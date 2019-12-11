//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_OBJECTTARGET_H__
#define __EASYAR_OBJECTTARGET_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_ObjectTargetParameters__ctor(/* OUT */ easyar_ObjectTargetParameters * * Return);
void easyar_ObjectTargetParameters_bufferDictionary(easyar_ObjectTargetParameters * This, /* OUT */ easyar_BufferDictionary * * Return);
void easyar_ObjectTargetParameters_setBufferDictionary(easyar_ObjectTargetParameters * This, easyar_BufferDictionary * bufferDictionary);
void easyar_ObjectTargetParameters_objPath(easyar_ObjectTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTargetParameters_setObjPath(easyar_ObjectTargetParameters * This, easyar_String * objPath);
void easyar_ObjectTargetParameters_name(easyar_ObjectTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTargetParameters_setName(easyar_ObjectTargetParameters * This, easyar_String * name);
void easyar_ObjectTargetParameters_uid(easyar_ObjectTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTargetParameters_setUid(easyar_ObjectTargetParameters * This, easyar_String * uid);
void easyar_ObjectTargetParameters_meta(easyar_ObjectTargetParameters * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTargetParameters_setMeta(easyar_ObjectTargetParameters * This, easyar_String * meta);
float easyar_ObjectTargetParameters_scale(easyar_ObjectTargetParameters * This);
void easyar_ObjectTargetParameters_setScale(easyar_ObjectTargetParameters * This, float size);
void easyar_ObjectTargetParameters__dtor(easyar_ObjectTargetParameters * This);
void easyar_ObjectTargetParameters__retain(const easyar_ObjectTargetParameters * This, /* OUT */ easyar_ObjectTargetParameters * * Return);
const char * easyar_ObjectTargetParameters__typeName(const easyar_ObjectTargetParameters * This);

void easyar_ObjectTarget__ctor(/* OUT */ easyar_ObjectTarget * * Return);
void easyar_ObjectTarget_createFromParameters(easyar_ObjectTargetParameters * parameters, /* OUT */ easyar_OptionalOfObjectTarget * Return);
void easyar_ObjectTarget_createFromObjectFile(easyar_String * path, easyar_StorageType storageType, easyar_String * name, easyar_String * uid, easyar_String * meta, float scale, /* OUT */ easyar_OptionalOfObjectTarget * Return);
void easyar_ObjectTarget_setupAll(easyar_String * path, easyar_StorageType storageType, /* OUT */ easyar_ListOfObjectTarget * * Return);
float easyar_ObjectTarget_scale(const easyar_ObjectTarget * This);
void easyar_ObjectTarget_boundingBox(easyar_ObjectTarget * This, /* OUT */ easyar_ListOfVec3F * * Return);
bool easyar_ObjectTarget_setScale(easyar_ObjectTarget * This, float scale);
int easyar_ObjectTarget_runtimeID(const easyar_ObjectTarget * This);
void easyar_ObjectTarget_uid(const easyar_ObjectTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTarget_name(const easyar_ObjectTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTarget_setName(easyar_ObjectTarget * This, easyar_String * name);
void easyar_ObjectTarget_meta(const easyar_ObjectTarget * This, /* OUT */ easyar_String * * Return);
void easyar_ObjectTarget_setMeta(easyar_ObjectTarget * This, easyar_String * data);
void easyar_ObjectTarget__dtor(easyar_ObjectTarget * This);
void easyar_ObjectTarget__retain(const easyar_ObjectTarget * This, /* OUT */ easyar_ObjectTarget * * Return);
const char * easyar_ObjectTarget__typeName(const easyar_ObjectTarget * This);
void easyar_castObjectTargetToTarget(const easyar_ObjectTarget * This, /* OUT */ easyar_Target * * Return);
void easyar_tryCastTargetToObjectTarget(const easyar_Target * This, /* OUT */ easyar_ObjectTarget * * Return);

void easyar_ListOfObjectTarget__ctor(easyar_ObjectTarget * const * begin, easyar_ObjectTarget * const * end, /* OUT */ easyar_ListOfObjectTarget * * Return);
void easyar_ListOfObjectTarget__dtor(easyar_ListOfObjectTarget * This);
void easyar_ListOfObjectTarget_copy(const easyar_ListOfObjectTarget * This, /* OUT */ easyar_ListOfObjectTarget * * Return);
int easyar_ListOfObjectTarget_size(const easyar_ListOfObjectTarget * This);
easyar_ObjectTarget * easyar_ListOfObjectTarget_at(const easyar_ListOfObjectTarget * This, int index);

void easyar_ListOfVec3F__ctor(easyar_Vec3F const * begin, easyar_Vec3F const * end, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_ListOfVec3F__dtor(easyar_ListOfVec3F * This);
void easyar_ListOfVec3F_copy(const easyar_ListOfVec3F * This, /* OUT */ easyar_ListOfVec3F * * Return);
int easyar_ListOfVec3F_size(const easyar_ListOfVec3F * This);
easyar_Vec3F easyar_ListOfVec3F_at(const easyar_ListOfVec3F * This, int index);

#ifdef __cplusplus
}
#endif

#endif
