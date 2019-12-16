//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_FRAME_HXX__
#define __EASYAR_FRAME_HXX__

#include "easyar/types.hxx"

namespace easyar {

class InputFrame
{
protected:
    easyar_InputFrame * cdata_ ;
    void init_cdata(easyar_InputFrame * cdata);
    virtual InputFrame & operator=(const InputFrame & data) { return *this; } //deleted
public:
    InputFrame(easyar_InputFrame * cdata);
    virtual ~InputFrame();

    InputFrame(const InputFrame & data);
    const easyar_InputFrame * get_cdata() const;
    easyar_InputFrame * get_cdata();

    int index();
    void image(/* OUT */ Image * * Return);
    bool hasCameraParameters();
    void cameraParameters(/* OUT */ CameraParameters * * Return);
    bool hasTemporalInformation();
    double timestamp();
    bool hasSpatialInformation();
    Matrix44F cameraTransform();
    InputFrameTrackingStatus trackingStatus();
    static void create(Image * image, CameraParameters * cameraParameters, double timestamp, Matrix44F cameraTransform, InputFrameTrackingStatus trackingStatus, /* OUT */ InputFrame * * Return);
    static void createWithImageAndCameraParametersAndTemporal(Image * image, CameraParameters * cameraParameters, double timestamp, /* OUT */ InputFrame * * Return);
    static void createWithImageAndCameraParameters(Image * image, CameraParameters * cameraParameters, /* OUT */ InputFrame * * Return);
    static void createWithImage(Image * image, /* OUT */ InputFrame * * Return);
};

class FrameFilterResult
{
protected:
    easyar_FrameFilterResult * cdata_ ;
    void init_cdata(easyar_FrameFilterResult * cdata);
    virtual FrameFilterResult & operator=(const FrameFilterResult & data) { return *this; } //deleted
public:
    FrameFilterResult(easyar_FrameFilterResult * cdata);
    virtual ~FrameFilterResult();

    FrameFilterResult(const FrameFilterResult & data);
    const easyar_FrameFilterResult * get_cdata() const;
    easyar_FrameFilterResult * get_cdata();

};

class OutputFrame
{
protected:
    easyar_OutputFrame * cdata_ ;
    void init_cdata(easyar_OutputFrame * cdata);
    virtual OutputFrame & operator=(const OutputFrame & data) { return *this; } //deleted
public:
    OutputFrame(easyar_OutputFrame * cdata);
    virtual ~OutputFrame();

    OutputFrame(const OutputFrame & data);
    const easyar_OutputFrame * get_cdata() const;
    easyar_OutputFrame * get_cdata();

    OutputFrame(InputFrame * inputFrame, ListOfOptionalOfFrameFilterResult * results);
    int index();
    void inputFrame(/* OUT */ InputFrame * * Return);
    void results(/* OUT */ ListOfOptionalOfFrameFilterResult * * Return);
};

class FeedbackFrame
{
protected:
    easyar_FeedbackFrame * cdata_ ;
    void init_cdata(easyar_FeedbackFrame * cdata);
    virtual FeedbackFrame & operator=(const FeedbackFrame & data) { return *this; } //deleted
public:
    FeedbackFrame(easyar_FeedbackFrame * cdata);
    virtual ~FeedbackFrame();

    FeedbackFrame(const FeedbackFrame & data);
    const easyar_FeedbackFrame * get_cdata() const;
    easyar_FeedbackFrame * get_cdata();

    FeedbackFrame(InputFrame * inputFrame, OutputFrame * previousOutputFrame);
    void inputFrame(/* OUT */ InputFrame * * Return);
    void previousOutputFrame(/* OUT */ OutputFrame * * Return);
};

#ifndef __EASYAR_OPTIONALOFFRAMEFILTERRESULT__
#define __EASYAR_OPTIONALOFFRAMEFILTERRESULT__
struct OptionalOfFrameFilterResult
{
    bool has_value;
    FrameFilterResult * value;
};
static inline easyar_OptionalOfFrameFilterResult OptionalOfFrameFilterResult_to_c(FrameFilterResult * o);
#endif

#ifndef __EASYAR_LISTOFOPTIONALOFFRAMEFILTERRESULT__
#define __EASYAR_LISTOFOPTIONALOFFRAMEFILTERRESULT__
class ListOfOptionalOfFrameFilterResult
{
private:
    easyar_ListOfOptionalOfFrameFilterResult * cdata_;
    virtual ListOfOptionalOfFrameFilterResult & operator=(const ListOfOptionalOfFrameFilterResult & data) { return *this; } //deleted
public:
    ListOfOptionalOfFrameFilterResult(easyar_ListOfOptionalOfFrameFilterResult * cdata);
    virtual ~ListOfOptionalOfFrameFilterResult();

