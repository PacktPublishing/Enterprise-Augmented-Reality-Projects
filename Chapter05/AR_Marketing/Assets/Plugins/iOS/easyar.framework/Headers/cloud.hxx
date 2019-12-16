//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CLOUD_HXX__
#define __EASYAR_CLOUD_HXX__

#include "easyar/types.hxx"

namespace easyar {

class CloudRecognizer
{
protected:
    easyar_CloudRecognizer * cdata_ ;
    void init_cdata(easyar_CloudRecognizer * cdata);
    virtual CloudRecognizer & operator=(const CloudRecognizer & data) { return *this; } //deleted
public:
    CloudRecognizer(easyar_CloudRecognizer * cdata);
    virtual ~CloudRecognizer();

    CloudRecognizer(const CloudRecognizer & data);
    const easyar_CloudRecognizer * get_cdata() const;
    easyar_CloudRecognizer * get_cdata();

    static bool isAvailable();
    void inputFrameSink(/* OUT */ InputFrameSink * * Return);
    static void create(String * server, String * appKey, String * appSecret, CallbackScheduler * callbackScheduler, OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget callback, /* OUT */ CloudRecognizer * * Return);
    bool start();
    void stop();
    void close();
};

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

#ifndef __EASYAR_FUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
#define __EASYAR_FUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
struct FunctorOfVoidFromCloudStatusAndListOfTarget
{
    void * _state;
    void (* func)(void * _state, CloudStatus, ListOfTarget *);
    void (* destroy)(void * _state);
    FunctorOfVoidFromCloudStatusAndListOfTarget(void * _state, void (* func)(void * _state, CloudStatus, ListOfTarget *), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromCloudStatusAndListOfTarget_func(void * _state, easyar_CloudStatus, easyar_ListOfTarget *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCloudStatusAndListOfTarget_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCloudStatusAndListOfTarget FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(FunctorOfVoidFromCloudStatusAndListOfTarget f);
#endif

#ifndef __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
#define __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
struct OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget
{
    bool has_value;
    FunctorOfVoidFromCloudStatusAndListOfTarget value;
};
static inline easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget_to_c(OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget o);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CLOUD_HXX__
#define __IMPLEMENTATION_EASYAR_CLOUD_HXX__

#include "easyar/cloud.h"
#include "easyar/dataflow.hxx"
#include "easyar/frame.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/matrix.hxx"
#include "easyar/callbackscheduler.hxx"
#include "easyar/target.hxx"

namespace easyar {

inline CloudRecognizer::CloudRecognizer(easyar_CloudRecognizer * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CloudRecognizer::~CloudRecognizer()
{
    if (cdata_) {
        easyar_CloudRecognizer__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CloudRecognizer::CloudRecognizer(const CloudRecognizer & data)
    :
    cdata_(NULL)
{
    easyar_CloudRecognizer * cdata = NULL;
    easyar_CloudRecognizer__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CloudRecognizer * CloudRecognizer::get_cdata() const
{
    return cdata_;
}
inline easyar_CloudRecognizer * CloudRecognizer::get_cdata()
{
    return cdata_;
}
inline void CloudRecognizer::init_cdata(easyar_CloudRecognizer * cdata)
{
    cdata_ = cdata;
}
inline bool CloudRecognizer::isAvailable()
{
    bool _return_value_ = easyar_CloudRecognizer_isAvailable();
    return _return_value_;
}
inline void CloudRecognizer::inputFrameSink(/* OUT */ InputFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSink * _return_value_ = NULL;
    easyar_CloudRecognizer_inputFrameSink(cdata_, &_return_value_);
    *Return = new InputFrameSink(_return_value_);
}
inline void CloudRecognizer::create(String * arg0, String * arg1, String * arg2, CallbackScheduler * arg3, OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget arg4, /* OUT */ CloudRecognizer * * Return)
{
    easyar_CloudRecognizer * _return_value_ = NULL;
    easyar_CloudRecognizer_create(arg0->get_cdata(), arg1->get_cdata(), arg2->get_cdata(), arg3->get_cdata(), OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget_to_c(arg4), &_return_value_);
    *Return = new CloudRecognizer(_return_value_);
}
inline bool CloudRecognizer::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CloudRecognizer_start(cdata_);
    return _return_value_;
}
inline void CloudRecognizer::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CloudRecognizer_stop(cdata_);
}
inline void CloudRecognizer::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CloudRecognizer_close(cdata_);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
static inline easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget_to_c(OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget o)
{
    if (o.has_value) {
        easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget _return_value_ = {true, FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(o.value)};
        return _return_value_;
    } else {
        easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget _return_value_ = {false, {NULL, NULL, NULL}};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCLOUDSTATUSANDLISTOFTARGET__
inline FunctorOfVoidFromCloudStatusAndListOfTarget::FunctorOfVoidFromCloudStatusAndListOfTarget(void * _state, void (* func)(void * _state, CloudStatus, ListOfTarget *), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromCloudStatusAndListOfTarget_func(void * _state, easyar_CloudStatus arg0, easyar_ListOfTarget * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        CloudStatus cpparg0 = static_cast<CloudStatus>(arg0);
        easyar_ListOfTarget_copy(arg1, &arg1);
        ListOfTarget * cpparg1 = new ListOfTarget(arg1);
        FunctorOfVoidFromCloudStatusAndListOfTarget * f = reinterpret_cast<FunctorOfVoidFromCloudStatusAndListOfTarget *>(_state);
        f->func(f->_state, cpparg0, cpparg1);
        delete cpparg1;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromCloudStatusAndListOfTarget_destroy(void * _state)
{
    FunctorOfVoidFromCloudStatusAndListOfTarget * f = reinterpret_cast<FunctorOfVoidFromCloudStatusAndListOfTarget *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromCloudStatusAndListOfTarget FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(FunctorOfVoidFromCloudStatusAndListOfTarget f)
{
    easyar_FunctorOfVoidFromCloudStatusAndListOfTarget _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromCloudStatusAndListOfTarget(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromCloudStatusAndListOfTarget_func;
    _return_value_.destroy = FunctorOfVoidFromCloudStatusAndListOfTarget_destroy;
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
