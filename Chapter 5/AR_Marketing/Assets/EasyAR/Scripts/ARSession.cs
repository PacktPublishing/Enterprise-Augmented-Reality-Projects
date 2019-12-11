//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using System;
using UnityEngine;

namespace easyar
{
    public class ARSessionUpdateEventArgs : EventArgs
    {
        public InputFrame IFrame = null;
        public OutputFrame OFrame = null;
        public Matrix4x4 ImageRotationMatrixGlobal = Matrix4x4.identity;
        public CameraParameters CameraParam = null;
        public float screenRotation;
    }

    public class ARSession : MonoBehaviour
    {
        public enum FrameSource
        {
            easyar
        }

        CameraDevice easyarCamera;

        InputFrameThrottler iFrameThrottler;
        OutputFrameJoin oFrameJoin;
        OutputFrameBuffer oFrameBuffer;

        InputFrameToOutputFrameAdapter i2OAdapter;
        InputFrameFork inputFrameFork;
        OutputFrameFork outputFrameFork;
        InputFrameToFeedbackFrameAdapter i2fAdapter;
        FeedbackFrameFork feedbackFork;

        ARSessionUpdateEventArgs args;

        int frameIndex = -1;

        bool initialized = false;

        public CameraDevicePreference EasyarCameraPrefer = CameraDevicePreference.PreferObjectSensing;

        public CameraDeviceFocusMode CameraFocusMode = CameraDeviceFocusMode.Continousauto;

        public Vector2 CameraSize = new Vector2(1280, 720);

        public FrameSource FrameSourceType;

        public bool UseSecondCamera = false;

        public int ForkOutputNum = 0;

        public int JoinNum = 0;

        public ImageTrackerBehaviour ImgTracker;

        public SurfaceTrackerBehaviour SfTracker;

        public CloudRecognizeBehaviour CloudImageRecognizer;

        public CameraImageRenderer CameraBackgroundRenderer;

        private void Awake()
        {
            easyar.CameraDevice.requestPermissions(EasyARBehaviour.Scheduler, (System.Action<PermissionStatus, string>)((status, msg) =>
            {
                if (status == PermissionStatus.Granted)
                {
                    Init();
                }
                Debug.Log("[EasyAR] RequestPermissions status " + status + " msg " + msg);
            }));
        }

        void Init()
        {
            initialized = true;

            iFrameThrottler = InputFrameThrottler.create();
            oFrameBuffer = OutputFrameBuffer.create();
            i2fAdapter = InputFrameToFeedbackFrameAdapter.create();
            inputFrameFork = InputFrameFork.create(ForkOutputNum);
            i2OAdapter = InputFrameToOutputFrameAdapter.create();
            oFrameJoin = OutputFrameJoin.create(JoinNum);

            if (FrameSourceType == FrameSource.easyar)
            {
                if (CameraDevice.isAvailable())
                {
                    Debug.Log("[EasyAR] use ezar camera device");
                    easyarCamera = CameraDeviceSelector.createCameraDevice(EasyarCameraPrefer);
                    var openResult = false;
                    if(UseSecondCamera)
                    {
                        openResult = easyarCamera.openWithIndex(1);
                    }
                    else
                    {
                        openResult = easyarCamera.openWithType(CameraDeviceType.Default);
                    }
                    easyarCamera.setFocusMode(CameraFocusMode);

                    if (!openResult)
                    {
                        Debug.Log("[EasyAR] open camera failed");
                        initialized = false;
                        return;
                    }
                    easyarCamera.setSize(new Vec2I((int)CameraSize.x, (int)CameraSize.y));
                    easyarCamera.inputFrameSource().connect(iFrameThrottler.input());
                    easyarCamera.start();
                }
                else
                {
                    initialized = false;
                    Debug.Log("[EasyAR] ezar camera device can not work");
                    return;
                }
            }

            iFrameThrottler.output().connect(inputFrameFork.input());
            inputFrameFork.output(0).connect(i2OAdapter.input());
            i2OAdapter.output().connect(oFrameJoin.input(0));
            outputFrameFork = OutputFrameFork.create(1);

            int index = 0;
            if (ImgTracker != null)
            {
                index++;
                outputFrameFork = OutputFrameFork.create(2);
                inputFrameFork.output(index).connect(i2fAdapter.input());
                i2fAdapter.output().connect(ImgTracker.Input());
                ImgTracker.Output().connect(oFrameJoin.input(index));
                outputFrameFork.output(1).connect(i2fAdapter.sideInput());
            }

            if (SfTracker != null)
            {
                index++;
                inputFrameFork.output(index).connect(SfTracker.Input());
                SfTracker.Output().connect(oFrameJoin.input(index));
            }

            if (CloudImageRecognizer != null)
            {
                index++;
                inputFrameFork.output(index).connect(CloudImageRecognizer.Input());
            }

            oFrameJoin.output().connect(outputFrameFork.input());
            outputFrameFork.output(0).connect(oFrameBuffer.input());
            oFrameBuffer.signalOutput().connect(iFrameThrottler.signalInput());

            args = new ARSessionUpdateEventArgs();
        }

