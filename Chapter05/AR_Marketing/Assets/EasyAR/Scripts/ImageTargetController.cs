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
using easyar;
using System.Runtime.InteropServices;
public class ImageTargetController : MonoBehaviour
{

    public enum TargetType
    {
        LocalImage,
        LocalTargetData,
        Cloud
    }

    [HideInInspector]
    public bool Tracked = false;
    public string TargetName = null;
    public string TargetPath = null;
    public float TargetSize = 1f;
    public PathType Type = PathType.StreamingAssets;
    public ImageTrackerBehaviour ImageTracker = null;

    private Target target = null;
    public TargetType targetType = TargetType.LocalImage;

    private bool xFlip = false;

    private Image targetImage;

    public Target Target()
    {
        return target;
    }
    public float TargetWidth
    {
        get
        {
            return transform.localScale.x;
        }
    }
    public float TargetHeight
    {
        get
        {
            return transform.localScale.y;
        }
    }

    public void SetTargetFromCloud(Target target)
    {
        this.target = target;
        targetType = TargetType.Cloud;
        var imageTarget = (target as ImageTarget);
        TargetSize = imageTarget.scale();
    }

    private void Start()
    {
        for (int i = 0; i < transform.childCount; i++)
        {
            transform.GetChild(i).gameObject.SetActive(false);
        }
        switch (targetType)
        {
            case TargetType.LocalImage:
            case TargetType.LocalTargetData:
                StartCoroutine(LoadImageTarget());
                break;
            case TargetType.Cloud:
                if (target != null)
                {
                    TargetName = target.name();
                }
                break;
        }
    }

    private IEnumerator LoadImageTarget()
    {
        var path = TargetPath;
        var type = Type;
        WWW www;
        if (type == PathType.Absolute)
        {
            path = Utility.AddFileHeader(path);
#if UNITY_ANDROID && !UNITY_EDITOR
            path = "file://" +  path;
#endif
        }
        else if (type == PathType.StreamingAssets)
        {
            path = Utility.AddFileHeader(Application.streamingAssetsPath + "/" + path);
        }
        Debug.Log("[EasyAR]:" + path);
        www = new WWW(path);
        while (!www.isDone)
        {
            yield return 0;
        }
        if (!string.IsNullOrEmpty(www.error))
        {
            Debug.LogError(www.error);
            www.Dispose();
            yield break;
        }
        var data = www.bytes;
        easyar.Buffer buffer = easyar.Buffer.create(data.Length);
        var ptr = buffer.data();
        Marshal.Copy(data, 0, ptr, data.Length);

        Optional<easyar.ImageTarget> op_target;
        if (targetType == TargetType.LocalImage)
        {
            var image = ImageHelper.decode(buffer);
            if (!image.OnSome)
            {
                throw new System.Exception("decode image file data failed");
            }

            var p = new ImageTargetParameters();
            p.setImage(image.Value);
            p.setName(TargetName);
            p.setScale(TargetSize);
            p.setUid("");
            p.setMeta("");
            op_target = ImageTarget.createFromParameters(p);

            if (!op_target.OnSome)
            {
                throw new System.Exception("create image target failed from image target parameters");
            }

            image.Value.Dispose();
            buffer.Dispose();
            p.Dispose();
        }
        else
        {
            op_target = ImageTarget.createFromTargetData(buffer);

            if (!op_target.OnSome)
            {
                throw new System.Exception("create image target failed from image target target data");
            }

            buffer.Dispose();
        }

        target = op_target.Value;
        Destroy(www.texture);
        www.Dispose();
        if (ImageTracker == null)
        {
            yield break;
        }
        ImageTracker.LoadImageTarget(this, (_target, status) =>
        {
            targetImage = ((_target as ImageTarget).images())[0];
            Debug.Log("[EasyAR] Targtet name: " + _target.name() + " target runtimeID: " + _target.runtimeID() + " load status: " + status);
            Debug.Log("[EasyAR] Target size" + targetImage.width() + " " + targetImage.height());
        });
    }

    private void Update()
    {
        if (target != null)
        {
            var target = this.target as ImageTarget;
        }
    }

    public void SetXFlip()
    {
        xFlip = !xFlip;
    }

    public void OnTracking(Matrix4x4 pose)
    {
        Debug.Log("[EasyAR] OnTracking targtet name: " + target.name());
        Utility.SetMatrixOnTransform(transform, pose);
        if (xFlip)
        {
            var scale = transform.localScale;
            scale.x = -scale.x;
            transform.localScale = scale;
        }

        transform.localScale = transform.localScale * TargetSize;
    }

    public void OnLost()
    {
        Debug.Log("[EasyAR] OnLost targtet name: " + target.name());
        gameObject.SetActive(false);
        for (int i = 0; i < transform.childCount; i++)
        {
            transform.GetChild(i).gameObject.SetActive(false);
        }
    }

    public void OnFound()
    {
        Debug.Log("[EasyAR] OnFound targtet name: " + target.name());
        gameObject.SetActive(true);
        for (int i = 0; i < transform.childCount; i++)
        {
            transform.GetChild(i).gameObject.SetActive(true);
        }
    }

    private void OnDestroy()
    {
        if (ImageTracker != null)
            ImageTracker.UnloadImageTarget(this, (target, status) => { Debug.Log("[EasyAR] Targtet name: " + target.name() + " Target runtimeID: " + target.runtimeID() + " load status: " + status); });
    }
}
