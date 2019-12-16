//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_OBJECTTARGET_HXX__
#define __EASYAR_OBJECTTARGET_HXX__

#include "easyar/types.hxx"
#include "easyar/target.hxx"

namespace easyar {

class ObjectTargetParameters
{
protected:
    easyar_ObjectTargetParameters * cdata_ ;
    void init_cdata(easyar_ObjectTargetParameters * cdata);
    virtual ObjectTargetParameters & operator=(const ObjectTargetParameters & data) { return *this; } //deleted
public:
    ObjectTargetParameters(easyar_ObjectTargetParameters * cdata);
    virtual ~ObjectTargetParameters();

    ObjectTargetParameters(const ObjectTargetParameters & data);
    const easyar_ObjectTargetParameters * get_cdata() const;
    easyar_ObjectTargetParameters * get_cdata();

    ObjectTargetParameters();
    void bufferDictionary(/* OUT */ BufferDictionary * * Return);
    void setBufferDictionary(BufferDictionary * bufferDictionary);
    void objPath(/* OUT */ String * * Return);
    void setObjPath(String * objPath);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void uid(/* OUT */ String * * Return);
    void setUid(String * uid);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * meta);
    float scale();
    void setScale(float size);
};

class ObjectTarget : public Target
{
protected:
    easyar_ObjectTarget * cdata_ ;
    void init_cdata(easyar_ObjectTarget * cdata);
    virtual ObjectTarget & operator=(const ObjectTarget & data) { return *this; } //deleted
public:
    ObjectTarget(easyar_ObjectTarget * cdata);
    virtual ~ObjectTarget();

    ObjectTarget(const ObjectTarget & data);
    const easyar_ObjectTarget * get_cdata() const;
    easyar_ObjectTarget * get_cdata();

    ObjectTarget();
    static void createFromParameters(ObjectTargetParameters * parameters, /* OUT */ ObjectTarget * * Return);
    static void createFromObjectFile(String * path, StorageType storageType, String * name, String * uid, String * meta, float scale, /* OUT */ ObjectTarget * * Return);
    static void setupAll(String * path, StorageType storageType, /* OUT */ ListOfObjectTarget * * Return);
    float scale();
    void boundingBox(/* OUT */ ListOfVec3F * * Return);
    bool setScale(float scale);
    int runtimeID();
    void uid(/* OUT */ String * * Return);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * data);
    static void tryCastFromTarget(Target * v, /* OUT */ ObjectTarget * * Return);
};

#ifndef __EASYAR_OPTIONALOFOBJECTTARGET__
#define __EASYAR_OPTIONALOFOBJECTTARGET__
struct OptionalOfObjectTarget
{
    bool has_value;
    ObjectTarget * value;
};
static inline easyar_OptionalOfObjectTarget OptionalOfObjectTarget_to_c(ObjectTarget * o);
#endif

#ifndef __EASYAR_LISTOFOBJECTTARGET__
#define __EASYAR_LISTOFOBJECTTARGET__
class ListOfObjectTarget
{
private:
    easyar_ListOfObjectTarget * cdata_;
    virtual ListOfObjectTarget & operator=(const ListOfObjectTarget & data) { return *this; } //deleted
public:
    ListOfObjectTarget(easyar_ListOfObjectTarget * cdata);
    virtual ~ListOfObjectTarget();

    ListOfObjectTarget(const ListOfObjectTarget & data);
    const easyar_ListOfObjectTarget * get_cdata() const;
    easyar_ListOfObjectTarget * get_cdata();

