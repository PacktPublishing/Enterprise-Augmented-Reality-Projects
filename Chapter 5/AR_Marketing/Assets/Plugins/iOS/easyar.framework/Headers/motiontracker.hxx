//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MOTIONTRACKER_HXX__
#define __EASYAR_MOTIONTRACKER_HXX__

#include "easyar/types.hxx"
#include "easyar/frame.hxx"

namespace easyar {

class MotionTrackerResult : public FrameFilterResult
{
protected:
    easyar_MotionTrackerResult * cdata_ ;
    void init_cdata(easyar_MotionTrackerResult * cdata);
    virtual MotionTrackerResult & operator=(const MotionTrackerResult & data) { return *this; } //deleted
public:
    MotionTrackerResult(easyar_MotionTrackerResult * cdata);
    virtual ~MotionTrackerResult();

    MotionTrackerResult(const MotionTrackerResult & data);
    const easyar_MotionTrackerResult * get_cdata() const;
    easyar_MotionTrackerResult * get_cdata();

    Matrix44F transform();
    MotionTrackingStatus status();
    static void tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ MotionTrackerResult * * Return);
};

class MotionTracker
{
protected:
    easyar_MotionTracker * cdata_ ;
    void init_cdata(easyar_MotionTracker * cdata);
    virtual MotionTracker & operator=(const MotionTracker & data) { return *this; } //deleted
public:
    MotionTracker(easyar_MotionTracker * cdata);
    virtual ~MotionTracker();

    MotionTracker(const MotionTracker & data);
    const easyar_MotionTracker * get_cdata() const;
    easyar_MotionTracker * get_cdata();

    static bool isAvailable();
    void inputFrameSink(/* OUT */ InputFrameSink * * Return);
    void outputFrameSource(/* OUT */ OutputFrameSource * * Return);
    static void create(/* OUT */ MotionTracker * * Return);
    bool start();
    void stop();
    void close();
};

class MotionTrackerOutputFrameToInputFrameAdapter
{
protected:
    easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata_ ;
    void init_cdata(easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata);
    virtual MotionTrackerOutputFrameToInputFrameAdapter & operator=(const MotionTrackerOutputFrameToInputFrameAdapter & data) { return *this; } //deleted
public:
    MotionTrackerOutputFrameToInputFrameAdapter(easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata);
    virtual ~MotionTrackerOutputFrameToInputFrameAdapter();

    MotionTrackerOutputFrameToInputFrameAdapter(const MotionTrackerOutputFrameToInputFrameAdapter & data);
    const easyar_MotionTrackerOutputFrameToInputFrameAdapter * get_cdata() const;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter * get_cdata();

