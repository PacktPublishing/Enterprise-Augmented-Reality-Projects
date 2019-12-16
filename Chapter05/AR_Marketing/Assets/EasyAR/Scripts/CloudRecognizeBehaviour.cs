//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using System.Collections.Generic;
using UnityEngine;
using System;
namespace easyar
{
    public class CloudRecognizeBehaviour : MonoBehaviour
    {
        //cloud only support image target now
        public ImageTrackerBehaviour Tracker;
        public string CloudServer = "--YOUR CLOUD CLIENT END URL HERE--";
        public string CloudKey = "--YOUR CLOUD KEY HERE--";
        public string CloudSecret = "--YOUR CLOUD SECRET HERE--";

        private CloudRecognizer cloudRecognizer;
        private List<string> loadedCloudTargetUids;
        private List<GameObject> targetObjs;
        public InputFrameSink Input()
        {
            if (cloudRecognizer == null)
            {
                throw new Exception("cloudRecognizer is null");
            }
            return cloudRecognizer.inputFrameSink();
        }

        void Awake()
        {
            loadedCloudTargetUids = new List<string>();
            targetObjs = new List<GameObject>();
            Open();
        }

        private void OnEnable()
        {
            if (CloudStart())
            {
                Debug.Log("[EasyAR] Cloud Start");
            }
        }

        private void Open()
        {
            cloudRecognizer = CloudRecognizer.create(
            CloudServer,
            CloudKey,
            CloudSecret,
            EasyARBehaviour.Scheduler,
            (System.Action<CloudStatus, List<Target>>)((CloudStatus status, List<Target> targets) =>
            {
                Debug.Log("[EasyAR] Cloud status " + status + " target number " + targets.Count);
                if (targets != null)
                {
                    foreach (var target in targets)
                    {
                        if (target == null)
                        {
                            continue;
                        }
                        var uid = target.uid();
                        if (!loadedCloudTargetUids.Contains(uid))
                        {
                            loadedCloudTargetUids.Add(target.uid());
                            var go = new GameObject(target.uid());
                            targetObjs.Add(go);
                            var targetController = go.AddComponent<ImageTargetController>();
                            targetController.SetTargetFromCloud(target.Clone());
                            targetController.ImageTracker = Tracker;
                            var cube = Instantiate(Resources.Load("HelloAR_ImageTarget_Cloud/prefabs/cube", typeof(GameObject)) as GameObject);
                            cube.transform.parent = go.transform;
                            Tracker.LoadImageTarget(targetController, (_target, result) =>
                            {
                                Debug.Log("[EasyAR] Target runtimeID: " + _target.runtimeID() + " result: " + result);
                            });
                        }
                    }
                }
            }));
        }

        public bool CloudStart()
        {
            if (cloudRecognizer != null)
            {
                return cloudRecognizer.start();
            }
            return false;
        }

        public void CloudStop()
        {
            if (cloudRecognizer != null)
            {
                cloudRecognizer.stop();
            }
        }

        public void CloudClose()
        {
            if (cloudRecognizer != null)
            {
                cloudRecognizer.close();
            }
        }

        public void Dispose()
        {
            if (cloudRecognizer != null)
            {
                cloudRecognizer.Dispose();
            }
            foreach (var obj in targetObjs)
            {
                Destroy(obj);
            }
        }

        private void OnDisable()
        {
            CloudStop();
        }

        private void Destroy()
        {
            Dispose();
        }
    }
}
