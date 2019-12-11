//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CAMERA_HXX__
#define __EASYAR_CAMERA_HXX__

#include "easyar/types.hxx"

namespace easyar {

class CameraDevice
{
protected:
    easyar_CameraDevice * cdata_ ;
    void init_cdata(easyar_CameraDevice * cdata);
    virtual CameraDevice & operator=(const CameraDevice & data) { return *this; } //deleted
public:
    CameraDevice(easyar_CameraDevice * cdata);
    virtual ~CameraDevice();

    CameraDevice(const CameraDevice & data);
    const easyar_CameraDevice * get_cdata() const;
    easyar_CameraDevice * get_cdata();

    CameraDevice();
    static bool isAvailable();
    AndroidCameraApiType androidCameraApiType();
    void setAndroidCameraApiType(AndroidCameraApiType type);
    int bufferCapacity();
    void setBufferCapacity(int capacity);
    void inputFrameSource(/* OUT */ InputFrameSource * * Return);
    void setStateChangedCallback(CallbackScheduler * callbackScheduler, OptionalOfFunctorOfVoidFromCameraState stateChangedCallback);
    static void requestPermissions(CallbackScheduler * callbackScheduler, OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
    bool openWithIndex(int cameraIndex);
    bool openWithType(CameraDeviceType type);
    bool start();
    void stop();
    void close();
    CameraDeviceType type();
    void cameraParameters(/* OUT */ CameraParameters * * Return);
    void setCameraParameters(CameraParameters * cameraParameters);
    Vec2I size();
    int supportedSizeCount();
    Vec2I supportedSize(int index);
    bool setSize(Vec2I size);
    int supportedFrameRateRangeCount();
    float supportedFrameRateRangeLower(int index);
    float supportedFrameRateRangeUpper(int index);
    int frameRateRange();
    bool setFrameRateRange(int index);
    bool setFlashTorchMode(bool on);
    bool setFocusMode(CameraDeviceFocusMode focusMode);
    bool autoFocus();
    bool setPresentProfile(CameraDevicePresetProfile profile);
};

class CameraDeviceSelector
{
public:
    static void createCameraDevice(CameraDevicePreference preference, /* OUT */ CameraDevice * * Return);
};

#ifndef __EASYAR_FUNCTOROFVOIDFROMCAMERASTATE__
#define __EASYAR_FUNCTOROFVOIDFROMCAMERASTATE__
struct FunctorOfVoidFromCameraState
{
    void * _state;
    void (* func)(void * _state, CameraState);
    void (* destroy)(void * _state);
    FunctorOfVoidFromCameraState(void * _state, void (* func)(void * _state, CameraState), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCameraState_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(FunctorOfVoidFromCameraState f);
#endif

#ifndef __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCAMERASTATE__
#define __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCAMERASTATE__
struct OptionalOfFunctorOfVoidFromCameraState
{
    bool has_value;
    FunctorOfVoidFromCameraState value;
};
static inline easyar_OptionalOfFunctorOfVoidFromCameraState OptionalOfFunctorOfVoidFromCameraState_to_c(OptionalOfFunctorOfVoidFromCameraState o);
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
#define __EASYAR_FUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
struct FunctorOfVoidFromPermissionStatusAndString
{
    void * _state;
    void (* func)(void * _state, PermissionStatus, String *);
    void (* destroy)(void * _state);
    FunctorOfVoidFromPermissionStatusAndString(void * _state, void (* func)(void * _state, PermissionStatus, String *), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(FunctorOfVoidFromPermissionStatusAndString f);
#endif

#ifndef __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
#define __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
struct OptionalOfFunctorOfVoidFromPermissionStatusAndString
{
    bool has_value;
    FunctorOfVoidFromPermissionStatusAndString value;
};
static inline easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString OptionalOfFunctorOfVoidFromPermissionStatusAndString_to_c(OptionalOfFunctorOfVoidFromPermissionStatusAndString o);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CAMERA_HXX__
#define __IMPLEMENTATION_EASYAR_CAMERA_HXX__

#include "easyar/camera.h"
#include "easyar/dataflow.hxx"
#include "easyar/frame.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/matrix.hxx"
#include "easyar/callbackscheduler.hxx"

namespace easyar {

inline CameraDevice::CameraDevice(easyar_CameraDevice * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CameraDevice::~CameraDevice()
{
    if (cdata_) {
        easyar_CameraDevice__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CameraDevice::CameraDevice(const CameraDevice & data)
    :
    cdata_(NULL)
{
    easyar_CameraDevice * cdata = NULL;
    easyar_CameraDevice__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CameraDevice * CameraDevice::get_cdata() const
{
    return cdata_;
}
inline easyar_CameraDevice * CameraDevice::get_cdata()
{
    return cdata_;
}
inline void CameraDevice::init_cdata(easyar_CameraDevice * cdata)
{
    cdata_ = cdata;
}
inline CameraDevice::CameraDevice()
    :
    cdata_(NULL)
{
    easyar_CameraDevice * _return_value_ = NULL;
    easyar_CameraDevice__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline bool CameraDevice::isAvailable()
{
    bool _return_value_ = easyar_CameraDevice_isAvailable();
    return _return_value_;
}
inline AndroidCameraApiType CameraDevice::androidCameraApiType()
{
    if (cdata_ == NULL) {
        return AndroidCameraApiType();
    }
    easyar_AndroidCameraApiType _return_value_ = easyar_CameraDevice_androidCameraApiType(cdata_);
    return static_cast<AndroidCameraApiType>(_return_value_);
}
inline void CameraDevice::setAndroidCameraApiType(AndroidCameraApiType arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_setAndroidCameraApiType(cdata_, static_cast<easyar_AndroidCameraApiType>(arg0));
}
inline int CameraDevice::bufferCapacity()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraDevice_bufferCapacity(cdata_);
    return _return_value_;
}
inline void CameraDevice::setBufferCapacity(int arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_setBufferCapacity(cdata_, arg0);
}
inline void CameraDevice::inputFrameSource(/* OUT */ InputFrameSource * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSource * _return_value_ = NULL;
    easyar_CameraDevice_inputFrameSource(cdata_, &_return_value_);
    *Return = new InputFrameSource(_return_value_);
}
inline void CameraDevice::setStateChangedCallback(CallbackScheduler * arg0, OptionalOfFunctorOfVoidFromCameraState arg1)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_setStateChangedCallback(cdata_, arg0->get_cdata(), OptionalOfFunctorOfVoidFromCameraState_to_c(arg1));
}
inline void CameraDevice::requestPermissions(CallbackScheduler * arg0, OptionalOfFunctorOfVoidFromPermissionStatusAndString arg1)
{
    easyar_CameraDevice_requestPermissions(arg0->get_cdata(), OptionalOfFunctorOfVoidFromPermissionStatusAndString_to_c(arg1));
}
inline bool CameraDevice::openWithIndex(int arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_openWithIndex(cdata_, arg0);
    return _return_value_;
}
inline bool CameraDevice::openWithType(CameraDeviceType arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_openWithType(cdata_, static_cast<easyar_CameraDeviceType>(arg0));
    return _return_value_;
}
inline bool CameraDevice::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_start(cdata_);
    return _return_value_;
}
inline void CameraDevice::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_stop(cdata_);
}
inline void CameraDevice::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_close(cdata_);
}
inline CameraDeviceType CameraDevice::type()
{
    if (cdata_ == NULL) {
        return CameraDeviceType();
    }
    easyar_CameraDeviceType _return_value_ = easyar_CameraDevice_type(cdata_);
    return static_cast<CameraDeviceType>(_return_value_);
}
inline void CameraDevice::cameraParameters(/* OUT */ CameraParameters * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CameraParameters * _return_value_ = NULL;
    easyar_CameraDevice_cameraParameters(cdata_, &_return_value_);
    *Return = new CameraParameters(_return_value_);
}
inline void CameraDevice::setCameraParameters(CameraParameters * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CameraDevice_setCameraParameters(cdata_, arg0->get_cdata());
}
inline Vec2I CameraDevice::size()
{
    if (cdata_ == NULL) {
        return Vec2I();
    }
    easyar_Vec2I _return_value_ = easyar_CameraDevice_size(cdata_);
    return Vec2I(_return_value_.data[0], _return_value_.data[1]);
}
inline int CameraDevice::supportedSizeCount()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraDevice_supportedSizeCount(cdata_);
    return _return_value_;
}
inline Vec2I CameraDevice::supportedSize(int arg0)
{
    if (cdata_ == NULL) {
        return Vec2I();
    }
    easyar_Vec2I _return_value_ = easyar_CameraDevice_supportedSize(cdata_, arg0);
    return Vec2I(_return_value_.data[0], _return_value_.data[1]);
}
inline bool CameraDevice::setSize(Vec2I arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_setSize(cdata_, arg0.get_cdata());
    return _return_value_;
}
inline int CameraDevice::supportedFrameRateRangeCount()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraDevice_supportedFrameRateRangeCount(cdata_);
    return _return_value_;
}
inline float CameraDevice::supportedFrameRateRangeLower(int arg0)
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_CameraDevice_supportedFrameRateRangeLower(cdata_, arg0);
    return _return_value_;
}
inline float CameraDevice::supportedFrameRateRangeUpper(int arg0)
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_CameraDevice_supportedFrameRateRangeUpper(cdata_, arg0);
    return _return_value_;
}
inline int CameraDevice::frameRateRange()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraDevice_frameRateRange(cdata_);
    return _return_value_;
}
inline bool CameraDevice::setFrameRateRange(int arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_setFrameRateRange(cdata_, arg0);
    return _return_value_;
}
inline bool CameraDevice::setFlashTorchMode(bool arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_setFlashTorchMode(cdata_, arg0);
    return _return_value_;
}
inline bool CameraDevice::setFocusMode(CameraDeviceFocusMode arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_setFocusMode(cdata_, static_cast<easyar_CameraDeviceFocusMode>(arg0));
    return _return_value_;
}
inline bool CameraDevice::autoFocus()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_autoFocus(cdata_);
    return _return_value_;
}
inline bool CameraDevice::setPresentProfile(CameraDevicePresetProfile arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraDevice_setPresentProfile(cdata_, static_cast<easyar_CameraDevicePresetProfile>(arg0));
    return _return_value_;
}

inline void CameraDeviceSelector::createCameraDevice(CameraDevicePreference arg0, /* OUT */ CameraDevice * * Return)
{
    easyar_CameraDevice * _return_value_ = NULL;
    easyar_CameraDeviceSelector_createCameraDevice(static_cast<easyar_CameraDevicePreference>(arg0), &_return_value_);
    *Return = new CameraDevice(_return_value_);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCAMERASTATE__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMCAMERASTATE__
static inline easyar_OptionalOfFunctorOfVoidFromCameraState OptionalOfFunctorOfVoidFromCameraState_to_c(OptionalOfFunctorOfVoidFromCameraState o)
{
    if (o.has_value) {
        easyar_OptionalOfFunctorOfVoidFromCameraState _return_value_ = {true, FunctorOfVoidFromCameraState_to_c(o.value)};
        return _return_value_;
    } else {
        easyar_OptionalOfFunctorOfVoidFromCameraState _return_value_ = {false, {NULL, NULL, NULL}};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCAMERASTATE__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCAMERASTATE__
inline FunctorOfVoidFromCameraState::FunctorOfVoidFromCameraState(void * _state, void (* func)(void * _state, CameraState), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        CameraState cpparg0 = static_cast<CameraState>(arg0);
        FunctorOfVoidFromCameraState * f = reinterpret_cast<FunctorOfVoidFromCameraState *>(_state);
        f->func(f->_state, cpparg0);
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromCameraState_destroy(void * _state)
{
    FunctorOfVoidFromCameraState * f = reinterpret_cast<FunctorOfVoidFromCameraState *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(FunctorOfVoidFromCameraState f)
{
    easyar_FunctorOfVoidFromCameraState _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromCameraState(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromCameraState_func;
    _return_value_.destroy = FunctorOfVoidFromCameraState_destroy;
    return _return_value_;
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
static inline easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString OptionalOfFunctorOfVoidFromPermissionStatusAndString_to_c(OptionalOfFunctorOfVoidFromPermissionStatusAndString o)
{
    if (o.has_value) {
        easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString _return_value_ = {true, FunctorOfVoidFromPermissionStatusAndString_to_c(o.value)};
        return _return_value_;
    } else {
        easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString _return_value_ = {false, {NULL, NULL, NULL}};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMPERMISSIONSTATUSANDSTRING__
inline FunctorOfVoidFromPermissionStatusAndString::FunctorOfVoidFromPermissionStatusAndString(void * _state, void (* func)(void * _state, PermissionStatus, String *), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        PermissionStatus cpparg0 = static_cast<PermissionStatus>(arg0);
        easyar_String_copy(arg1, &arg1);
        String * cpparg1 = new String(arg1);
        FunctorOfVoidFromPermissionStatusAndString * f = reinterpret_cast<FunctorOfVoidFromPermissionStatusAndString *>(_state);
        f->func(f->_state, cpparg0, cpparg1);
        delete cpparg1;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state)
{
    FunctorOfVoidFromPermissionStatusAndString * f = reinterpret_cast<FunctorOfVoidFromPermissionStatusAndString *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(FunctorOfVoidFromPermissionStatusAndString f)
{
    easyar_FunctorOfVoidFromPermissionStatusAndString _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromPermissionStatusAndString(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromPermissionStatusAndString_func;
    _return_value_.destroy = FunctorOfVoidFromPermissionStatusAndString_destroy;
    return _return_value_;
}
#endif

}

#endif
