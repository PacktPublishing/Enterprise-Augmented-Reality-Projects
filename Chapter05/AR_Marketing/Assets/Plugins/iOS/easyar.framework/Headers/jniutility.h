//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_JNIUTILITY_H__
#define __EASYAR_JNIUTILITY_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_JniUtility_wrapByteArray(void * bytes, bool readOnly, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * * Return);
void easyar_JniUtility_wrapBuffer(void * directBuffer, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * * Return);

#ifdef __cplusplus
}
#endif

#endif
