//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_InputFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (int)index;
- (easyar_Image *)image;
- (bool)hasCameraParameters;
- (easyar_CameraParameters *)cameraParameters;
- (bool)hasTemporalInformation;
- (double)timestamp;
- (bool)hasSpatialInformation;
- (easyar_Matrix44F *)cameraTransform;
- (easyar_InputFrameTrackingStatus)trackingStatus;
+ (easyar_InputFrame *)create:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters timestamp:(double)timestamp cameraTransform:(easyar_Matrix44F *)cameraTransform trackingStatus:(easyar_InputFrameTrackingStatus)trackingStatus;
+ (easyar_InputFrame *)createWithImageAndCameraParametersAndTemporal:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters timestamp:(double)timestamp;
+ (easyar_InputFrame *)createWithImageAndCameraParameters:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters;
+ (easyar_InputFrame *)createWithImage:(easyar_Image *)image;

@end

@interface easyar_FrameFilterResult : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

@interface easyar_OutputFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_OutputFrame *) create:(easyar_InputFrame *)inputFrame results:(NSArray<easyar_FrameFilterResult *> *)results;
- (int)index;
- (easyar_InputFrame *)inputFrame;
- (NSArray<easyar_FrameFilterResult *> *)results;

@end

@interface easyar_FeedbackFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_FeedbackFrame *) create:(easyar_InputFrame *)inputFrame previousOutputFrame:(easyar_OutputFrame *)previousOutputFrame;
- (easyar_InputFrame *)inputFrame;
- (easyar_OutputFrame *)previousOutputFrame;

@end
