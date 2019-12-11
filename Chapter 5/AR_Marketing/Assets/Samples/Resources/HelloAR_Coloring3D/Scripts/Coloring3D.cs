//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
using easyar;
public class Coloring3D : MonoBehaviour
{
    public Camera Camera = null;

    public ImageTargetController ImageTarget = null;

    public RenderTexture renderTexture = null;

    private Texture2D staticTexture = null;

    private Material material = null;

    private bool useStaticTex = false;
    private void Start()
    {
        var renderer = GetComponent<MeshRenderer>();
        if (renderer != null)
        {
            material = renderer.material;
        }
    }

    private void Update()
    {
        if (useStaticTex)
        {
            return;
        }
        var halfWidth = ImageTarget.TargetWidth * 0.5f;
        var halfHeight = ImageTarget.TargetHeight * 0.5f;
        Vector3 targetAnglePoint1 = ImageTarget.transform.TransformPoint(new Vector3(-halfWidth, halfHeight, 0));
        Vector3 targetAnglePoint2 = ImageTarget.transform.TransformPoint(new Vector3(-halfWidth, -halfHeight, 0));
        Vector3 targetAnglePoint3 = ImageTarget.transform.TransformPoint(new Vector3(halfWidth, halfHeight, 0));
        Vector3 targetAnglePoint4 = ImageTarget.transform.TransformPoint(new Vector3(halfWidth, -halfHeight, 0));
        material.SetVector("_Uvpoint1", new Vector4(targetAnglePoint1.x, targetAnglePoint1.y, targetAnglePoint1.z, 1f));
        material.SetVector("_Uvpoint2", new Vector4(targetAnglePoint2.x, targetAnglePoint2.y, targetAnglePoint2.z, 1f));
        material.SetVector("_Uvpoint3", new Vector4(targetAnglePoint3.x, targetAnglePoint3.y, targetAnglePoint3.z, 1f));
        material.SetVector("_Uvpoint4", new Vector4(targetAnglePoint4.x, targetAnglePoint4.y, targetAnglePoint4.z, 1f));
        if (Camera != null)
        {
            var cameraRender = Camera.GetComponent<CameraImageRenderer>();
            if (cameraRender != null)
            {
                renderTexture = cameraRender.TargetTexture;
            }
        }
        material.SetTexture("_MainTex", renderTexture);
    }

    public Texture2D getBackgroundPic()
    {
        RenderTexture.active = renderTexture;
        var tempTexture = new Texture2D(renderTexture.width, renderTexture.height, TextureFormat.RGB24, false);
        tempTexture.ReadPixels(new Rect(0, 0, renderTexture.width, renderTexture.height), 0, 0);
        RenderTexture.active = null;
        tempTexture.Apply();
        return tempTexture;
    }

    public void SetStaticPic()
    {
        Destroy(staticTexture);
        useStaticTex = true;
        RenderTexture.active = renderTexture;
        staticTexture = new Texture2D(renderTexture.width, renderTexture.height, TextureFormat.RGB24, false);
        staticTexture.ReadPixels(new Rect(0, 0, renderTexture.width, renderTexture.height), 0, 0);
        RenderTexture.active = null;
        staticTexture.Apply();
        material.SetTexture("_MainTex", staticTexture);
    }

    public void SetDynamicPic()
    {
        Destroy(staticTexture);
        useStaticTex = false;
    }
}
