//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
using UnityEngine.Rendering;
namespace easyar
{
    [RequireComponent(typeof(Camera))]
    public class CameraImageRenderer : MonoBehaviour
    {
        public enum RenderType
        {
            Normal,
            Eyewear
        }

        public enum GlassesDisplay
        {
            Normal,
            Left,
            Right
        }

        private CommandBuffer commandBuffer;
        private ARMaterial arMat;
        private Material mat;
        private Camera targetCamera;
        private RenderTexture targetTexture;

        public RenderType Type = RenderType.Normal;
        public GlassesDisplay Display = GlassesDisplay.Normal;

        public void SetRenderType(RenderType value)
        {
            if (value == RenderType.Eyewear)
            {
                targetCamera.RemoveAllCommandBuffers();
            }
            else
            {
                UpdateCommandBuffer();
            }
            Type = value;
        }

        public RenderTexture TargetTexture
        {
            get
            {
                var screen_w = Screen.width;
                var screen_h = Screen.height;
                var w = screen_w * targetCamera.rect.width;
                var h = screen_h * targetCamera.rect.height;
                if (targetTexture == null)
                {
                    targetTexture = new RenderTexture((int)w, (int)h, 0);
                }
                else
                {
                    if ((int)w != targetTexture.width || (int)h != targetTexture.height)
                    {
                        Destroy(targetTexture);
                        targetTexture = new RenderTexture((int)w, (int)h, 0);
                        UpdateCommandBuffer();
                    }
                }
                return targetTexture;
            }
        }

        private void UpdateCommandBuffer()
        {
            if (commandBuffer != null)
            {
                targetCamera.RemoveAllCommandBuffers();
                commandBuffer.Dispose();
                commandBuffer = new CommandBuffer();
                commandBuffer.Blit(null, BuiltinRenderTextureType.CameraTarget, mat);
                if (TargetTexture != null)
                {
                    commandBuffer.Blit(BuiltinRenderTextureType.CameraTarget, TargetTexture);
                }
                targetCamera.AddCommandBuffer(CameraEvent.BeforeForwardOpaque, commandBuffer);
            }
        }

        private void Awake()
        {
            targetCamera = GetComponent<Camera>();
            arMat = new ARMaterial();
        }


        private void UpdateRender(easyar.Image image)
        {
            if (image == null)
            {
                return;
            }
            var updateMat = arMat.UpdateByImage(image);
            if (mat == updateMat)
            {
                return;
            }
            mat = updateMat;
            if (commandBuffer != null)
            {
                targetCamera.RemoveCommandBuffer(CameraEvent.BeforeForwardOpaque, commandBuffer);
                commandBuffer.Dispose();
                commandBuffer = null;
            }
            commandBuffer = new CommandBuffer();
            commandBuffer.Blit(null, BuiltinRenderTextureType.CameraTarget, mat);
            if (TargetTexture != null)
            {
                commandBuffer.Blit(BuiltinRenderTextureType.CameraTarget, TargetTexture);
            }
            if (Type == RenderType.Normal)
                targetCamera.AddCommandBuffer(CameraEvent.BeforeForwardOpaque, commandBuffer);
        }

        public void UpdateFrame(ARSessionUpdateEventArgs e)
        {
            var frame = e.IFrame;
            var image = frame.image();
            if (image != null)
            {
                var img = image;
                UpdateRender(img);

                var screenRotation = Utility.GetScreenRotation();
                var viewport_aspect_ratio = targetCamera.aspect;
                var projection = Utility.Matrix44FToMatrix4x4(e.CameraParam.projection(targetCamera.nearClipPlane, targetCamera.farClipPlane, viewport_aspect_ratio, screenRotation, true, false));

                var imageProjection = Utility.Matrix44FToMatrix4x4(e.CameraParam.imageProjection(viewport_aspect_ratio, screenRotation, true, false));
                targetCamera.projectionMatrix = projection * e.ImageRotationMatrixGlobal.inverse;

                mat.SetMatrix("_TextureRotation", imageProjection);
                img.Dispose();
            }
            else
            {
                Debug.Log("[EasyAR] image is null");
            }
        }

        private void OnDestroy()
        {
            if (commandBuffer != null)
            {
                targetCamera.RemoveCommandBuffer(CameraEvent.BeforeForwardOpaque, commandBuffer);
                commandBuffer.Dispose();
            }
            arMat.Dispose();
            Destroy(targetTexture);
        }
    }
}
