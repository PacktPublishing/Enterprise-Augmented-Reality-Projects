//=============================================================================================================================
//
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================
using UnityEngine;
using System.Collections;
using System.IO;
using System.Collections.Generic;
using System;

namespace Sample
{
    public class FilesManager : MonoBehaviour
    {
        private string MarksDirectory;
        private bool isWriting;
        private TargetOnTheFly ui;
        void Awake()
        {
            ui = FindObjectOfType<TargetOnTheFly>();
#if UNITY_ANDROID && !UNITY_EDITOR
            using (var unityPlayerClass = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
            using (var currentActivity = unityPlayerClass.GetStatic<AndroidJavaObject>("currentActivity"))
            using (var file = currentActivity.Call<AndroidJavaObject>("getFilesDir"))
            {
                MarksDirectory = file.Call<string>("getAbsolutePath");
            }
#else
            MarksDirectory = Application.persistentDataPath;
#endif
            Debug.Log("MarkPath:" + MarksDirectory);
            Debug.Log("MarkPath:" + Application.persistentDataPath);
        }

        public void StartTakePhoto()
        {
            if (!Directory.Exists(MarksDirectory))
                Directory.CreateDirectory(MarksDirectory);
            if (!isWriting)
                StartCoroutine(ImageCreate());
        }

        IEnumerator ImageCreate()
        {
            isWriting = true;
            yield return new WaitForEndOfFrame();

            Texture2D photo = new Texture2D(Screen.width / 2, Screen.height / 2, TextureFormat.RGB24, false);
            photo.ReadPixels(new Rect(Screen.width / 4, Screen.height / 4, Screen.width / 2, Screen.height / 2), 0, 0, false);
            photo.Apply();

            byte[] data = photo.EncodeToJPG(80);
            DestroyImmediate(photo);
            photo = null;

            string photoPath = Path.Combine(MarksDirectory, "photo" + DateTime.Now.Ticks + ".jpg");
            File.WriteAllBytes(photoPath, data);
            FileStream file = File.Open(photoPath, FileMode.Create);
            file.BeginWrite(data, 0, data.Length, new AsyncCallback(endWriter), file);
        }

        void endWriter(IAsyncResult end)
        {
            using (FileStream file = (FileStream)end.AsyncState)
            {
                file.EndWrite(end);
                isWriting = false;
                ui.StartShowMessage = true;
            }
        }

        public Dictionary<string, string> GetDirectoryName_FileDic()
        {
            if (!Directory.Exists(MarksDirectory))
                return new Dictionary<string, string>();
            return GetAllImagesFiles(MarksDirectory);
        }

        private Dictionary<string, string> GetAllImagesFiles(string path)
        {
            Dictionary<string, string> imagefilesDic = new Dictionary<string, string>();
            foreach (var file in Directory.GetFiles(path))
            {
                if (Path.GetExtension(file) == ".jpg" || Path.GetExtension(file) == ".bmp" || Path.GetExtension(file) == ".png")
                    imagefilesDic.Add(Path.GetFileNameWithoutExtension(file), file);
            }
            return imagefilesDic;
        }

        public void ClearTexture()
        {
            Dictionary<string, string> imageFileDic = GetAllImagesFiles(MarksDirectory);
            foreach (var path in imageFileDic)
                File.Delete(path.Value);
        }
    }
}
