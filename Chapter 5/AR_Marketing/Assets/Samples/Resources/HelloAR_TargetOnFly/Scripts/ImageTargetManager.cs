//=============================================================================================================================
//
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================
using UnityEngine;
using System.Collections.Generic;
using System.Linq;
using easyar;

namespace Sample
{
    public class ImageTargetManager : MonoBehaviour
    {
        private Dictionary<string, ImageTargetController> imageTargetDic = new Dictionary<string, ImageTargetController>();
        public FilesManager pathManager;
        public ImageTrackerBehaviour Tracker;
        void Start()
        {
            if (!pathManager)
                pathManager = FindObjectOfType<FilesManager>();
            LoadTarget();
        }

        public void LoadTarget()
        {
            var imageTargetName_FileDic = pathManager.GetDirectoryName_FileDic();
            foreach (var obj in imageTargetName_FileDic.Where(obj => !imageTargetDic.ContainsKey(obj.Key)))
            {
                GameObject imageTarget = new GameObject(obj.Key);
                var behaviour = imageTarget.AddComponent<ImageTargetController>();
                behaviour.TargetName = obj.Key;
                behaviour.TargetPath = obj.Value.Replace(@"\", "/");
                behaviour.Type = PathType.Absolute;
                behaviour.ImageTracker = Tracker;
                imageTargetDic.Add(obj.Key, behaviour);
                var cube = Instantiate(Resources.Load("HelloAR_TargetOnFly/Prefabs/Cube")) as GameObject;
                cube.transform.parent = imageTarget.transform;
            }
        }

        public void ClearAllTarget()
        {
            
            foreach (var obj in imageTargetDic)
                Destroy(obj.Value.gameObject);
            imageTargetDic = new Dictionary<string, ImageTargetController>();
        }
    }
}