    ListOfObjectTarget(easyar_ObjectTarget * * begin, easyar_ObjectTarget * * end);
    int size() const;
    ObjectTarget * at(int index) const;
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

#ifndef __IMPLEMENTATION_EASYAR_OBJECTTARGET_HXX__
#define __IMPLEMENTATION_EASYAR_OBJECTTARGET_HXX__

#include "easyar/objecttarget.h"
#include "easyar/buffer.hxx"
#include "easyar/target.hxx"
#include "easyar/vector.hxx"

namespace easyar {

inline ObjectTargetParameters::ObjectTargetParameters(easyar_ObjectTargetParameters * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline ObjectTargetParameters::~ObjectTargetParameters()
{
    if (cdata_) {
        easyar_ObjectTargetParameters__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ObjectTargetParameters::ObjectTargetParameters(const ObjectTargetParameters & data)
    :
    cdata_(NULL)
{
    easyar_ObjectTargetParameters * cdata = NULL;
    easyar_ObjectTargetParameters__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_ObjectTargetParameters * ObjectTargetParameters::get_cdata() const
{
    return cdata_;
}
inline easyar_ObjectTargetParameters * ObjectTargetParameters::get_cdata()
{
    return cdata_;
}
inline void ObjectTargetParameters::init_cdata(easyar_ObjectTargetParameters * cdata)
{
    cdata_ = cdata;
}
inline ObjectTargetParameters::ObjectTargetParameters()
    :
    cdata_(NULL)
{
    easyar_ObjectTargetParameters * _return_value_ = NULL;
    easyar_ObjectTargetParameters__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void ObjectTargetParameters::bufferDictionary(/* OUT */ BufferDictionary * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_BufferDictionary * _return_value_ = NULL;
    easyar_ObjectTargetParameters_bufferDictionary(cdata_, &_return_value_);
    *Return = new BufferDictionary(_return_value_);
}
inline void ObjectTargetParameters::setBufferDictionary(BufferDictionary * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setBufferDictionary(cdata_, arg0->get_cdata());
}
inline void ObjectTargetParameters::objPath(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTargetParameters_objPath(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTargetParameters::setObjPath(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setObjPath(cdata_, arg0->get_cdata());
}
inline void ObjectTargetParameters::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTargetParameters_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTargetParameters::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setName(cdata_, arg0->get_cdata());
}
inline void ObjectTargetParameters::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTargetParameters_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTargetParameters::setUid(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setUid(cdata_, arg0->get_cdata());
}
inline void ObjectTargetParameters::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTargetParameters_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTargetParameters::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setMeta(cdata_, arg0->get_cdata());
}
inline float ObjectTargetParameters::scale()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_ObjectTargetParameters_scale(cdata_);
    return _return_value_;
}
inline void ObjectTargetParameters::setScale(float arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTargetParameters_setScale(cdata_, arg0);
}

inline ObjectTarget::ObjectTarget(easyar_ObjectTarget * cdata)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline ObjectTarget::~ObjectTarget()
{
    if (cdata_) {
        easyar_ObjectTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ObjectTarget::ObjectTarget(const ObjectTarget & data)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_ObjectTarget * cdata = NULL;
    easyar_ObjectTarget__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_ObjectTarget * ObjectTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ObjectTarget * ObjectTarget::get_cdata()
{
    return cdata_;
}
inline void ObjectTarget::init_cdata(easyar_ObjectTarget * cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * cdata_inner = NULL;
        easyar_castObjectTargetToTarget(cdata, &cdata_inner);
        Target::init_cdata(cdata_inner);
    }
}
inline ObjectTarget::ObjectTarget()
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_ObjectTarget * _return_value_ = NULL;
    easyar_ObjectTarget__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void ObjectTarget::createFromParameters(ObjectTargetParameters * arg0, /* OUT */ ObjectTarget * * Return)
{
    easyar_OptionalOfObjectTarget _return_value_ = {false, NULL};
    easyar_ObjectTarget_createFromParameters(arg0->get_cdata(), &_return_value_);
    *Return = (_return_value_.has_value ? new ObjectTarget(_return_value_.value) : NULL);
}
inline void ObjectTarget::createFromObjectFile(String * arg0, StorageType arg1, String * arg2, String * arg3, String * arg4, float arg5, /* OUT */ ObjectTarget * * Return)
{
    easyar_OptionalOfObjectTarget _return_value_ = {false, NULL};
    easyar_ObjectTarget_createFromObjectFile(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), arg2->get_cdata(), arg3->get_cdata(), arg4->get_cdata(), arg5, &_return_value_);
    *Return = (_return_value_.has_value ? new ObjectTarget(_return_value_.value) : NULL);
}
inline void ObjectTarget::setupAll(String * arg0, StorageType arg1, /* OUT */ ListOfObjectTarget * * Return)
{
    easyar_ListOfObjectTarget * _return_value_ = NULL;
    easyar_ObjectTarget_setupAll(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    *Return = new ListOfObjectTarget(_return_value_);
}
inline float ObjectTarget::scale()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_ObjectTarget_scale(cdata_);
    return _return_value_;
}
inline void ObjectTarget::boundingBox(/* OUT */ ListOfVec3F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfVec3F * _return_value_ = NULL;
    easyar_ObjectTarget_boundingBox(cdata_, &_return_value_);
    *Return = new ListOfVec3F(_return_value_);
}
inline bool ObjectTarget::setScale(float arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_ObjectTarget_setScale(cdata_, arg0);
    return _return_value_;
}
inline int ObjectTarget::runtimeID()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_ObjectTarget_runtimeID(cdata_);
    return _return_value_;
}
inline void ObjectTarget::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTarget_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTarget::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTarget_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTarget::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTarget_setName(cdata_, arg0->get_cdata());
}
inline void ObjectTarget::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ObjectTarget_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ObjectTarget::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ObjectTarget_setMeta(cdata_, arg0->get_cdata());
}
inline void ObjectTarget::tryCastFromTarget(Target * v, /* OUT */ ObjectTarget * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ObjectTarget * cdata = NULL;
    easyar_tryCastTargetToObjectTarget(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new ObjectTarget(cdata);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFOBJECTTARGET__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFOBJECTTARGET__
static inline easyar_OptionalOfObjectTarget OptionalOfObjectTarget_to_c(ObjectTarget * o)
{
    if (o != NULL) {
        easyar_OptionalOfObjectTarget _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfObjectTarget _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFOBJECTTARGET__
#define __IMPLEMENTATION_EASYAR_LISTOFOBJECTTARGET__
inline ListOfObjectTarget::ListOfObjectTarget(easyar_ListOfObjectTarget * cdata)
    : cdata_(cdata)
{
}
inline ListOfObjectTarget::~ListOfObjectTarget()
{
    if (cdata_) {
        easyar_ListOfObjectTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfObjectTarget::ListOfObjectTarget(const ListOfObjectTarget & data)
    : cdata_(static_cast<easyar_ListOfObjectTarget *>(NULL))
{
    easyar_ListOfObjectTarget_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfObjectTarget * ListOfObjectTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfObjectTarget * ListOfObjectTarget::get_cdata()
{
    return cdata_;
}

inline ListOfObjectTarget::ListOfObjectTarget(easyar_ObjectTarget * * begin, easyar_ObjectTarget * * end)
    : cdata_(static_cast<easyar_ListOfObjectTarget *>(NULL))
{
    easyar_ListOfObjectTarget__ctor(begin, end, &cdata_);
}
inline int ListOfObjectTarget::size() const
{
    return easyar_ListOfObjectTarget_size(cdata_);
}
inline ObjectTarget * ListOfObjectTarget::at(int index) const
{
    easyar_ObjectTarget * _return_value_ = easyar_ListOfObjectTarget_at(cdata_, index);
    easyar_ObjectTarget__retain(_return_value_, &_return_value_);
    return new ObjectTarget(_return_value_);
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
