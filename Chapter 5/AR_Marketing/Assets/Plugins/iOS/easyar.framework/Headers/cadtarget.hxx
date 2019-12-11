//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CADTARGET_HXX__
#define __EASYAR_CADTARGET_HXX__

#include "easyar/types.hxx"
#include "easyar/target.hxx"

namespace easyar {

class CADTarget : public Target
{
protected:
    easyar_CADTarget * cdata_ ;
    void init_cdata(easyar_CADTarget * cdata);
    virtual CADTarget & operator=(const CADTarget & data) { return *this; } //deleted
public:
    CADTarget(easyar_CADTarget * cdata);
    virtual ~CADTarget();

    CADTarget(const CADTarget & data);
    const easyar_CADTarget * get_cdata() const;
    easyar_CADTarget * get_cdata();

    CADTarget();
    static void createFromUnity(Buffer * vertices, Buffer * faces, Matrix44F transform, float localScale, /* OUT */ CADTarget * * Return);
    void updateTransform(Matrix44F transform, float localScale);
    void updateTrackConfig(float threshContrast, float threshConsist, float threshQuality);
    static void createFromObjectFile(String * path, StorageType storageType, String * name, String * uid, String * meta, float scale, /* OUT */ CADTarget * * Return);
    static void setupAll(String * path, StorageType storageType, /* OUT */ ListOfCADTarget * * Return);
    float scale();
    void boundingBox(/* OUT */ ListOfVec3F * * Return);
    void boundingBoxGL(/* OUT */ ListOfVec3F * * Return);
    bool setScale(float scale);
    int runtimeID();
    void uid(/* OUT */ String * * Return);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * data);
    static void tryCastFromTarget(Target * v, /* OUT */ CADTarget * * Return);
};

#ifndef __EASYAR_OPTIONALOFCADTARGET__
#define __EASYAR_OPTIONALOFCADTARGET__
struct OptionalOfCADTarget
{
    bool has_value;
    CADTarget * value;
};
static inline easyar_OptionalOfCADTarget OptionalOfCADTarget_to_c(CADTarget * o);
#endif

#ifndef __EASYAR_LISTOFCADTARGET__
#define __EASYAR_LISTOFCADTARGET__
class ListOfCADTarget
{
private:
    easyar_ListOfCADTarget * cdata_;
    virtual ListOfCADTarget & operator=(const ListOfCADTarget & data) { return *this; } //deleted
public:
    ListOfCADTarget(easyar_ListOfCADTarget * cdata);
    virtual ~ListOfCADTarget();

    ListOfCADTarget(const ListOfCADTarget & data);
    const easyar_ListOfCADTarget * get_cdata() const;
    easyar_ListOfCADTarget * get_cdata();

    ListOfCADTarget(easyar_CADTarget * * begin, easyar_CADTarget * * end);
    int size() const;
    CADTarget * at(int index) const;
};
#endif

#ifndef __EASYAR_LISTOFVEC_F__
#define __EASYAR_LISTOFVEC_F__
class ListOfVec3F
{
private:
    easyar_ListOfVec3F * cdata_;
    virtual ListOfVec3F & operator=(const ListOfVec3F & data) { return *this; } //deleted
public:
    ListOfVec3F(easyar_ListOfVec3F * cdata);
    virtual ~ListOfVec3F();

    ListOfVec3F(const ListOfVec3F & data);
    const easyar_ListOfVec3F * get_cdata() const;
    easyar_ListOfVec3F * get_cdata();

    ListOfVec3F(easyar_Vec3F * begin, easyar_Vec3F * end);
    int size() const;
    Vec3F at(int index) const;
};
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CADTARGET_HXX__
#define __IMPLEMENTATION_EASYAR_CADTARGET_HXX__

#include "easyar/cadtarget.h"
#include "easyar/target.hxx"
#include "easyar/buffer.hxx"
#include "easyar/matrix.hxx"
#include "easyar/vector.hxx"

