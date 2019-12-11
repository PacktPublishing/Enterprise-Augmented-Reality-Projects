//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_Buffer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_Buffer *)wrap:(void *)ptr size:(int)size deleter:(void (^)())deleter;
+ (easyar_Buffer *)create:(int)size;
- (void *)data;
- (int)size;
+ (void)memoryCopy:(void *)src dest:(void *)dest length:(int)length;
- (bool)tryCopyFrom:(void *)src srcIndex:(int)srcIndex index:(int)index length:(int)length;
- (bool)tryCopyTo:(int)index dest:(void *)dest destIndex:(int)destIndex length:(int)length;
- (easyar_Buffer *)partition:(int)index length:(int)length;

@end

@interface easyar_BufferDictionary : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_BufferDictionary *) create;
- (int)count;
- (bool)contains:(NSString *)path;
- (easyar_Buffer *)tryGet:(NSString *)path;
- (void)set:(NSString *)path buffer:(easyar_Buffer *)buffer;
- (bool)remove:(NSString *)path;
- (void)clear;

@end
