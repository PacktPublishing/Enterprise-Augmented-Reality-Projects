//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_CameraDevice : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_CameraDevice *) create;
+ (bool)isAvailable;
- (easyar_AndroidCameraApiType)androidCameraApiType;
- (void)setAndroidCameraApiType:(easyar_AndroidCameraApiType)type;
- (int)bufferCapacity;
- (void)setBufferCapacity:(int)capacity;
- (easyar_InputFrameSource *)inputFrameSource;
- (void)setStateChangedCallback:(easyar_CallbackScheduler *)callbackScheduler stateChangedCallback:(void (^)(easyar_CameraState))stateChangedCallback;
+ (void)requestPermissions:(easyar_CallbackScheduler *)callbackScheduler permissionCallback:(void (^)(easyar_PermissionStatus status, NSString * value))permissionCallback;
- (bool)openWithIndex:(int)cameraIndex;
- (bool)openWithType:(easyar_CameraDeviceType)type;
- (bool)start;
- (void)stop;
- (void)close;
- (easyar_CameraDeviceType)type;
- (easyar_CameraParameters *)cameraParameters;
- (void)setCameraParameters:(easyar_CameraParameters *)cameraParameters;
- (easyar_Vec2I *)size;
- (int)supportedSizeCount;
- (easyar_Vec2I *)supportedSize:(int)index;
- (bool)setSize:(easyar_Vec2I *)size;
- (int)supportedFrameRateRangeCount;
- (float)supportedFrameRateRangeLower:(int)index;
- (float)supportedFrameRateRangeUpper:(int)index;
- (int)frameRateRange;
- (bool)setFrameRateRange:(int)index;
- (bool)setFlashTorchMode:(bool)on;
- (bool)setFocusMode:(easyar_CameraDeviceFocusMode)focusMode;
- (bool)autoFocus;
- (bool)setPresentProfile:(easyar_CameraDevicePresetProfile)profile;

@end

@interface easyar_CameraDeviceSelector : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_CameraDevice *)createCameraDevice:(easyar_CameraDevicePreference)preference;

@end
