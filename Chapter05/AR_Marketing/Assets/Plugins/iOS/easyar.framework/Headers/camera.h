//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CAMERA_H__
#define __EASYAR_CAMERA_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_CameraDevice__ctor(/* OUT */ easyar_CameraDevice * * Return);
bool easyar_CameraDevice_isAvailable();
easyar_AndroidCameraApiType easyar_CameraDevice_androidCameraApiType(easyar_CameraDevice * This);
void easyar_CameraDevice_setAndroidCameraApiType(easyar_CameraDevice * This, easyar_AndroidCameraApiType type);
int easyar_CameraDevice_bufferCapacity(const easyar_CameraDevice * This);
void easyar_CameraDevice_setBufferCapacity(easyar_CameraDevice * This, int capacity);
void easyar_CameraDevice_inputFrameSource(easyar_CameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
void easyar_CameraDevice_setStateChangedCallback(easyar_CameraDevice * This, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromCameraState stateChangedCallback);
void easyar_CameraDevice_requestPermissions(easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
bool easyar_CameraDevice_openWithIndex(easyar_CameraDevice * This, int cameraIndex);
bool easyar_CameraDevice_openWithType(easyar_CameraDevice * This, easyar_CameraDeviceType type);
bool easyar_CameraDevice_start(easyar_CameraDevice * This);
void easyar_CameraDevice_stop(easyar_CameraDevice * This);
void easyar_CameraDevice_close(easyar_CameraDevice * This);
easyar_CameraDeviceType easyar_CameraDevice_type(const easyar_CameraDevice * This);
void easyar_CameraDevice_cameraParameters(easyar_CameraDevice * This, /* OUT */ easyar_CameraParameters * * Return);
void easyar_CameraDevice_setCameraParameters(easyar_CameraDevice * This, easyar_CameraParameters * cameraParameters);
easyar_Vec2I easyar_CameraDevice_size(const easyar_CameraDevice * This);
int easyar_CameraDevice_supportedSizeCount(const easyar_CameraDevice * This);
easyar_Vec2I easyar_CameraDevice_supportedSize(const easyar_CameraDevice * This, int index);
bool easyar_CameraDevice_setSize(easyar_CameraDevice * This, easyar_Vec2I size);
int easyar_CameraDevice_supportedFrameRateRangeCount(const easyar_CameraDevice * This);
float easyar_CameraDevice_supportedFrameRateRangeLower(const easyar_CameraDevice * This, int index);
float easyar_CameraDevice_supportedFrameRateRangeUpper(const easyar_CameraDevice * This, int index);
int easyar_CameraDevice_frameRateRange(const easyar_CameraDevice * This);
bool easyar_CameraDevice_setFrameRateRange(easyar_CameraDevice * This, int index);
bool easyar_CameraDevice_setFlashTorchMode(easyar_CameraDevice * This, bool on);
bool easyar_CameraDevice_setFocusMode(easyar_CameraDevice * This, easyar_CameraDeviceFocusMode focusMode);
bool easyar_CameraDevice_autoFocus(easyar_CameraDevice * This);
bool easyar_CameraDevice_setPresentProfile(easyar_CameraDevice * This, easyar_CameraDevicePresetProfile profile);
void easyar_CameraDevice__dtor(easyar_CameraDevice * This);
void easyar_CameraDevice__retain(const easyar_CameraDevice * This, /* OUT */ easyar_CameraDevice * * Return);
const char * easyar_CameraDevice__typeName(const easyar_CameraDevice * This);

void easyar_CameraDeviceSelector_createCameraDevice(easyar_CameraDevicePreference preference, /* OUT */ easyar_CameraDevice * * Return);

#ifdef __cplusplus
}
#endif

#endif
