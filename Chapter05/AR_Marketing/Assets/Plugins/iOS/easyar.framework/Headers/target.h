//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_TARGET_H__
#define __EASYAR_TARGET_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

int easyar_Target_runtimeID(const easyar_Target * This);
void easyar_Target_uid(const easyar_Target * This, /* OUT */ easyar_String * * Return);
void easyar_Target_name(const easyar_Target * This, /* OUT */ easyar_String * * Return);
void easyar_Target_setName(easyar_Target * This, easyar_String * name);
void easyar_Target_meta(const easyar_Target * This, /* OUT */ easyar_String * * Return);
void easyar_Target_setMeta(easyar_Target * This, easyar_String * data);
void easyar_Target__dtor(easyar_Target * This);
void easyar_Target__retain(const easyar_Target * This, /* OUT */ easyar_Target * * Return);
const char * easyar_Target__typeName(const easyar_Target * This);

void easyar_TargetInstance__ctor(/* OUT */ easyar_TargetInstance * * Return);
easyar_TargetStatus easyar_TargetInstance_status(const easyar_TargetInstance * This);
void easyar_TargetInstance_target(const easyar_TargetInstance * This, /* OUT */ easyar_OptionalOfTarget * Return);
easyar_Matrix44F easyar_TargetInstance_pose(const easyar_TargetInstance * This);
void easyar_TargetInstance__dtor(easyar_TargetInstance * This);
void easyar_TargetInstance__retain(const easyar_TargetInstance * This, /* OUT */ easyar_TargetInstance * * Return);
const char * easyar_TargetInstance__typeName(const easyar_TargetInstance * This);

void easyar_TargetTrackerResult_targetInstances(const easyar_TargetTrackerResult * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_TargetTrackerResult_setTargetInstances(easyar_TargetTrackerResult * This, easyar_ListOfTargetInstance * instances);
void easyar_TargetTrackerResult__dtor(easyar_TargetTrackerResult * This);
void easyar_TargetTrackerResult__retain(const easyar_TargetTrackerResult * This, /* OUT */ easyar_TargetTrackerResult * * Return);
const char * easyar_TargetTrackerResult__typeName(const easyar_TargetTrackerResult * This);
void easyar_castTargetTrackerResultToFrameFilterResult(const easyar_TargetTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToTargetTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_TargetTrackerResult * * Return);

void easyar_ListOfTargetInstance__ctor(easyar_TargetInstance * const * begin, easyar_TargetInstance * const * end, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_ListOfTargetInstance__dtor(easyar_ListOfTargetInstance * This);
void easyar_ListOfTargetInstance_copy(const easyar_ListOfTargetInstance * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
int easyar_ListOfTargetInstance_size(const easyar_ListOfTargetInstance * This);
easyar_TargetInstance * easyar_ListOfTargetInstance_at(const easyar_ListOfTargetInstance * This, int index);

#ifdef __cplusplus
}
#endif

#endif
