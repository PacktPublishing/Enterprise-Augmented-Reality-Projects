//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CAMERAPARAMETERS_HXX__
#define __EASYAR_CAMERAPARAMETERS_HXX__

#include "easyar/types.hxx"

namespace easyar {

class CameraParameters
{
protected:
    easyar_CameraParameters * cdata_ ;
    void init_cdata(easyar_CameraParameters * cdata);
    virtual CameraParameters & operator=(const CameraParameters & data) { return *this; } //deleted
public:
    CameraParameters(easyar_CameraParameters * cdata);
    virtual ~CameraParameters();

    CameraParameters(const CameraParameters & data);
    const easyar_CameraParameters * get_cdata() const;
    easyar_CameraParameters * get_cdata();

    CameraParameters(Vec2I size, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation);
    Vec2I size();
    Vec2F focalLength();
    Vec2F principalPoint();
    CameraDeviceType cameraDeviceType();
    int cameraOrientation();
    static void createWithDefaultIntrinsics(Vec2I size, CameraDeviceType cameraDeviceType, int cameraOrientation, /* OUT */ CameraParameters * * Return);
    int imageOrientation(int screenRotation);
    bool imageHorizontalFlip(bool manualHorizontalFlip);
    Matrix44F projection(float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    Matrix44F imageProjection(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    Vec2F screenCoordinatesFromImageCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F imageCoordinates);
    Vec2F imageCoordinatesFromScreenCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F screenCoordinates);
    bool equalsTo(CameraParameters * other);
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CAMERAPARAMETERS_HXX__
#define __IMPLEMENTATION_EASYAR_CAMERAPARAMETERS_HXX__

#include "easyar/cameraparameters.h"
#include "easyar/vector.hxx"
#include "easyar/matrix.hxx"

namespace easyar {

inline CameraParameters::CameraParameters(easyar_CameraParameters * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CameraParameters::~CameraParameters()
{
    if (cdata_) {
        easyar_CameraParameters__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CameraParameters::CameraParameters(const CameraParameters & data)
    :
    cdata_(NULL)
{
    easyar_CameraParameters * cdata = NULL;
    easyar_CameraParameters__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CameraParameters * CameraParameters::get_cdata() const
{
    return cdata_;
}
inline easyar_CameraParameters * CameraParameters::get_cdata()
{
    return cdata_;
}
inline void CameraParameters::init_cdata(easyar_CameraParameters * cdata)
{
    cdata_ = cdata;
}
inline CameraParameters::CameraParameters(Vec2I arg0, Vec2F arg1, Vec2F arg2, CameraDeviceType arg3, int arg4)
    :
    cdata_(NULL)
{
    easyar_CameraParameters * _return_value_ = NULL;
    easyar_CameraParameters__ctor(arg0.get_cdata(), arg1.get_cdata(), arg2.get_cdata(), static_cast<easyar_CameraDeviceType>(arg3), arg4, &_return_value_);
    init_cdata(_return_value_);
}
inline Vec2I CameraParameters::size()
{
    if (cdata_ == NULL) {
        return Vec2I();
    }
    easyar_Vec2I _return_value_ = easyar_CameraParameters_size(cdata_);
    return Vec2I(_return_value_.data[0], _return_value_.data[1]);
}
inline Vec2F CameraParameters::focalLength()
{
    if (cdata_ == NULL) {
        return Vec2F();
    }
    easyar_Vec2F _return_value_ = easyar_CameraParameters_focalLength(cdata_);
    return Vec2F(_return_value_.data[0], _return_value_.data[1]);
}
inline Vec2F CameraParameters::principalPoint()
{
    if (cdata_ == NULL) {
        return Vec2F();
    }
    easyar_Vec2F _return_value_ = easyar_CameraParameters_principalPoint(cdata_);
    return Vec2F(_return_value_.data[0], _return_value_.data[1]);
}
inline CameraDeviceType CameraParameters::cameraDeviceType()
{
    if (cdata_ == NULL) {
        return CameraDeviceType();
    }
    easyar_CameraDeviceType _return_value_ = easyar_CameraParameters_cameraDeviceType(cdata_);
    return static_cast<CameraDeviceType>(_return_value_);
}
inline int CameraParameters::cameraOrientation()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraParameters_cameraOrientation(cdata_);
    return _return_value_;
}
inline void CameraParameters::createWithDefaultIntrinsics(Vec2I arg0, CameraDeviceType arg1, int arg2, /* OUT */ CameraParameters * * Return)
{
    easyar_CameraParameters * _return_value_ = NULL;
    easyar_CameraParameters_createWithDefaultIntrinsics(arg0.get_cdata(), static_cast<easyar_CameraDeviceType>(arg1), arg2, &_return_value_);
    *Return = new CameraParameters(_return_value_);
}
inline int CameraParameters::imageOrientation(int arg0)
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CameraParameters_imageOrientation(cdata_, arg0);
    return _return_value_;
}
inline bool CameraParameters::imageHorizontalFlip(bool arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraParameters_imageHorizontalFlip(cdata_, arg0);
    return _return_value_;
}
inline Matrix44F CameraParameters::projection(float arg0, float arg1, float arg2, int arg3, bool arg4, bool arg5)
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_CameraParameters_projection(cdata_, arg0, arg1, arg2, arg3, arg4, arg5);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline Matrix44F CameraParameters::imageProjection(float arg0, int arg1, bool arg2, bool arg3)
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_CameraParameters_imageProjection(cdata_, arg0, arg1, arg2, arg3);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline Vec2F CameraParameters::screenCoordinatesFromImageCoordinates(float arg0, int arg1, bool arg2, bool arg3, Vec2F arg4)
{
    if (cdata_ == NULL) {
        return Vec2F();
    }
    easyar_Vec2F _return_value_ = easyar_CameraParameters_screenCoordinatesFromImageCoordinates(cdata_, arg0, arg1, arg2, arg3, arg4.get_cdata());
    return Vec2F(_return_value_.data[0], _return_value_.data[1]);
}
inline Vec2F CameraParameters::imageCoordinatesFromScreenCoordinates(float arg0, int arg1, bool arg2, bool arg3, Vec2F arg4)
{
    if (cdata_ == NULL) {
        return Vec2F();
    }
    easyar_Vec2F _return_value_ = easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(cdata_, arg0, arg1, arg2, arg3, arg4.get_cdata());
    return Vec2F(_return_value_.data[0], _return_value_.data[1]);
}
inline bool CameraParameters::equalsTo(CameraParameters * arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CameraParameters_equalsTo(cdata_, arg0->get_cdata());
    return _return_value_;
}

}

#endif
