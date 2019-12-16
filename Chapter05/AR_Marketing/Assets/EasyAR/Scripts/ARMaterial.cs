//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
using System;
namespace easyar
{
    public class ARMaterial
    {
        private Material mat;
        private PixelFormat format = PixelFormat.Unknown;
        private int imageWidth = 0;
        private int imageHeight = 0;

        private Texture2D yTexture;
        private Texture2D uTexture;
        private Texture2D vTexture;
        private Texture2D uvTexture;
        private Texture2D rgbTexture;
        private Texture2D bgrTexture;
        private Texture2D grayTexture;

        public Material UpdateByImage(Image image)
        {
            var updateTextureOnly = false;
            if (image.width() != imageWidth || image.height() != imageHeight || image.format() != format)
            {
                Dispose();
                imageWidth = image.width();
                imageHeight = image.height();
                format = image.format();
                updateTextureOnly = false;
            }
            else
            {
                updateTextureOnly = true;
            }
            var buffer = image.buffer();
            var ptr = buffer.data();
            var resolution = imageWidth * imageHeight;
            switch (format)
            {
                case PixelFormat.Unknown:
                    break;
                case PixelFormat.Gray:
                    if (!updateTextureOnly)
                    {
                        grayTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.Alpha8, false);
                        mat = new Material(ARShader.Instance.GRAY);
                        mat.SetTexture("_grayTexture", grayTexture);
                    }
                    grayTexture.LoadRawTextureData(ptr, resolution);
                    grayTexture.Apply();
                    break;
                case PixelFormat.YUV_NV21:
                    if (!updateTextureOnly)
                    {
                        yTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.Alpha8, false);
                        uvTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.RGBA4444, false);
                        mat = new Material(ARShader.Instance.YUV_NV21);
                        mat.SetTexture("_yTexture", yTexture);
                        mat.SetTexture("_uvTexture", uvTexture);
                    }
                    yTexture.LoadRawTextureData(ptr, resolution);
                    yTexture.Apply();
                    uvTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution), resolution);
                    uvTexture.Apply();

                    break;
                case PixelFormat.YUV_NV12:
                    if (!updateTextureOnly)
                    {
                        yTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.Alpha8, false);
                        uvTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.RGBA4444, false);
                        mat = new Material(ARShader.Instance.YUV_NV12);
                        mat.SetTexture("_yTexture", yTexture);
                        mat.SetTexture("_uvTexture", uvTexture);
                    }
                    yTexture.LoadRawTextureData(ptr, resolution);
                    yTexture.Apply();
                    uvTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution), resolution);
                    uvTexture.Apply();
                    break;
                case PixelFormat.YUV_I420:
                    if (!updateTextureOnly)
                    {
                        yTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.Alpha8, false);
                        uTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.Alpha8, false);
                        vTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.Alpha8, false);
                        mat = new Material(ARShader.Instance.YUV_I420_YV12);
                        mat.SetTexture("_yTexture", yTexture);
                        mat.SetTexture("_uTexture", uTexture);
                        mat.SetTexture("_vTexture", vTexture);
                    }
                    yTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), resolution);
                    yTexture.Apply();
                    uTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution), resolution / 4);
                    uTexture.Apply();
                    vTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution + resolution / 4), resolution / 4);
                    vTexture.Apply();
                    break;
                case PixelFormat.YUV_YV12:
                    if (!updateTextureOnly)
                    {
                        yTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.Alpha8, false);
                        uTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.Alpha8, false);
                        vTexture = new Texture2D(imageWidth / 2, imageHeight / 2, TextureFormat.Alpha8, false);
                        mat = new Material(ARShader.Instance.YUV_I420_YV12);
                        mat.SetTexture("_yTexture", yTexture);
                        mat.SetTexture("_uTexture", uTexture);
                        mat.SetTexture("_vTexture", vTexture);
                    }
                    yTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), resolution);
                    yTexture.Apply();
                    vTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution), resolution / 4);
                    vTexture.Apply();
                    uTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64() + resolution + resolution / 4), resolution / 4);
                    uTexture.Apply();
                    break;
                case PixelFormat.RGB888:
                    if (!updateTextureOnly)
                    {
                        rgbTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.RGB24, false);
                        mat = new Material(Shader.Find("Unlit/Texture"));
                        mat.SetTexture("_MainTex", rgbTexture);
                    }
                    rgbTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), buffer.size());
                    rgbTexture.Apply();
                    break;
                case PixelFormat.BGR888:
                    if (!updateTextureOnly)
                    {
                        bgrTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.RGB24, false);
                        mat = new Material(ARShader.Instance.BGR);
                        mat.SetTexture("_MainTex", bgrTexture);
                    }
                    bgrTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), buffer.size());
                    bgrTexture.Apply();
                    break;
                case PixelFormat.RGBA8888:
                    if (!updateTextureOnly)
                    {
                        rgbTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.RGBA32, false);
                        mat = new Material(Shader.Find("Unlit/Texture"));
                        mat.SetTexture("_MainTex", rgbTexture);
                    }
                    rgbTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), buffer.size());
                    rgbTexture.Apply();
                    break;
                case PixelFormat.BGRA8888:
                    if (!updateTextureOnly)
                    {
                        bgrTexture = new Texture2D(imageWidth, imageHeight, TextureFormat.RGBA32, false);
                        mat = new Material(ARShader.Instance.BGR);
                        mat.SetTexture("_MainTex", bgrTexture);
                    }
                    bgrTexture.LoadRawTextureData(new IntPtr(ptr.ToInt64()), buffer.size());
                    bgrTexture.Apply();
                    break;
                default:
                    break;
            }
            buffer.Dispose();
            return mat;
        }

        public void Dispose()
        {
            if (mat != null)
            {
                UnityEngine.Object.Destroy(mat);
            }

            if (rgbTexture != null)
            {
                UnityEngine.Object.Destroy(rgbTexture);
            }

            if (uTexture != null)

            {
                UnityEngine.Object.Destroy(uTexture);
            }

            if (vTexture != null)
            {
                UnityEngine.Object.Destroy(vTexture);
            }

            if (uvTexture != null)
            {
                UnityEngine.Object.Destroy(uvTexture);
            }

            if (yTexture != null)
            {
                UnityEngine.Object.Destroy(yTexture);
            }
        }
    }
}