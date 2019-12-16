//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CADTRACKER_HXX__
#define __EASYAR_CADTRACKER_HXX__

#include "easyar/types.hxx"
#include "easyar/target.hxx"

namespace easyar {

class CADTrackerResult : public TargetTrackerResult
{
protected:
    easyar_CADTrackerResult * cdata_ ;
    void init_cdata(easyar_CADTrackerResult * cdata);
    virtual CADTrackerResult & operator=(const CADTrackerResult & data) { return *this; } //deleted
public:
    CADTrackerResult(easyar_CADTrackerResult * cdata);
    virtual ~CADTrackerResult();

    CADTrackerResult(const CADTrackerResult & data);
    const easyar_CADTrackerResult * get_cdata() const;
    easyar_CADTrackerResult * get_cdata();

    void targetInstances(/* OUT */ ListOfTargetInstance * * Return);
    void setTargetInstances(ListOfTargetInstance * instances);
    static void tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ CADTrackerResult * * Return);
    static void tryCastFromTargetTrackerResult(TargetTrackerResult * v, /* OUT */ CADTrackerResult * * Return);
};

class CADTracker
{
protected:
    easyar_CADTracker * cdata_ ;
    void init_cdata(easyar_CADTracker * cdata);
    virtual CADTracker & operator=(const CADTracker & data) { return *this; } //deleted
public:
    CADTracker(easyar_CADTracker * cdata);
    virtual ~CADTracker();

    CADTracker(const CADTracker & data);
    const easyar_CADTracker * get_cdata() const;
    easyar_CADTracker * get_cdata();