    void input(/* OUT */ OutputFrameSink * * Return);
    void output(/* OUT */ InputFrameSource * * Return);
    static void create(/* OUT */ MotionTrackerOutputFrameToInputFrameAdapter * * Return);
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_MOTIONTRACKER_HXX__
#define __IMPLEMENTATION_EASYAR_MOTIONTRACKER_HXX__

#include "easyar/motiontracker.h"
#include "easyar/frame.hxx"
#include "easyar/matrix.hxx"
#include "easyar/dataflow.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"

namespace easyar {

inline MotionTrackerResult::MotionTrackerResult(easyar_MotionTrackerResult * cdata)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline MotionTrackerResult::~MotionTrackerResult()
{
    if (cdata_) {
        easyar_MotionTrackerResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline MotionTrackerResult::MotionTrackerResult(const MotionTrackerResult & data)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    easyar_MotionTrackerResult * cdata = NULL;
    easyar_MotionTrackerResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_MotionTrackerResult * MotionTrackerResult::get_cdata() const
{
    return cdata_;
}
inline easyar_MotionTrackerResult * MotionTrackerResult::get_cdata()
{
    return cdata_;
}
inline void MotionTrackerResult::init_cdata(easyar_MotionTrackerResult * cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * cdata_inner = NULL;
        easyar_castMotionTrackerResultToFrameFilterResult(cdata, &cdata_inner);
        FrameFilterResult::init_cdata(cdata_inner);
    }
}
inline Matrix44F MotionTrackerResult::transform()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_MotionTrackerResult_transform(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline MotionTrackingStatus MotionTrackerResult::status()
{
    if (cdata_ == NULL) {
        return MotionTrackingStatus();
    }
    easyar_MotionTrackingStatus _return_value_ = easyar_MotionTrackerResult_status(cdata_);
    return static_cast<MotionTrackingStatus>(_return_value_);
}
inline void MotionTrackerResult::tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ MotionTrackerResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_MotionTrackerResult * cdata = NULL;
    easyar_tryCastFrameFilterResultToMotionTrackerResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new MotionTrackerResult(cdata);
}

inline MotionTracker::MotionTracker(easyar_MotionTracker * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline MotionTracker::~MotionTracker()
{
    if (cdata_) {
        easyar_MotionTracker__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline MotionTracker::MotionTracker(const MotionTracker & data)
    :
    cdata_(NULL)
{
    easyar_MotionTracker * cdata = NULL;
    easyar_MotionTracker__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_MotionTracker * MotionTracker::get_cdata() const
{
    return cdata_;
}
inline easyar_MotionTracker * MotionTracker::get_cdata()
{
    return cdata_;
}
inline void MotionTracker::init_cdata(easyar_MotionTracker * cdata)
{
    cdata_ = cdata;
}
inline bool MotionTracker::isAvailable()
{
    bool _return_value_ = easyar_MotionTracker_isAvailable();
    return _return_value_;
}
inline void MotionTracker::inputFrameSink(/* OUT */ InputFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSink * _return_value_ = NULL;
    easyar_MotionTracker_inputFrameSink(cdata_, &_return_value_);
    *Return = new InputFrameSink(_return_value_);
}
inline void MotionTracker::outputFrameSource(/* OUT */ OutputFrameSource * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OutputFrameSource * _return_value_ = NULL;
    easyar_MotionTracker_outputFrameSource(cdata_, &_return_value_);
    *Return = new OutputFrameSource(_return_value_);
}
inline void MotionTracker::create(/* OUT */ MotionTracker * * Return)
{
    easyar_MotionTracker * _return_value_ = NULL;
    easyar_MotionTracker_create(&_return_value_);
    *Return = new MotionTracker(_return_value_);
}
inline bool MotionTracker::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_MotionTracker_start(cdata_);
    return _return_value_;
}
inline void MotionTracker::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_MotionTracker_stop(cdata_);
}
inline void MotionTracker::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_MotionTracker_close(cdata_);
}

inline MotionTrackerOutputFrameToInputFrameAdapter::MotionTrackerOutputFrameToInputFrameAdapter(easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline MotionTrackerOutputFrameToInputFrameAdapter::~MotionTrackerOutputFrameToInputFrameAdapter()
{
    if (cdata_) {
        easyar_MotionTrackerOutputFrameToInputFrameAdapter__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline MotionTrackerOutputFrameToInputFrameAdapter::MotionTrackerOutputFrameToInputFrameAdapter(const MotionTrackerOutputFrameToInputFrameAdapter & data)
    :
    cdata_(NULL)
{
    easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata = NULL;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_MotionTrackerOutputFrameToInputFrameAdapter * MotionTrackerOutputFrameToInputFrameAdapter::get_cdata() const
{
    return cdata_;
}
inline easyar_MotionTrackerOutputFrameToInputFrameAdapter * MotionTrackerOutputFrameToInputFrameAdapter::get_cdata()
{
    return cdata_;
}
inline void MotionTrackerOutputFrameToInputFrameAdapter::init_cdata(easyar_MotionTrackerOutputFrameToInputFrameAdapter * cdata)
{
    cdata_ = cdata;
}
inline void MotionTrackerOutputFrameToInputFrameAdapter::input(/* OUT */ OutputFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OutputFrameSink * _return_value_ = NULL;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_input(cdata_, &_return_value_);
    *Return = new OutputFrameSink(_return_value_);
}
inline void MotionTrackerOutputFrameToInputFrameAdapter::output(/* OUT */ InputFrameSource * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSource * _return_value_ = NULL;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_output(cdata_, &_return_value_);
    *Return = new InputFrameSource(_return_value_);
}
inline void MotionTrackerOutputFrameToInputFrameAdapter::create(/* OUT */ MotionTrackerOutputFrameToInputFrameAdapter * * Return)
{
    easyar_MotionTrackerOutputFrameToInputFrameAdapter * _return_value_ = NULL;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_create(&_return_value_);
    *Return = new MotionTrackerOutputFrameToInputFrameAdapter(_return_value_);
}

}

#endif