namespace easyar {

inline CADTarget::CADTarget(easyar_CADTarget * cdata)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CADTarget::~CADTarget()
{
    if (cdata_) {
        easyar_CADTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CADTarget::CADTarget(const CADTarget & data)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_CADTarget * cdata = NULL;
    easyar_CADTarget__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CADTarget * CADTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_CADTarget * CADTarget::get_cdata()
{
    return cdata_;
}
inline void CADTarget::init_cdata(easyar_CADTarget * cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * cdata_inner = NULL;
        easyar_castCADTargetToTarget(cdata, &cdata_inner);
        Target::init_cdata(cdata_inner);
    }
}
inline CADTarget::CADTarget()
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_CADTarget * _return_value_ = NULL;
    easyar_CADTarget__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void CADTarget::createFromUnity(Buffer * arg0, Buffer * arg1, Matrix44F arg2, float arg3, /* OUT */ CADTarget * * Return)
{
    easyar_OptionalOfCADTarget _return_value_ = {false, NULL};
    easyar_CADTarget_createFromUnity(arg0->get_cdata(), arg1->get_cdata(), arg2.get_cdata(), arg3, &_return_value_);
    *Return = (_return_value_.has_value ? new CADTarget(_return_value_.value) : NULL);
}
inline void CADTarget::updateTransform(Matrix44F arg0, float arg1)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTarget_updateTransform(cdata_, arg0.get_cdata(), arg1);
}
inline void CADTarget::updateTrackConfig(float arg0, float arg1, float arg2)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTarget_updateTrackConfig(cdata_, arg0, arg1, arg2);
}
inline void CADTarget::createFromObjectFile(String * arg0, StorageType arg1, String * arg2, String * arg3, String * arg4, float arg5, /* OUT */ CADTarget * * Return)
{
    easyar_OptionalOfCADTarget _return_value_ = {false, NULL};
    easyar_CADTarget_createFromObjectFile(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), arg2->get_cdata(), arg3->get_cdata(), arg4->get_cdata(), arg5, &_return_value_);
    *Return = (_return_value_.has_value ? new CADTarget(_return_value_.value) : NULL);
}
inline void CADTarget::setupAll(String * arg0, StorageType arg1, /* OUT */ ListOfCADTarget * * Return)
{
    easyar_ListOfCADTarget * _return_value_ = NULL;
    easyar_CADTarget_setupAll(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    *Return = new ListOfCADTarget(_return_value_);
}
inline float CADTarget::scale()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_CADTarget_scale(cdata_);
    return _return_value_;
}
inline void CADTarget::boundingBox(/* OUT */ ListOfVec3F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfVec3F * _return_value_ = NULL;
    easyar_CADTarget_boundingBox(cdata_, &_return_value_);
    *Return = new ListOfVec3F(_return_value_);
}
inline void CADTarget::boundingBoxGL(/* OUT */ ListOfVec3F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfVec3F * _return_value_ = NULL;
    easyar_CADTarget_boundingBoxGL(cdata_, &_return_value_);
    *Return = new ListOfVec3F(_return_value_);
}
inline bool CADTarget::setScale(float arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_CADTarget_setScale(cdata_, arg0);
    return _return_value_;
}
inline int CADTarget::runtimeID()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_CADTarget_runtimeID(cdata_);
    return _return_value_;
}
inline void CADTarget::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CADTarget_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CADTarget::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CADTarget_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CADTarget::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTarget_setName(cdata_, arg0->get_cdata());
}
inline void CADTarget::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CADTarget_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CADTarget::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CADTarget_setMeta(cdata_, arg0->get_cdata());
}
inline void CADTarget::tryCastFromTarget(Target * v, /* OUT */ CADTarget * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CADTarget * cdata = NULL;
    easyar_tryCastTargetToCADTarget(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new CADTarget(cdata);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFCADTARGET__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFCADTARGET__
static inline easyar_OptionalOfCADTarget OptionalOfCADTarget_to_c(CADTarget * o)
{
    if (o != NULL) {
        easyar_OptionalOfCADTarget _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfCADTarget _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFCADTARGET__
#define __IMPLEMENTATION_EASYAR_LISTOFCADTARGET__
inline ListOfCADTarget::ListOfCADTarget(easyar_ListOfCADTarget * cdata)
    : cdata_(cdata)
{
}
inline ListOfCADTarget::~ListOfCADTarget()
{
    if (cdata_) {
        easyar_ListOfCADTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfCADTarget::ListOfCADTarget(const ListOfCADTarget & data)
    : cdata_(static_cast<easyar_ListOfCADTarget *>(NULL))
{
    easyar_ListOfCADTarget_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfCADTarget * ListOfCADTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfCADTarget * ListOfCADTarget::get_cdata()
{
    return cdata_;
}

inline ListOfCADTarget::ListOfCADTarget(easyar_CADTarget * * begin, easyar_CADTarget * * end)
    : cdata_(static_cast<easyar_ListOfCADTarget *>(NULL))
{
    easyar_ListOfCADTarget__ctor(begin, end, &cdata_);
}
inline int ListOfCADTarget::size() const
{
    return easyar_ListOfCADTarget_size(cdata_);
}
inline CADTarget * ListOfCADTarget::at(int index) const
{
    easyar_CADTarget * _return_value_ = easyar_ListOfCADTarget_at(cdata_, index);
    easyar_CADTarget__retain(_return_value_, &_return_value_);
    return new CADTarget(_return_value_);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFVEC_F__
#define __IMPLEMENTATION_EASYAR_LISTOFVEC_F__
inline ListOfVec3F::ListOfVec3F(easyar_ListOfVec3F * cdata)
    : cdata_(cdata)
{
}
inline ListOfVec3F::~ListOfVec3F()
{
    if (cdata_) {
        easyar_ListOfVec3F__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfVec3F::ListOfVec3F(const ListOfVec3F & data)
    : cdata_(static_cast<easyar_ListOfVec3F *>(NULL))
{
    easyar_ListOfVec3F_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfVec3F * ListOfVec3F::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfVec3F * ListOfVec3F::get_cdata()
{
    return cdata_;
}

inline ListOfVec3F::ListOfVec3F(easyar_Vec3F * begin, easyar_Vec3F * end)
    : cdata_(static_cast<easyar_ListOfVec3F *>(NULL))
{
    easyar_ListOfVec3F__ctor(begin, end, &cdata_);
}
inline int ListOfVec3F::size() const
{
    return easyar_ListOfVec3F_size(cdata_);
}
inline Vec3F ListOfVec3F::at(int index) const
{
    easyar_Vec3F _return_value_ = easyar_ListOfVec3F_at(cdata_, index);
    return Vec3F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2]);
}
#endif

}

#endif
