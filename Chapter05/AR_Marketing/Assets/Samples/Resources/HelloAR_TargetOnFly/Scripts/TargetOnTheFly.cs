//=============================================================================================================================
//
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================
using UnityEngine;
using System.Collections;

namespace Sample
{
    public class TargetOnTheFly : MonoBehaviour
    {
        [HideInInspector]
        public bool StartShowMessage = false;
        private bool isShowing = false;
        private ImageTargetManager imageManager;
        private FilesManager imageCreator;

        public GUISkin skin;
        private void Start()
        {
            imageManager = FindObjectOfType<ImageTargetManager>();
            imageCreator = FindObjectOfType<FilesManager>();
        }

        void OnGUI()
        {
            if (StartShowMessage)
            {
                if (!isShowing)
                    StartCoroutine(ShowMessageAndLoadTarget());
                StartShowMessage = false;
            }

            GUI.Box(new Rect(Screen.width / 2 - 250, 30, 500, 60), "The box area will be used as ImageTarget. Take photo!", skin.GetStyle("Button"));
            GUI.Box(new Rect(Screen.width / 4, Screen.height / 4, Screen.width / 2, Screen.height / 2), "", skin.GetStyle("Button"));

            if (isShowing)
                GUI.Box(new Rect(Screen.width / 2 - 65, Screen.height / 2, 130, 60), "Photo Saved", skin.GetStyle("Button"));


            if (GUI.Button(new Rect(Screen.width / 2 - 80, Screen.height - 85, 160, 80), "Take Photo", skin.GetStyle("Button")))
                imageCreator.StartTakePhoto();

            if (GUI.Button(new Rect(Screen.width - 160, Screen.height - 85, 150, 80), "Clear Targets", skin.GetStyle("Button")))
            {
                imageCreator.ClearTexture();
                imageManager.ClearAllTarget();
            }
        }

        IEnumerator ShowMessageAndLoadTarget()
        {
            isShowing = true;
            yield return new WaitForSeconds(2f);
            isShowing = false;
            imageManager.LoadTarget();
        }
    }
}
