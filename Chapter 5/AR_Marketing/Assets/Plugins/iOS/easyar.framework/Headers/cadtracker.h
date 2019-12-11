//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CADTRACKER_H__
#define __EASYAR_CADTRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_CADTrackerResult_targetInstances(const easyar_CADTrackerResult * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_CADTrackerResult_setTargetInstances(easyar_CADTrackerResult * This, easyar_ListOfTargetInstance * instances);
void easyar_CADTrackerResult__dtor(easyar_CADTrackerResult * This);
void easyar_CADTrackerResult__retain(const easyar_CADTrackerResult * This, /* OUT */ easyar_CADTrackerResult * * Return);
const char * easyar_CADTrackerResult__typeName(const easyar_CADTrackerResult * This);
void easyar_castCADTrackerResultToFrameFilterResult(const easyar_CADTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToCADTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_CADTrackerResult * * Return);
void easyar_castCADTrackerResultToTargetTrackerResult(const easyar_CADTrackerResult * This, /* OUT */ easyar_TargetTrackerResult * * Return);
void easyar_tryCastTargetTrackerResultToCADTrackerResult(const easyar_TargetTrackerResult * This, /* OUT */ easyar_CADTrackerResult * * Return);

bool easyar_CADTracker_isAvailable();
void easyar_CADTracker_feedbackFrameSink(easyar_CADTracker * This, /* OUT */ easyar_FeedbackFrameSink * * Return);
void easyar_CADTracker_outputFrameSource(easyar_CADTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_CADTracker_create(/* OUT */ easyar_CADTracker * * Return);
bool easyar_CADTracker_start(easyar_CADTracker * This);
void easyar_CADTracker_stop(easyar_CADTracker * This);
void easyar_CADTracker_close(easyar_CADTracker * This);
void easyar_CADTracker_loadTarget(easyar_CADTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_CADTracker_unloadTarget(easyar_CADTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_CADTracker_targets(const easyar_CADTracker * This, /* OUT */ easyar_ListOfTarget * * Return);
void easyar_CADTracker__dtor(easyar_CADTracker * This);
void easyar_CADTracker__retain(const easyar_CADTracker * This, /* OUT */ easyar_CADTracker * * Return);
const char * easyar_CADTracker__typeName(const easyar_CADTracker * This);

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
