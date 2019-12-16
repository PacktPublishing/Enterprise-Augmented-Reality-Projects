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
    public class ARShader : MonoBehaviour
    {
        private static ARShader instance;
        public static ARShader Instance
        {
            get { return instance; }
        }

        public Shader BGR = null;
        public Shader GRAY = null;
        public Shader YUV_I420_YV12 = null;
        public Shader YUV_NV12 = null;
        public Shader YUV_NV21 = null;

        private void Awake()
        {
            instance = this;
        }
    }
}

