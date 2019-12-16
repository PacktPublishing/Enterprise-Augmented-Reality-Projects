//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
using System.Collections.Generic;
using System;
namespace easyar
{
    public class SurfaceTrackerBehaviour : MonoBehaviour
    {
        private SurfaceTracker tracker;
        public SurfaceTargetController Target = null;
        public bool PickSwitch = true;

        private class TouchInfo
        {
            public Vector2 position;
            public TouchPhase phase;
        }

        private List<TouchInfo> touchInfoList = new List<TouchInfo>();


        void Awake()
        {
            if (!SurfaceTracker.isAvailable())
            {
                throw new Exception("surface tracker not support");
            }
            tracker = SurfaceTracker.create();
        }

        public InputFrameSink Input()
        {
            if (tracker == null)
            {
                throw new Exception("surface tracker is null");
            }
            return tracker.inputFrameSink();
        }

        public OutputFrameSource Output()
        {
            if (tracker == null)
            {
                throw new Exception("surface tracker is null");
            }
            return tracker.outputFrameSource();
        }

        public void StartTracker()
        {
            if (tracker == null)
            {
                throw new Exception("surface tracker is null");
            }
            tracker.start();
        }

        public void StopTracker()
        {
            if (tracker == null)
            {
                throw new Exception("surface tracker is null");
            }
            tracker.stop();
        }

        public void CloseTracker()
        {
            if (tracker == null)
            {
                throw new Exception("surface tracker is null");
            }
            tracker.close();
            tracker.Dispose();
            tracker = null;
        }

        private void OnEnable()
        {
            if(tracker != null)
                tracker.start();
        }

        public void UpdateFrame(ARSessionUpdateEventArgs args)
        {
            var frame = args.OFrame;
            var results = args.OFrame.results();
            foreach (var _result in results)
            {
                SurfaceTrackerResult result = null;
                if (_result.OnSome)
                {
                    result = _result.Value as SurfaceTrackerResult;
                }
                if (result != null && Target != null)
                {
                    if (result.status() != SurfaceTrackingStatus.NotTracking)
                    {
                        if (!Target.Tracked)
                        {
                            Target.OnFound();
                            Target.Tracked = true;
                        }
                        var easyarTransform = result.transform();
                        var unityTransform = Utility.Matrix44FToMatrix4x4(easyarTransform);
                        unityTransform = unityTransform * args.ImageRotationMatrixGlobal.inverse;
                        Target.OnTracking(unityTransform);
                    }
                    else
                    {
                        Target.OnLost();
                        Target.Tracked = false;
                    }

                    result.Dispose();
                }
            }

            if (!PickSwitch)
            {
                return;
            }
            var cameraParams = args.CameraParam;
            if (cameraParams != null && Target != null && UnityEngine.Input.touchCount > 0)
            {
                var touch = UnityEngine.Input.GetTouch(0);
                if (touch.phase == TouchPhase.Began)
                {
                    TouchInfo info = new TouchInfo();
                    info.position = touch.position;
                    touchInfoList.Add(info);
                }
                else if (touch.phase == TouchPhase.Ended)
                {
                    var distance = touchInfoList[0].position - touch.position;
                    touchInfoList.Clear();
                    if (distance.magnitude > 0.1)
                    {
                        return;
                    }
                    var position = touch.position;
                    var position_normalize = new Vector2(position.x / Screen.width, 1 - position.y / Screen.height);
                    var aspectRatio = Target.TargetCamera.aspect;
                    var screenRotation = Utility.GetScreenRotation();
                    var imageCoordinates = cameraParams.imageCoordinatesFromScreenCoordinates(
                        aspectRatio, screenRotation, true, false, new Vec2F(position_normalize.x, position_normalize.y));
                    tracker.alignTargetToCameraImagePoint(imageCoordinates);
                }
            }
        }

        private void OnDisable()
        {
            if (tracker != null)
                tracker.stop();
        }

        public void OnDestroy()
        {
            if (tracker != null)
            {
                tracker.Dispose();
            }
        }
    }
}