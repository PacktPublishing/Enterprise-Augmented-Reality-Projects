//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_RecorderConfiguration : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_RecorderConfiguration *) create;
- (void)setOutputFile:(NSString *)path;
- (bool)setProfile:(easyar_RecordProfile)profile;
- (void)setVideoSize:(easyar_RecordVideoSize)framesize;
- (void)setVideoBitrate:(int)bitrate;
- (void)setChannelCount:(int)count;
- (void)setAudioSampleRate:(int)samplerate;
- (void)setAudioBitrate:(int)bitrate;
- (void)setVideoOrientation:(easyar_RecordVideoOrientation)mode;
- (void)setZoomMode:(easyar_RecordZoomMode)mode;

@end
