//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_IMAGETARGET_H__
#define __EASYAR_IMAGETARGET_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_ImageTargetParameters__ctor(/* OUT */ easyar_ImageTargetParameters * * Return);
void easyar_ImageTargetParameters_image(easyar_ImageTargetParameters * This, /* OUT */ easyar_Image * * Return);
void easyar_ImageTargetParameters_setImage(easyar_ImageTargetParameters * This, easyar_Image * image);
void easyar_ImageTargetParameters_name(easyar_ImageTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTargetParameters_setName(easyar_ImageTargetParameters * This, easyar_String * name);
void easyar_ImageTargetParameters_uid(easyar_ImageTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTargetParameters_setUid(easyar_ImageTargetParameters * This, easyar_String * uid);
void easyar_ImageTargetParameters_meta(easyar_ImageTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTargetParameters_setMeta(easyar_ImageTargetParameters * This, easyar_String * meta);
float easyar_ImageTargetParameters_scale(easyar_ImageTargetParameters * This);
void easyar_ImageTargetParameters_setScale(easyar_ImageTargetParameters * This, float scale);
void easyar_ImageTargetParameters__dtor(easyar_ImageTargetParameters * This);
void easyar_ImageTargetParameters__retain(const easyar_ImageTargetParameters * This, /* OUT */ easyar_ImageTargetParameters * * Return);
const char * easyar_ImageTargetParameters__typeName(const easyar_ImageTargetParameters * This);

void easyar_ImageTarget__ctor(/* OUT */ easyar_ImageTarget * * Return);
void easyar_ImageTarget_createFromParameters(easyar_ImageTargetParameters * parameters, /* OUT */ easyar_OptionalOfImageTarget * Return);
void easyar_ImageTarget_createFromTargetFile(easyar_String * path, easyar_StorageType storageType, /* OUT */ easyar_OptionalOfImageTarget * Return);
void easyar_ImageTarget_createFromTargetData(easyar_Buffer * buffer, /* OUT */ easyar_OptionalOfImageTarget * Return);
bool easyar_ImageTarget_save(easyar_ImageTarget * This, easyar_String * path);
void easyar_ImageTarget_createFromImageFile(easyar_String * path, easyar_StorageType storageType, easyar_String * name, easyar_String * uid, easyar_String * meta, float scale, /* OUT */ easyar_OptionalOfImageTarget * Return);
void easyar_ImageTarget_setupAll(easyar_String * path, easyar_StorageType storageType, /* OUT */ easyar_ListOfImageTarget * * Return);
float easyar_ImageTarget_scale(const easyar_ImageTarget * This);
float easyar_ImageTarget_aspectRatio(const easyar_ImageTarget * This);
bool easyar_ImageTarget_setScale(easyar_ImageTarget * This, float scale);
void easyar_ImageTarget_images(easyar_ImageTarget * This, /* OUT */ easyar_ListOfImage * * Return);
int easyar_ImageTarget_runtimeID(const easyar_ImageTarget * This);
void easyar_ImageTarget_uid(const easyar_ImageTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTarget_name(const easyar_ImageTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTarget_setName(easyar_ImageTarget * This, easyar_String * name);
void easyar_ImageTarget_meta(const easyar_ImageTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ImageTarget_setMeta(easyar_ImageTarget * This, easyar_String * data);
void easyar_ImageTarget__dtor(easyar_ImageTarget * This);
void easyar_ImageTarget__retain(const easyar_ImageTarget * This, /* OUT */ easyar_ImageTarget * * Return);
const char * easyar_ImageTarget__typeName(const easyar_ImageTarget * This);
void easyar_castImageTargetToTarget(const easyar_ImageTarget * This, /* OUT */ easyar_Target * * Return);
void easyar_tryCastTargetToImageTarget(const easyar_Target * This, /* OUT */ easyar_ImageTarget * * Return);

void easyar_ListOfImageTarget__ctor(easyar_ImageTarget * const * begin, easyar_ImageTarget * const * end, /* OUT */ easyar_ListOfImageTarget * * Return);
void easyar_ListOfImageTarget__dtor(easyar_ListOfImageTarget * This);
void easyar_ListOfImageTarget_copy(const easyar_ListOfImageTarget * This, /* OUT */ easyar_ListOfImageTarget * * Return);
int easyar_ListOfImageTarget_size(const easyar_ListOfImageTarget * This);
easyar_ImageTarget * easyar_ListOfImageTarget_at(const easyar_ListOfImageTarget * This, int index);

void easyar_ListOfImage__ctor(easyar_Image * const * begin, easyar_Image * const * end, /* OUT */ easyar_ListOfImage * * Return);
void easyar_ListOfImage__dtor(easyar_ListOfImage * This);
void easyar_ListOfImage_copy(const easyar_ListOfImage * This, /* OUT */ easyar_ListOfImage * * Return);
int easyar_ListOfImage_size(const easyar_ListOfImage * This);
easyar_Image * easyar_ListOfImage_at(const easyar_ListOfImage * This, int index);

#ifdef __cplusplus
}
#endif

#endif
