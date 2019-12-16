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
    [CreateAssetMenu()]
    public class EasyARSettings : ScriptableObject
    {
        [SerializeField]
        [TextArea(1, 10)]
        public string EasyARKey;
    }
}
