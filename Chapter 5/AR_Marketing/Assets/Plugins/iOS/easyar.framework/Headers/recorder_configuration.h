//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_RECORDER_CONFIGURATION_H__
#define __EASYAR_RECORDER_CONFIGURATION_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_RecorderConfiguration__ctor(/* OUT */ easyar_RecorderConfiguration * * Return);
void easyar_RecorderConfiguration_setOutputFile(easyar_RecorderConfiguration * This, easyar_String * path);
bool easyar_RecorderConfiguration_setProfile(easyar_RecorderConfiguration * This, easyar_RecordProfile profile);
void easyar_RecorderConfiguration_setVideoSize(easyar_RecorderConfiguration * This, easyar_RecordVideoSize framesize);
void easyar_RecorderConfiguration_setVideoBitrate(easyar_RecorderConfiguration * This, int bitrate);
void easyar_RecorderConfiguration_setChannelCount(easyar_RecorderConfiguration * This, int count);
void easyar_RecorderConfiguration_setAudioSampleRate(easyar_RecorderConfiguration * This, int samplerate);
void easyar_RecorderConfiguration_setAudioBitrate(easyar_RecorderConfiguration * This, int bitrate);
void easyar_RecorderConfiguration_setVideoOrientation(easyar_RecorderConfiguration * This, easyar_RecordVideoOrientation mode);
void easyar_RecorderConfiguration_setZoomMode(easyar_RecorderConfiguration * This, easyar_RecordZoomMode mode);
void easyar_RecorderConfiguration__dtor(easyar_RecorderConfiguration * This);
void easyar_RecorderConfiguration__retain(const easyar_RecorderConfiguration * This, /* OUT */ easyar_RecorderConfiguration * * Return);
const char * easyar_RecorderConfiguration__typeName(const easyar_RecorderConfiguration * This);

#ifdef __cplusplus
}
#endif

#endif
