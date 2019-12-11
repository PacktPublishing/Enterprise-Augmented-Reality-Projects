//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
namespace easyar
{
    public class SurfaceTargetController : MonoBehaviour
    {
        public Camera TargetCamera;
        public bool Tracked;
        public void OnFound()
        {
        }

        public void OnLost()
        {
        }

        public void OnTracking(Matrix4x4 pose)
        {
            Utility.SetMatrixOnTransform(TargetCamera.transform, pose);
        }
    }
}