    ListOfOptionalOfFrameFilterResult(const ListOfOptionalOfFrameFilterResult & data);
    const easyar_ListOfOptionalOfFrameFilterResult * get_cdata() const;
    easyar_ListOfOptionalOfFrameFilterResult * get_cdata();

    ListOfOptionalOfFrameFilterResult(easyar_OptionalOfFrameFilterResult * begin, easyar_OptionalOfFrameFilterResult * end);
    int size() const;
    FrameFilterResult * at(int index) const;
};
#endif

#ifndef __EASYAR_OPTIONALOFOUTPUTFRAME__
#define __EASYAR_OPTIONALOFOUTPUTFRAME__
struct OptionalOfOutputFrame
{
    bool has_value;
    OutputFrame * value;
};
static inline easyar_OptionalOfOutputFrame OptionalOfOutputFrame_to_c(OutputFrame * o);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_FRAME_HXX__
#define __IMPLEMENTATION_EASYAR_FRAME_HXX__

#include "easyar/frame.h"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/matrix.hxx"

namespace easyar {

inline InputFrame::InputFrame(easyar_InputFrame * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline InputFrame::~InputFrame()
{
    if (cdata_) {
        easyar_InputFrame__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline InputFrame::InputFrame(const InputFrame & data)
    :
    cdata_(NULL)
{
    easyar_InputFrame * cdata = NULL;
    easyar_InputFrame__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_InputFrame * InputFrame::get_cdata() const
{
    return cdata_;
}
inline easyar_InputFrame * InputFrame::get_cdata()
{
    return cdata_;
}
inline void InputFrame::init_cdata(easyar_InputFrame * cdata)
{
    cdata_ = cdata;
}
inline int InputFrame::index()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_InputFrame_index(cdata_);
    return _return_value_;
}
inline void InputFrame::image(/* OUT */ Image * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Image * _return_value_ = NULL;
    easyar_InputFrame_image(cdata_, &_return_value_);
    *Return = new Image(_return_value_);
}
inline bool InputFrame::hasCameraParameters()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_InputFrame_hasCameraParameters(cdata_);
    return _return_value_;
}
inline void InputFrame::cameraParameters(/* OUT */ CameraParameters * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CameraParameters * _return_value_ = NULL;
    easyar_InputFrame_cameraParameters(cdata_, &_return_value_);
    *Return = new CameraParameters(_return_value_);
}
inline bool InputFrame::hasTemporalInformation()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_InputFrame_hasTemporalInformation(cdata_);
    return _return_value_;
}
inline double InputFrame::timestamp()
{
    if (cdata_ == NULL) {
        return double();
    }
    double _return_value_ = easyar_InputFrame_timestamp(cdata_);
    return _return_value_;
}
inline bool InputFrame::hasSpatialInformation()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_InputFrame_hasSpatialInformation(cdata_);
    return _return_value_;
}
inline Matrix44F InputFrame::cameraTransform()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_InputFrame_cameraTransform(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline InputFrameTrackingStatus InputFrame::trackingStatus()
{
    if (cdata_ == NULL) {
        return InputFrameTrackingStatus();
    }
    easyar_InputFrameTrackingStatus _return_value_ = easyar_InputFrame_trackingStatus(cdata_);
    return static_cast<InputFrameTrackingStatus>(_return_value_);
}
inline void InputFrame::create(Image * arg0, CameraParameters * arg1, double arg2, Matrix44F arg3, InputFrameTrackingStatus arg4, /* OUT */ InputFrame * * Return)
{
    easyar_InputFrame * _return_value_ = NULL;
    easyar_InputFrame_create(arg0->get_cdata(), arg1->get_cdata(), arg2, arg3.get_cdata(), static_cast<easyar_InputFrameTrackingStatus>(arg4), &_return_value_);
    *Return = new InputFrame(_return_value_);
}
inline void InputFrame::createWithImageAndCameraParametersAndTemporal(Image * arg0, CameraParameters * arg1, double arg2, /* OUT */ InputFrame * * Return)
{
    easyar_InputFrame * _return_value_ = NULL;
    easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(arg0->get_cdata(), arg1->get_cdata(), arg2, &_return_value_);
    *Return = new InputFrame(_return_value_);
}
inline void InputFrame::createWithImageAndCameraParameters(Image * arg0, CameraParameters * arg1, /* OUT */ InputFrame * * Return)
{
    easyar_InputFrame * _return_value_ = NULL;
    easyar_InputFrame_createWithImageAndCameraParameters(arg0->get_cdata(), arg1->get_cdata(), &_return_value_);
    *Return = new InputFrame(_return_value_);
}
inline void InputFrame::createWithImage(Image * arg0, /* OUT */ InputFrame * * Return)
{
    easyar_InputFrame * _return_value_ = NULL;
    easyar_InputFrame_createWithImage(arg0->get_cdata(), &_return_value_);
    *Return = new InputFrame(_return_value_);
}

inline FrameFilterResult::FrameFilterResult(easyar_FrameFilterResult * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline FrameFilterResult::~FrameFilterResult()
{
    if (cdata_) {
        easyar_FrameFilterResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline FrameFilterResult::FrameFilterResult(const FrameFilterResult & data)
    :
    cdata_(NULL)
{
    easyar_FrameFilterResult * cdata = NULL;
    easyar_FrameFilterResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_FrameFilterResult * FrameFilterResult::get_cdata() const
{
    return cdata_;
}
inline easyar_FrameFilterResult * FrameFilterResult::get_cdata()
{
    return cdata_;
}
inline void FrameFilterResult::init_cdata(easyar_FrameFilterResult * cdata)
{
    cdata_ = cdata;
}

inline OutputFrame::OutputFrame(easyar_OutputFrame * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline OutputFrame::~OutputFrame()
{
    if (cdata_) {
        easyar_OutputFrame__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline OutputFrame::OutputFrame(const OutputFrame & data)
    :
    cdata_(NULL)
{
    easyar_OutputFrame * cdata = NULL;
    easyar_OutputFrame__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_OutputFrame * OutputFrame::get_cdata() const
{
    return cdata_;
}
inline easyar_OutputFrame * OutputFrame::get_cdata()
{
    return cdata_;
}
inline void OutputFrame::init_cdata(easyar_OutputFrame * cdata)
{
    cdata_ = cdata;
}
inline OutputFrame::OutputFrame(InputFrame * arg0, ListOfOptionalOfFrameFilterResult * arg1)
    :
    cdata_(NULL)
{
    easyar_OutputFrame * _return_value_ = NULL;
    easyar_OutputFrame__ctor(arg0->get_cdata(), arg1->get_cdata(), &_return_value_);
    init_cdata(_return_value_);
}
inline int OutputFrame::index()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_OutputFrame_index(cdata_);
    return _return_value_;
}
inline void OutputFrame::inputFrame(/* OUT */ InputFrame * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrame * _return_value_ = NULL;
    easyar_OutputFrame_inputFrame(cdata_, &_return_value_);
    *Return = new InputFrame(_return_value_);
}
inline void OutputFrame::results(/* OUT */ ListOfOptionalOfFrameFilterResult * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfOptionalOfFrameFilterResult * _return_value_ = NULL;
    easyar_OutputFrame_results(cdata_, &_return_value_);
    *Return = new ListOfOptionalOfFrameFilterResult(_return_value_);
}

inline FeedbackFrame::FeedbackFrame(easyar_FeedbackFrame * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline FeedbackFrame::~FeedbackFrame()
{
    if (cdata_) {
        easyar_FeedbackFrame__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline FeedbackFrame::FeedbackFrame(const FeedbackFrame & data)
    :
    cdata_(NULL)
{
    easyar_FeedbackFrame * cdata = NULL;
    easyar_FeedbackFrame__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_FeedbackFrame * FeedbackFrame::get_cdata() const
{
    return cdata_;
}
inline easyar_FeedbackFrame * FeedbackFrame::get_cdata()
{
    return cdata_;
}
inline void FeedbackFrame::init_cdata(easyar_FeedbackFrame * cdata)
{
    cdata_ = cdata;
}
inline FeedbackFrame::FeedbackFrame(InputFrame * arg0, OutputFrame * arg1)
    :
    cdata_(NULL)
{
    easyar_FeedbackFrame * _return_value_ = NULL;
    easyar_FeedbackFrame__ctor(arg0->get_cdata(), OptionalOfOutputFrame_to_c(arg1), &_return_value_);
    init_cdata(_return_value_);
}
inline void FeedbackFrame::inputFrame(/* OUT */ InputFrame * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrame * _return_value_ = NULL;
    easyar_FeedbackFrame_inputFrame(cdata_, &_return_value_);
    *Return = new InputFrame(_return_value_);
}
inline void FeedbackFrame::previousOutputFrame(/* OUT */ OutputFrame * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OptionalOfOutputFrame _return_value_ = {false, NULL};
    easyar_FeedbackFrame_previousOutputFrame(cdata_, &_return_value_);
    *Return = (_return_value_.has_value ? new OutputFrame(_return_value_.value) : NULL);
}

#ifndef __IMPLEMENTATION_EASYAR_LISTOFOPTIONALOFFRAMEFILTERRESULT__
#define __IMPLEMENTATION_EASYAR_LISTOFOPTIONALOFFRAMEFILTERRESULT__
inline ListOfOptionalOfFrameFilterResult::ListOfOptionalOfFrameFilterResult(easyar_ListOfOptionalOfFrameFilterResult * cdata)
    : cdata_(cdata)
{
}
inline ListOfOptionalOfFrameFilterResult::~ListOfOptionalOfFrameFilterResult()
{
    if (cdata_) {
        easyar_ListOfOptionalOfFrameFilterResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfOptionalOfFrameFilterResult::ListOfOptionalOfFrameFilterResult(const ListOfOptionalOfFrameFilterResult & data)
    : cdata_(static_cast<easyar_ListOfOptionalOfFrameFilterResult *>(NULL))
{
    easyar_ListOfOptionalOfFrameFilterResult_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfOptionalOfFrameFilterResult * ListOfOptionalOfFrameFilterResult::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfOptionalOfFrameFilterResult * ListOfOptionalOfFrameFilterResult::get_cdata()
{
    return cdata_;
}

inline ListOfOptionalOfFrameFilterResult::ListOfOptionalOfFrameFilterResult(easyar_OptionalOfFrameFilterResult * begin, easyar_OptionalOfFrameFilterResult * end)
    : cdata_(static_cast<easyar_ListOfOptionalOfFrameFilterResult *>(NULL))
{
    easyar_ListOfOptionalOfFrameFilterResult__ctor(begin, end, &cdata_);
}
inline int ListOfOptionalOfFrameFilterResult::size() const
{
    return easyar_ListOfOptionalOfFrameFilterResult_size(cdata_);
}
inline FrameFilterResult * ListOfOptionalOfFrameFilterResult::at(int index) const
{
    easyar_OptionalOfFrameFilterResult _return_value_ = easyar_ListOfOptionalOfFrameFilterResult_at(cdata_, index);
    if (_return_value_.has_value) { easyar_FrameFilterResult__retain(_return_value_.value, &_return_value_.value); }
    return (_return_value_.has_value ? new FrameFilterResult(_return_value_.value) : NULL);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFFRAMEFILTERRESULT__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFFRAMEFILTERRESULT__
static inline easyar_OptionalOfFrameFilterResult OptionalOfFrameFilterResult_to_c(FrameFilterResult * o)
{
    if (o != NULL) {
        easyar_OptionalOfFrameFilterResult _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfFrameFilterResult _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFOUTPUTFRAME__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFOUTPUTFRAME__
static inline easyar_OptionalOfOutputFrame OptionalOfOutputFrame_to_c(OutputFrame * o)
{
    if (o != NULL) {
        easyar_OptionalOfOutputFrame _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfOutputFrame _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

}

#endif
