//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SURFACETRACKER_H__
#define __EASYAR_SURFACETRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

easyar_Matrix44F easyar_SurfaceTrackerResult_transform(const easyar_SurfaceTrackerResult * This);
easyar_SurfaceTrackingStatus easyar_SurfaceTrackerResult_status(const easyar_SurfaceTrackerResult * This);
void easyar_SurfaceTrackerResult__dtor(easyar_SurfaceTrackerResult * This);
void easyar_SurfaceTrackerResult__retain(const easyar_SurfaceTrackerResult * This, /* OUT */ easyar_SurfaceTrackerResult * * Return);
const char * easyar_SurfaceTrackerResult__typeName(const easyar_SurfaceTrackerResult * This);
void easyar_castSurfaceTrackerResultToFrameFilterResult(const easyar_SurfaceTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToSurfaceTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_SurfaceTrackerResult * * Return);

bool easyar_SurfaceTracker_isAvailable();
void easyar_SurfaceTracker_inputFrameSink(easyar_SurfaceTracker * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_SurfaceTracker_outputFrameSource(easyar_SurfaceTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_SurfaceTracker_create(/* OUT */ easyar_SurfaceTracker * * Return);
bool easyar_SurfaceTracker_start(easyar_SurfaceTracker * This);
void easyar_SurfaceTracker_stop(easyar_SurfaceTracker * This);
void easyar_SurfaceTracker_close(easyar_SurfaceTracker * This);
void easyar_SurfaceTracker_alignTargetToCameraImagePoint(easyar_SurfaceTracker * This, easyar_Vec2F cameraImagePoint);
void easyar_SurfaceTracker__dtor(easyar_SurfaceTracker * This);
void easyar_SurfaceTracker__retain(const easyar_SurfaceTracker * This, /* OUT */ easyar_SurfaceTracker * * Return);
const char * easyar_SurfaceTracker__typeName(const easyar_SurfaceTracker * This);

#ifdef __cplusplus
}
#endif

#endif
