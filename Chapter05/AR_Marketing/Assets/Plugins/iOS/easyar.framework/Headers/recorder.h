//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_RECORDER_H__
#define __EASYAR_RECORDER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool easyar_Recorder_isAvailable();
void easyar_Recorder_requestPermissions(easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
void easyar_Recorder_create(easyar_RecorderConfiguration * config, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString statusCallback, /* OUT */ easyar_Recorder * * Return);
void easyar_Recorder_start(easyar_Recorder * This);
void easyar_Recorder_updateFrame(easyar_Recorder * This, easyar_TextureId * texture, int width, int height);
bool easyar_Recorder_stop(easyar_Recorder * This);
void easyar_Recorder__dtor(easyar_Recorder * This);
void easyar_Recorder__retain(const easyar_Recorder * This, /* OUT */ easyar_Recorder * * Return);
const char * easyar_Recorder__typeName(const easyar_Recorder * This);

#ifdef __cplusplus
}
#endif

#endif
