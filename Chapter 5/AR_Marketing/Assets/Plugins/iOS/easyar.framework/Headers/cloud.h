//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CLOUD_H__
#define __EASYAR_CLOUD_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool easyar_CloudRecognizer_isAvailable();
void easyar_CloudRecognizer_inputFrameSink(easyar_CloudRecognizer * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_CloudRecognizer_create(easyar_String * server, easyar_String * appKey, easyar_String * appSecret, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget callback, /* OUT */ easyar_CloudRecognizer * * Return);
bool easyar_CloudRecognizer_start(easyar_CloudRecognizer * This);
void easyar_CloudRecognizer_stop(easyar_CloudRecognizer * This);
void easyar_CloudRecognizer_close(easyar_CloudRecognizer * This);
void easyar_CloudRecognizer__dtor(easyar_CloudRecognizer * This);
void easyar_CloudRecognizer__retain(const easyar_CloudRecognizer * This, /* OUT */ easyar_CloudRecognizer * * Return);
const char * easyar_CloudRecognizer__typeName(const easyar_CloudRecognizer * This);

void easyar_ListOfTarget__ctor(easyar_Target * const * begin, easyar_Target * const * end, /* OUT */ easyar_ListOfTarget * * Return);
void easyar_ListOfTarget__dtor(easyar_ListOfTarget * This);
void easyar_ListOfTarget_copy(const easyar_ListOfTarget * This, /* OUT */ easyar_ListOfTarget * * Return);
int easyar_ListOfTarget_size(const easyar_ListOfTarget * This);
easyar_Target * easyar_ListOfTarget_at(const easyar_ListOfTarget * This, int index);

#ifdef __cplusplus
}
#endif

#endif
