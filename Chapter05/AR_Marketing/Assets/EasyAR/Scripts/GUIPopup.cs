//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
namespace easyar
{
    public class GUIPopup : MonoBehaviour {
        private List<string> messageList;
        private List<float> timeList;
        private bool isShowing = false;
        private bool isBegin = false;
        private static GUIPopup popup;

        private GUISkin Skin;

        private void Start()
        {
            Skin = Resources.Load<GUISkin>("GUISkin/GUISkin");
            StartCoroutine(showMessage());
        }

        public static void AddShowMessage(string message, float seconds)
        {
            if (popup == null)
            {
                var go = new GameObject("popuper");
                popup = go.AddComponent<GUIPopup>();
                popup.messageList = new List<string>();
                popup.timeList = new List<float>();
            }
            if (popup.messageList.Count > 5)
            {
                popup.messageList.RemoveAt(0);
                popup.timeList.RemoveAt(0);
            }
            popup.messageList.Add(message);
            popup.timeList.Add(seconds);
        }

        private IEnumerator showMessage()
        {
            while (true)
            {
                if (messageList.Count > 0)
                {
                    isShowing = true;
                    isBegin = true;
                    if (Skin != null)
                    {
                        var color = Skin.GetStyle("box").normal.textColor;
                        color.a = 0;
                        Skin.GetStyle("box").normal.textColor = color;
                    }
                    var halftime = timeList[0] / 2;
                    if (halftime > 2)
                    {
                        yield return new WaitForSeconds(1);
                        yield return new WaitForSeconds(timeList[0] - 2);
                        isBegin = false;
                        yield return new WaitForSeconds(1);
                    }
                    else
                    {
                        yield return new WaitForSeconds(halftime);
                        isBegin = false;
                        yield return new WaitForSeconds(halftime);
                    }

                    if (Skin != null)
                    {
                        var color = Skin.GetStyle("box").normal.textColor;
                        color.a = 1;
                        Skin.GetStyle("box").normal.textColor = color;
                    }

                    timeList.RemoveAt(0);
                    messageList.RemoveAt(0);
                }
                else
                {
                    isShowing = false;
                    yield return 0;
                }
            }
        }

        private void OnGUI()
        {
            if (isShowing && Skin != null)
            {
                if (isBegin)
                {
                    var color = Skin.GetStyle("box").normal.textColor;
                    if (color.a <= 1)
                    {
                        color.a += Time.deltaTime * 2;
                    }
                    else
                    {
                        color.a = 1f;
                    }
                    Skin.GetStyle("box").normal.textColor = color;
                }
                else
                {
                    var color = Skin.GetStyle("box").normal.textColor;
                    if (color.a >= 0)
                    {
                        color.a -= Time.deltaTime * 2;
                    }
                    else
                    {
                        color.a = 0f;
                    }
                    Skin.GetStyle("box").normal.textColor = color;
                }
                GUI.Box(new Rect(0, Screen.height / 2, Screen.width, 160), messageList[0], Skin.GetStyle("box"));
            }
        }
    }
}
