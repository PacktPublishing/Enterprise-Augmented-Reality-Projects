//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_IMAGETRACKER_H__
#define __EASYAR_IMAGETRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_ImageTrackerResult_targetInstances(const easyar_ImageTrackerResult * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_ImageTrackerResult_setTargetInstances(easyar_ImageTrackerResult * This, easyar_ListOfTargetInstance * instances);
void easyar_ImageTrackerResult__dtor(easyar_ImageTrackerResult * This);
void easyar_ImageTrackerResult__retain(const easyar_ImageTrackerResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);
const char * easyar_ImageTrackerResult__typeName(const easyar_ImageTrackerResult * This);
void easyar_castImageTrackerResultToFrameFilterResult(const easyar_ImageTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToImageTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);
void easyar_castImageTrackerResultToTargetTrackerResult(const easyar_ImageTrackerResult * This, /* OUT */ easyar_TargetTrackerResult * * Return);
void easyar_tryCastTargetTrackerResultToImageTrackerResult(const easyar_TargetTrackerResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);

bool easyar_ImageTracker_isAvailable();
void easyar_ImageTracker_feedbackFrameSink(easyar_ImageTracker * This, /* OUT */ easyar_FeedbackFrameSink * * Return);
void easyar_ImageTracker_outputFrameSource(easyar_ImageTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_ImageTracker_create(/* OUT */ easyar_ImageTracker * * Return);
void easyar_ImageTracker_createWithMode(easyar_ImageTrackerMode trackMode, /* OUT */ easyar_ImageTracker * * Return);
bool easyar_ImageTracker_start(easyar_ImageTracker * This);
void easyar_ImageTracker_stop(easyar_ImageTracker * This);
void easyar_ImageTracker_close(easyar_ImageTracker * This);
void easyar_ImageTracker_loadTarget(easyar_ImageTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ImageTracker_unloadTarget(easyar_ImageTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ImageTracker_targets(const easyar_ImageTracker * This, /* OUT */ easyar_ListOfTarget * * Return);
bool easyar_ImageTracker_setSimultaneousNum(easyar_ImageTracker * This, int num);
int easyar_ImageTracker_simultaneousNum(const easyar_ImageTracker * This);
void easyar_ImageTracker__dtor(easyar_ImageTracker * This);
void easyar_ImageTracker__retain(const easyar_ImageTracker * This, /* OUT */ easyar_ImageTracker * * Return);
const char * easyar_ImageTracker__typeName(const easyar_ImageTracker * This);

void easyar_ListOfTargetInstance__ctor(easyar_TargetInstance * const * begin, easyar_TargetInstance * const * end, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_ListOfTargetInstance__dtor(easyar_ListOfTargetInstance * This);
void easyar_ListOfTargetInstance_copy(const easyar_ListOfTargetInstance * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
int easyar_ListOfTargetInstance_size(const easyar_ListOfTargetInstance * This);
easyar_TargetInstance * easyar_ListOfTargetInstance_at(const easyar_ListOfTargetInstance * This, int index);

void easyar_ListOfTarget__ctor(easyar_Target * const * begin, easyar_Target * const * end, /* OUT */ easyar_ListOfTarget * * Return);
void easyar_ListOfTarget__dtor(easyar_ListOfTarget * This);
void easyar_ListOfTarget_copy(const easyar_ListOfTarget * This, /* OUT */ easyar_ListOfTarget * * Return);
int easyar_ListOfTarget_size(const easyar_ListOfTarget * This);
easyar_Target * easyar_ListOfTarget_at(const easyar_ListOfTarget * This, int index);

#ifdef __cplusplus
}
#endif

#endif