        private void Update()
        {
            if (!initialized)
            {
                return;
            }

            var oFrame = oFrameBuffer.peek();
            if (!oFrame.OnSome) { Debug.Log("[EasyAR] oframe is null"); return; }
            var iFrame = oFrame.Value.inputFrame();
            if (iFrame == null) { oFrame.Value.Dispose(); Debug.Log("[EasyAR] iFrame is null"); return; }

            var index = iFrame.index();
            if (frameIndex == index)
            {
                oFrame.Value.Dispose();
                iFrame.Dispose();
                return;
            }
            frameIndex = index;

            var camParams = iFrame.cameraParameters();
            if (camParams == null) { Debug.Log("[EasyAR] camParams is null"); return; }

            var screenRotation = Utility.GetScreenRotation();
            var imageRotationDegree = camParams.imageOrientation(screenRotation);
            var imageRotation = (float)(imageRotationDegree) / 180.0f * Mathf.PI;
            Matrix4x4 rotationMatrixGlobal = Matrix4x4.identity;
            rotationMatrixGlobal.m00 = Mathf.Cos(-imageRotation);
            rotationMatrixGlobal.m01 = -Mathf.Sin(-imageRotation);
            rotationMatrixGlobal.m10 = Mathf.Sin(-imageRotation);
            rotationMatrixGlobal.m11 = Mathf.Cos(-imageRotation);
            args.ImageRotationMatrixGlobal = rotationMatrixGlobal;
            args.IFrame = iFrame;
            args.OFrame = oFrame.Value;
            args.CameraParam = camParams;

            if (ImgTracker != null)
                ImgTracker.UpdateFrame(args);

            if (SfTracker != null)
                SfTracker.UpdateFrame(args);

            if (CameraBackgroundRenderer != null)
                CameraBackgroundRenderer.UpdateFrame(args);

            oFrame.Value.Dispose();
            iFrame.Dispose();
            camParams.Dispose();
        }

        public void SwitchCamera()
        {
            if (easyarCamera == null)
            {
                Debug.Log("only support easyar camera");
                return;
            }
            CameraDeviceType type = easyarCamera.type();
            if (type == CameraDeviceType.Front)
            {
                OpenCamera(true);
            }
            else
            {
                OpenCamera(false);
            }
        }

        public void OpenCamera(bool isBack)
        {
            if (easyarCamera == null)
            {
                return;
            }
            easyarCamera.close();
            easyarCamera.Dispose();
            easyarCamera = CameraDeviceSelector.createCameraDevice(CameraDevicePreference.PreferObjectSensing);
            easyarCamera.setFocusMode(CameraFocusMode);
            bool openResult = false;
            if (isBack)
            {
                openResult = easyarCamera.openWithType(CameraDeviceType.Back);
                Debug.Log("[EasyAR] open camera back result " + openResult);
                if (openResult)
                    GL.invertCulling = false;
            }
            else
            {
                openResult = easyarCamera.openWithType(CameraDeviceType.Front);
                Debug.Log("[EasyAR] open camera front result " + openResult);
                if (openResult)
                    GL.invertCulling = true;
            }

            easyarCamera.setSize(new Vec2I((int)CameraSize.x, (int)CameraSize.y));
            easyarCamera.start();
            easyarCamera.inputFrameSource().connect(iFrameThrottler.input());
        }
    }
}
