//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_VideoPlayer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_VideoPlayer *) create;
- (void)setVideoType:(easyar_VideoType)videoType;
- (void)setRenderTexture:(easyar_TextureId *)texture;
- (void)open:(NSString *)path storageType:(easyar_StorageType)storageType callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_VideoStatus status))callback;
- (void)close;
- (bool)play;
- (void)stop;
- (void)pause;
- (bool)isRenderTextureAvailable;
- (void)updateFrame;
- (int)duration;
- (int)currentPosition;
- (bool)seek:(int)position;
- (easyar_Vec2I *)size;
- (float)volume;
- (bool)setVolume:(float)volume;

@end
