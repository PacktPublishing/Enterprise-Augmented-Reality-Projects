//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_SignalSink : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)handle;

@end

@interface easyar_SignalSource : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)setHandler:(void (^)())handler;
- (void)connect:(easyar_SignalSink *)sink;
- (void)disconnect;

@end

@interface easyar_InputFrameSink : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)handle:(easyar_InputFrame *)inputData;

@end

@interface easyar_InputFrameSource : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)setHandler:(void (^)(easyar_InputFrame *))handler;
- (void)connect:(easyar_InputFrameSink *)sink;
- (void)disconnect;

@end

@interface easyar_OutputFrameSink : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)handle:(easyar_OutputFrame *)inputData;

@end

@interface easyar_OutputFrameSource : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)setHandler:(void (^)(easyar_OutputFrame *))handler;
- (void)connect:(easyar_OutputFrameSink *)sink;
- (void)disconnect;

@end

@interface easyar_FeedbackFrameSink : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)handle:(easyar_FeedbackFrame *)inputData;

@end

@interface easyar_FeedbackFrameSource : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)setHandler:(void (^)(easyar_FeedbackFrame *))handler;
- (void)connect:(easyar_FeedbackFrameSink *)sink;
- (void)disconnect;

@end

@interface easyar_InputFrameFork : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_InputFrameSink *)input;
- (easyar_InputFrameSource *)output:(int)index;
- (int)outputCount;
+ (easyar_InputFrameFork *)create:(int)outputCount;

@end

@interface easyar_OutputFrameFork : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_OutputFrameSink *)input;
- (easyar_OutputFrameSource *)output:(int)index;
- (int)outputCount;
+ (easyar_OutputFrameFork *)create:(int)outputCount;

@end

@interface easyar_OutputFrameJoin : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_OutputFrameSink *)input:(int)index;
- (easyar_OutputFrameSource *)output;
- (int)inputCount;
+ (easyar_OutputFrameJoin *)create:(int)inputCount;
+ (easyar_OutputFrameJoin *)createWithJoiner:(int)inputCount joiner:(easyar_OutputFrame * (^)(NSArray<easyar_OutputFrame *> *))joiner;

@end

@interface easyar_FeedbackFrameFork : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_FeedbackFrameSink *)input;
- (easyar_FeedbackFrameSource *)output:(int)index;
- (int)outputCount;
+ (easyar_FeedbackFrameFork *)create:(int)outputCount;

@end

@interface easyar_InputFrameThrottler : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_InputFrameSink *)input;
- (easyar_InputFrameSource *)output;
- (easyar_SignalSink *)signalInput;
+ (easyar_InputFrameThrottler *)create;

@end

@interface easyar_OutputFrameBuffer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_OutputFrameSink *)input;
- (easyar_SignalSource *)signalOutput;
- (easyar_OutputFrame *)peek;
+ (easyar_OutputFrameBuffer *)create;

@end

@interface easyar_InputFrameToOutputFrameAdapter : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_InputFrameSink *)input;
- (easyar_OutputFrameSource *)output;
+ (easyar_InputFrameToOutputFrameAdapter *)create;

@end

@interface easyar_InputFrameToFeedbackFrameAdapter : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_InputFrameSink *)input;
- (easyar_OutputFrameSink *)sideInput;
- (easyar_FeedbackFrameSource *)output;
+ (easyar_InputFrameToFeedbackFrameAdapter *)create;

@end
