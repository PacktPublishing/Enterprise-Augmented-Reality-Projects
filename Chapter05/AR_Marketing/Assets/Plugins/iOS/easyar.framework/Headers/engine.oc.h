//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_Engine : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (int)schemaHash;
+ (bool)initialize:(NSString *)key;
+ (void)onPause;
+ (void)onResume;
+ (NSString *)errorMessage;
+ (NSString *)versionString;
+ (NSString *)name;

@end
