//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_CloudRecognizer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (bool)isAvailable;
- (easyar_InputFrameSink *)inputFrameSink;
+ (easyar_CloudRecognizer *)create:(NSString *)server appKey:(NSString *)appKey appSecret:(NSString *)appSecret callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_CloudStatus status, NSArray<easyar_Target *> * targets))callback;
- (bool)start;
- (void)stop;
- (void)close;

@end
