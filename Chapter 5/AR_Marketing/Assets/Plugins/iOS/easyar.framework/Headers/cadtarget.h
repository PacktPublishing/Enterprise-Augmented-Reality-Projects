//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CADTARGET_H__
#define __EASYAR_CADTARGET_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_CADTarget__ctor(/* OUT */ easyar_CADTarget * * Return);
void easyar_CADTarget_createFromUnity(easyar_Buffer * vertices, easyar_Buffer * faces, easyar_Matrix44F transform, float localScale, /* OUT */ easyar_OptionalOfCADTarget * Return);
void easyar_CADTarget_updateTransform(easyar_CADTarget * This, easyar_Matrix44F transform, float localScale);
void easyar_CADTarget_updateTrackConfig(easyar_CADTarget * This, float threshContrast, float threshConsist, float threshQuality);
void easyar_CADTarget_createFromObjectFile(easyar_String * path, easyar_StorageType storageType, easyar_String * name, easyar_String * uid, easyar_String * meta, float scale, /* OUT */ easyar_OptionalOfCADTarget * Return);
void easyar_CADTarget_setupAll(easyar_String * path, easyar_StorageType storageType, /* OUT */ easyar_ListOfCADTarget * * Return);
float easyar_CADTarget_scale(const easyar_CADTarget * This);
void easyar_CADTarget_boundingBox(easyar_CADTarget * This, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_CADTarget_boundingBoxGL(easyar_CADTarget * This, /* OUT */ easyar_ListOfVec3F * * Return);
bool easyar_CADTarget_setScale(easyar_CADTarget * This, float scale);
int easyar_CADTarget_runtimeID(const easyar_CADTarget * This);
void easyar_CADTarget_uid(const easyar_CADTarget * This, /* OUT */ easyar_String * * Return);
void easyar_CADTarget_name(const easyar_CADTarget * This, /* OUT */ easyar_String * * Return);
void easyar_CADTarget_setName(easyar_CADTarget * This, easyar_String * name);
void easyar_CADTarget_meta(const easyar_CADTarget * This, /* OUT */ easyar_String * * Return);
void easyar_CADTarget_setMeta(easyar_CADTarget * This, easyar_String * data);
void easyar_CADTarget__dtor(easyar_CADTarget * This);
void easyar_CADTarget__retain(const easyar_CADTarget * This, /* OUT */ easyar_CADTarget * * Return);
const char * easyar_CADTarget__typeName(const easyar_CADTarget * This);
void easyar_castCADTargetToTarget(const easyar_CADTarget * This, /* OUT */ easyar_Target * * Return);
void easyar_tryCastTargetToCADTarget(const easyar_Target * This, /* OUT */ easyar_CADTarget * * Return);

void easyar_ListOfCADTarget__ctor(easyar_CADTarget * const * begin, easyar_CADTarget * const * end, /* OUT */ easyar_ListOfCADTarget * * Return);
void easyar_ListOfCADTarget__dtor(easyar_ListOfCADTarget * This);
void easyar_ListOfCADTarget_copy(const easyar_ListOfCADTarget * This, /* OUT */ easyar_ListOfCADTarget * * Return);
int easyar_ListOfCADTarget_size(const easyar_ListOfCADTarget * This);
easyar_CADTarget * easyar_ListOfCADTarget_at(const easyar_ListOfCADTarget * This, int index);

void easyar_ListOfVec3F__ctor(easyar_Vec3F const * begin, easyar_Vec3F const * end, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_ListOfVec3F__dtor(easyar_ListOfVec3F * This);
void easyar_ListOfVec3F_copy(const easyar_ListOfVec3F * This, /* OUT */ easyar_ListOfVec3F * * Return);
int easyar_ListOfVec3F_size(const easyar_ListOfVec3F * This);
easyar_Vec3F easyar_ListOfVec3F_at(const easyar_ListOfVec3F * This, int index);

#ifdef __cplusplus
}
#endif

#endif
