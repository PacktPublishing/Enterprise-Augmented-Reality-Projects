//=============================================================================================================================
//
// Copyright (c) 2015-2017 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace EasyAR
{
    public class ARBuilder
    {
        private static readonly ARBuilder instance = new ARBuilder();
        public List<CameraDeviceBaseBehaviour> CameraDeviceBehaviours = new List<CameraDeviceBaseBehaviour>();
        public List<ARCameraBaseBehaviour> ARCameraBehaviours = new List<ARCameraBaseBehaviour>();
        public List<ImageTrackerBaseBehaviour> ImageTrackerBehaviours = new List<ImageTrackerBaseBehaviour>();
        public List<ObjectTrackerBaseBehaviour> ObjectTrackerBehaviours = new List<ObjectTrackerBaseBehaviour>();
        public RecorderBaseBehaviour RecorderBehaviour;

        static ARBuilder()
        {
        }

        ARBuilder()
        {
        }

        public static ARBuilder Instance
        {
            get
            {
                return instance;
            }
        }

        public bool InitializeEasyAR(string key)
        {
            bool success;
#if UNITY_ANDROID && !UNITY_EDITOR
            using (var easyarClass = new AndroidJavaClass("cn.easyar.engine.EasyAR"))
            {
                easyarClass.CallStatic("loadLibraries");
            }
            using (var actClass = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
            {
                var playerActivityContext = actClass.GetStatic<AndroidJavaObject>("currentActivity");
                var activityclassloader = playerActivityContext.Call<AndroidJavaObject>("getClass").Call<AndroidJavaObject>("getClassLoader");
                success = Engine.Initialize(key, activityclassloader.GetRawObject(), playerActivityContext.GetRawObject());
            }
#else
            success = Engine.Initialize(key, IntPtr.Zero, IntPtr.Zero);
#endif
            if (!success)
            {
                Debug.LogError("Fail to initialize EasyAR!");
                return false;
            }
            return true;
        }

        public bool EasyBuild()
        {
            ARCameraBehaviours.Clear();
            CameraDeviceBehaviours.Clear();
            ImageTrackerBehaviours = GameObject.FindObjectsOfType<ImageTrackerBaseBehaviour>().ToList();
            ObjectTrackerBehaviours = GameObject.FindObjectsOfType<ObjectTrackerBaseBehaviour>().ToList();
            RecorderBehaviour = GameObject.FindObjectOfType<RecorderBaseBehaviour>();

            var arcamerabehaviour = GameObject.FindObjectOfType<ARCameraBaseBehaviour>();
            if (arcamerabehaviour == null)
            {
                Debug.LogError("ARBuilder: fail to build AR");
                return false;
            }
            ARCameraBehaviours.Add(arcamerabehaviour);

            var cambehaviour = GameObject.FindObjectOfType<CameraDeviceBaseBehaviour>();
            if (cambehaviour == null)
            {
                Debug.LogError("ARBuilder: fail to build AR");
                return false;
            }
            CameraDeviceBehaviours.Add(cambehaviour);

            foreach (var behaviour in GameObject.FindObjectsOfType<DeviceUserAbstractBehaviour>())
            {
                behaviour.Bind(cambehaviour);
                Debug.Log("ARBuilder: " + behaviour + " bind " + cambehaviour);
            }
            foreach (var behaviour in ARCameraBehaviours)
            {
                behaviour.Bind(cambehaviour);
            }
            return true;
        }

        public void Start()
        {
            foreach (var behaviour in CameraDeviceBehaviours)
            {
                behaviour.OpenAndStart();
            }
        }
    }
}
