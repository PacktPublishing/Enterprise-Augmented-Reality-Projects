//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CAMERAPARAMETERS_H__
#define __EASYAR_CAMERAPARAMETERS_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_CameraParameters__ctor(easyar_Vec2I size, easyar_Vec2F focalLength, easyar_Vec2F principalPoint, easyar_CameraDeviceType cameraDeviceType, int cameraOrientation, /* OUT */ easyar_CameraParameters * * Return);
easyar_Vec2I easyar_CameraParameters_size(const easyar_CameraParameters * This);
easyar_Vec2F easyar_CameraParameters_focalLength(const easyar_CameraParameters * This);
easyar_Vec2F easyar_CameraParameters_principalPoint(const easyar_CameraParameters * This);
easyar_CameraDeviceType easyar_CameraParameters_cameraDeviceType(const easyar_CameraParameters * This);
int easyar_CameraParameters_cameraOrientation(const easyar_CameraParameters * This);
void easyar_CameraParameters_createWithDefaultIntrinsics(easyar_Vec2I size, easyar_CameraDeviceType cameraDeviceType, int cameraOrientation, /* OUT */ easyar_CameraParameters * * Return);
int easyar_CameraParameters_imageOrientation(const easyar_CameraParameters * This, int screenRotation);
bool easyar_CameraParameters_imageHorizontalFlip(const easyar_CameraParameters * This, bool manualHorizontalFlip);
easyar_Matrix44F easyar_CameraParameters_projection(const easyar_CameraParameters * This, float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
easyar_Matrix44F easyar_CameraParameters_imageProjection(const easyar_CameraParameters * This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
easyar_Vec2F easyar_CameraParameters_screenCoordinatesFromImageCoordinates(const easyar_CameraParameters * This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, easyar_Vec2F imageCoordinates);
easyar_Vec2F easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(const easyar_CameraParameters * This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, easyar_Vec2F screenCoordinates);
bool easyar_CameraParameters_equalsTo(const easyar_CameraParameters * This, easyar_CameraParameters * other);
void easyar_CameraParameters__dtor(easyar_CameraParameters * This);
void easyar_CameraParameters__retain(const easyar_CameraParameters * This, /* OUT */ easyar_CameraParameters * * Return);
const char * easyar_CameraParameters__typeName(const easyar_CameraParameters * This);

#ifdef __cplusplus
}
#endif

#endif