    static bool isAvailable();
    void feedbackFrameSink(/* OUT */ FeedbackFrameSink * * Return);
    void outputFrameSource(/* OUT */ OutputFrameSource * * Return);
    static void create(/* OUT */ CADTracker * * Return);
    bool start();
    void stop();
    void close();
    void loadTarget(Target * target, CallbackScheduler * callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
    void unloadTarget(Target * target, CallbackScheduler * callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
    void targets(/* OUT */ ListOfTarget * * Return);
};

#ifndef __EASYAR_LISTOFTARGETINSTANCE__
#define __EASYAR_LISTOFTARGETINSTANCE__
class ListOfTargetInstance
{
private:
    easyar_ListOfTargetInstance * cdata_;
    virtual ListOfTargetInstance & operator=(const ListOfTargetInstance & data) { return *this; } //deleted
public:
    ListOfTargetInstance(easyar_ListOfTargetInstance * cdata);
    virtual ~ListOfTargetInstance();

    ListOfTargetInstance(const ListOfTargetInstance & data);
    const easyar_ListOfTargetInstance * get_cdata() const;
    easyar_ListOfTargetInstance * get_cdata();

    ListOfTargetInstance(easyar_TargetInstance * * begin, easyar_TargetInstance * * end);
    int size() const;
    TargetInstance * at(int index) const;
};
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMTARGETANDBOOL__
#define __EASYAR_FUNCTOROFVOIDFROMTARGETANDBOOL__
struct FunctorOfVoidFromTargetAndBool
{
    void * _state;
    void (* func)(void * _state, Target *, bool);
    void (* destroy)(void * _state);
    FunctorOfVoidFromTargetAndBool(void * _state, void (* func)(void * _state, Target *, bool), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target *, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(FunctorOfVoidFromTargetAndBool f);
#endif

#ifndef __EASYAR_LISTOFTARGET__
#define __EASYAR_LISTOFTARGET__
class ListOfTarget
{
private:
    easyar_ListOfTarget * cdata_;
    virtual ListOfTarget & operator=(const ListOfTarget & data) { return *this; } //deleted
public:
    ListOfTarget(easyar_ListOfTarget * cdata);
    virtual ~ListOfTarget();

    ListOfTarget(const ListOfTarget & data);
    const easyar_ListOfTarget * get_cdata() const;
    easyar_ListOfTarget * get_cdata();

    ListOfTarget(easyar_Target * * begin, easyar_Target * * end);
    int size() const;
    Target * at(int index) const;
};
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CADTRACKER_HXX__
#define __IMPLEMENTATION_EASYAR_CADTRACKER_HXX__

#include "easyar/cadtracker.h"
#include "easyar/target.hxx"
#include "easyar/frame.hxx"
#include "easyar/matrix.hxx"
#include "easyar/dataflow.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/callbackscheduler.hxx"

namespace easyar {

inline CADTrackerResult::CADTrackerResult(easyar_CADTrackerResult * cdata)
    :
    TargetTrackerResult(static_cast<easyar_TargetTrackerResult *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CADTrackerResult::~CADTrackerResult()
{
    if (cdata_) {
        easyar_CADTrackerResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CADTrackerResult::CADTrackerResult(const CADTrackerResult & data)
    :
    TargetTrackerResult(static_cast<easyar_TargetTrackerResult *>(NULL)),
    cdata_(NULL)
{
    easyar_CADTrackerResult * cdata = NULL;
    easyar_CADTrackerResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CADTrackerResult * CADTrackerResult::get_cdata() const
{
    return cdata_;
}
inline easyar_CADTrackerResult * CADTrackerResult::get_cdata()
{
    return cdata_;
}
inline void CADTrackerResult::init_cdata(easyar_CADTrackerResult * cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * cdata_inner = NULL;
        easyar_castCADTrackerResultToTargetTrackerResult(cdata, &cdata_inner);
        TargetTrackerResult::init_cdata(cdata_inner);
    }
}
inline void CADTrackerResult::targetInstances(/* OUT */ ListOfTargetInstance * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfTargetInstance * _return_value_ = NULL;
    easyar_CADTrackerResult_targetInstances(cdata_, &_return_value_);
    *Return = new ListOfTargetInstance(_return_value_);
}
inline void CADTrackerResult::setTargetInstances(ListOfTargetInstance * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTrackerResult_setTargetInstances(cdata_, arg0->get_cdata());
}
inline void CADTrackerResult::tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ CADTrackerResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CADTrackerResult * cdata = NULL;
    easyar_tryCastFrameFilterResultToCADTrackerResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new CADTrackerResult(cdata);
}
inline void CADTrackerResult::tryCastFromTargetTrackerResult(TargetTrackerResult * v, /* OUT */ CADTrackerResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CADTrackerResult * cdata = NULL;
    easyar_tryCastTargetTrackerResultToCADTrackerResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new CADTrackerResult(cdata);
}

inline CADTracker::CADTracker(easyar_CADTracker * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CADTracker::~CADTracker()
{
    if (cdata_) {
        easyar_CADTracker__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CADTracker::CADTracker(const CADTracker & data)
    :
    cdata_(NULL)
{
    easyar_CADTracker * cdata = NULL;
    easyar_CADTracker__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CADTracker * CADTracker::get_cdata() const
{
    return cdata_;
}
inline easyar_CADTracker * CADTracker::get_cdata()
{
    return cdata_;
}
inline void CADTracker::init_cdata(easyar_CADTracker * cdata)
{
    cdata_ = cdata;
}
inline bool CADTracker::isAvailable()
{
    bool _return_value_ = easyar_CADTracker_isAvailable();
    return _return_value_;
}
inline void CADTracker::feedbackFrameSink(/* OUT */ FeedbackFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_FeedbackFrameSink * _return_value_ = NULL;
    easyar_CADTracker_feedbackFrameSink(cdata_, &_return_value_);
    *Return = new FeedbackFrameSink(_return_value_);
}
inline void CADTracker::outputFrameSource(/* OUT */ OutputFrameSource * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OutputFrameSource * _return_value_ = NULL;
    easyar_CADTracker_outputFrameSource(cdata_, &_return_value_);
    *Return = new OutputFrameSource(_return_value_);
}
inline void CADTracker::create(/* OUT */ CADTracker * * Return)
{
    easyar_CADTracker * _return_value_ = NULL;
    easyar_CADTracker_create(&_return_value_);
    *Return = new CADTracker(_return_value_);
}
inline bool CADTracker::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CADTracker_start(cdata_);
    return _return_value_;
}
inline void CADTracker::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTracker_stop(cdata_);
}
inline void CADTracker::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTracker_close(cdata_);
}
inline void CADTracker::loadTarget(Target * arg0, CallbackScheduler * arg1, FunctorOfVoidFromTargetAndBool arg2)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTracker_loadTarget(cdata_, arg0->get_cdata(), arg1->get_cdata(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
inline void CADTracker::unloadTarget(Target * arg0, CallbackScheduler * arg1, FunctorOfVoidFromTargetAndBool arg2)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTracker_unloadTarget(cdata_, arg0->get_cdata(), arg1->get_cdata(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
inline void CADTracker::targets(/* OUT */ ListOfTarget * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfTarget * _return_value_ = NULL;
    easyar_CADTracker_targets(cdata_, &_return_value_);
    *Return = new ListOfTarget(_return_value_);
}

#ifndef __IMPLEMENTATION_EASYAR_LISTOFTARGETINSTANCE__
#define __IMPLEMENTATION_EASYAR_LISTOFTARGETINSTANCE__
inline ListOfTargetInstance::ListOfTargetInstance(easyar_ListOfTargetInstance * cdata)
    : cdata_(cdata)
{
}
inline ListOfTargetInstance::~ListOfTargetInstance()
{
    if (cdata_) {
        easyar_ListOfTargetInstance__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfTargetInstance::ListOfTargetInstance(const ListOfTargetInstance & data)
    : cdata_(static_cast<easyar_ListOfTargetInstance *>(NULL))
{
    easyar_ListOfTargetInstance_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfTargetInstance * ListOfTargetInstance::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfTargetInstance * ListOfTargetInstance::get_cdata()
{
    return cdata_;
}

inline ListOfTargetInstance::ListOfTargetInstance(easyar_TargetInstance * * begin, easyar_TargetInstance * * end)
    : cdata_(static_cast<easyar_ListOfTargetInstance *>(NULL))
{
    easyar_ListOfTargetInstance__ctor(begin, end, &cdata_);
}
inline int ListOfTargetInstance::size() const
{
    return easyar_ListOfTargetInstance_size(cdata_);
}
inline TargetInstance * ListOfTargetInstance::at(int index) const
{
    easyar_TargetInstance * _return_value_ = easyar_ListOfTargetInstance_at(cdata_, index);
    easyar_TargetInstance__retain(_return_value_, &_return_value_);
    return new TargetInstance(_return_value_);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMTARGETANDBOOL__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMTARGETANDBOOL__
inline FunctorOfVoidFromTargetAndBool::FunctorOfVoidFromTargetAndBool(void * _state, void (* func)(void * _state, Target *, bool), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target * arg0, bool arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        easyar_Target__retain(arg0, &arg0);
        Target * cpparg0 = new Target(arg0);
        bool cpparg1 = arg1;
        FunctorOfVoidFromTargetAndBool * f = reinterpret_cast<FunctorOfVoidFromTargetAndBool *>(_state);
        f->func(f->_state, cpparg0, cpparg1);
        delete cpparg0;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state)
{
    FunctorOfVoidFromTargetAndBool * f = reinterpret_cast<FunctorOfVoidFromTargetAndBool *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(FunctorOfVoidFromTargetAndBool f)
{
    easyar_FunctorOfVoidFromTargetAndBool _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromTargetAndBool(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromTargetAndBool_func;
    _return_value_.destroy = FunctorOfVoidFromTargetAndBool_destroy;
    return _return_value_;
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFTARGET__
#define __IMPLEMENTATION_EASYAR_LISTOFTARGET__
inline ListOfTarget::ListOfTarget(easyar_ListOfTarget * cdata)
    : cdata_(cdata)
{
}
inline ListOfTarget::~ListOfTarget()
{
    if (cdata_) {
        easyar_ListOfTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfTarget::ListOfTarget(const ListOfTarget & data)
    : cdata_(static_cast<easyar_ListOfTarget *>(NULL))
{
    easyar_ListOfTarget_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfTarget * ListOfTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfTarget * ListOfTarget::get_cdata()
{
    return cdata_;
}

inline ListOfTarget::ListOfTarget(easyar_Target * * begin, easyar_Target * * end)
    : cdata_(static_cast<easyar_ListOfTarget *>(NULL))
{
    easyar_ListOfTarget__ctor(begin, end, &cdata_);
}
inline int ListOfTarget::size() const
{
    return easyar_ListOfTarget_size(cdata_);
}
inline Target * ListOfTarget::at(int index) const
{
    easyar_Target * _return_value_ = easyar_ListOfTarget_at(cdata_, index);
    easyar_Target__retain(_return_value_, &_return_value_);
    return new Target(_return_value_);
}
#endif

}

#endif
