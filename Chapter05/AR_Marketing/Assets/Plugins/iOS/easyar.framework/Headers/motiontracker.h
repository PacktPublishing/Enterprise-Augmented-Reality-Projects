//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MOTIONTRACKER_H__
#define __EASYAR_MOTIONTRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

easyar_Matrix44F easyar_MotionTrackerResult_transform(const easyar_MotionTrackerResult * This);
easyar_MotionTrackingStatus easyar_MotionTrackerResult_status(const easyar_MotionTrackerResult * This);
void easyar_MotionTrackerResult__dtor(easyar_MotionTrackerResult * This);
void easyar_MotionTrackerResult__retain(const easyar_MotionTrackerResult * This, /* OUT */ easyar_MotionTrackerResult * * Return);
const char * easyar_MotionTrackerResult__typeName(const easyar_MotionTrackerResult * This);
void easyar_castMotionTrackerResultToFrameFilterResult(const easyar_MotionTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToMotionTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_MotionTrackerResult * * Return);

bool easyar_MotionTracker_isAvailable();
void easyar_MotionTracker_inputFrameSink(easyar_MotionTracker * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_MotionTracker_outputFrameSource(easyar_MotionTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_MotionTracker_create(/* OUT */ easyar_MotionTracker * * Return);
bool easyar_MotionTracker_start(easyar_MotionTracker * This);
void easyar_MotionTracker_stop(easyar_MotionTracker * This);
void easyar_MotionTracker_close(easyar_MotionTracker * This);
void easyar_MotionTracker__dtor(easyar_MotionTracker * This);
void easyar_MotionTracker__retain(const easyar_MotionTracker * This, /* OUT */ easyar_MotionTracker * * Return);
const char * easyar_MotionTracker__typeName(const easyar_MotionTracker * This);

void easyar_MotionTrackerOutputFrameToInputFrameAdapter_input(easyar_MotionTrackerOutputFrameToInputFrameAdapter * This, /* OUT */ easyar_OutputFrameSink * * Return);
void easyar_MotionTrackerOutputFrameToInputFrameAdapter_output(easyar_MotionTrackerOutputFrameToInputFrameAdapter * This, /* OUT */ easyar_InputFrameSource * * Return);
void easyar_MotionTrackerOutputFrameToInputFrameAdapter_create(/* OUT */ easyar_MotionTrackerOutputFrameToInputFrameAdapter * * Return);
void easyar_MotionTrackerOutputFrameToInputFrameAdapter__dtor(easyar_MotionTrackerOutputFrameToInputFrameAdapter * This);
void easyar_MotionTrackerOutputFrameToInputFrameAdapter__retain(const easyar_MotionTrackerOutputFrameToInputFrameAdapter * This, /* OUT */ easyar_MotionTrackerOutputFrameToInputFrameAdapter * * Return);
const char * easyar_MotionTrackerOutputFrameToInputFrameAdapter__typeName(const easyar_MotionTrackerOutputFrameToInputFrameAdapter * This);

#ifdef __cplusplus
}
#endif

#endif
