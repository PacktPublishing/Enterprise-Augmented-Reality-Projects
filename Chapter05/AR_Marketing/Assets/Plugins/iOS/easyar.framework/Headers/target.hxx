//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_TARGET_HXX__
#define __EASYAR_TARGET_HXX__

#include "easyar/types.hxx"
#include "easyar/frame.hxx"

namespace easyar {

class Target
{
protected:
    easyar_Target * cdata_ ;
    void init_cdata(easyar_Target * cdata);
    virtual Target & operator=(const Target & data) { return *this; } //deleted
public:
    Target(easyar_Target * cdata);
    virtual ~Target();

    Target(const Target & data);
    const easyar_Target * get_cdata() const;
    easyar_Target * get_cdata();

    int runtimeID();
    void uid(/* OUT */ String * * Return);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * data);
};

class TargetInstance
{
protected:
    easyar_TargetInstance * cdata_ ;
    void init_cdata(easyar_TargetInstance * cdata);
    virtual TargetInstance & operator=(const TargetInstance & data) { return *this; } //deleted
public:
    TargetInstance(easyar_TargetInstance * cdata);
    virtual ~TargetInstance();

    TargetInstance(const TargetInstance & data);
    const easyar_TargetInstance * get_cdata() const;
    easyar_TargetInstance * get_cdata();

    TargetInstance();
    TargetStatus status();
    void target(/* OUT */ Target * * Return);
    Matrix44F pose();
};

class TargetTrackerResult : public FrameFilterResult
{
protected:
    easyar_TargetTrackerResult * cdata_ ;
    void init_cdata(easyar_TargetTrackerResult * cdata);
    virtual TargetTrackerResult & operator=(const TargetTrackerResult & data) { return *this; } //deleted
public:
    TargetTrackerResult(easyar_TargetTrackerResult * cdata);
    virtual ~TargetTrackerResult();

    TargetTrackerResult(const TargetTrackerResult & data);
    const easyar_TargetTrackerResult * get_cdata() const;
    easyar_TargetTrackerResult * get_cdata();

    void targetInstances(/* OUT */ ListOfTargetInstance * * Return);
    void setTargetInstances(ListOfTargetInstance * instances);
    static void tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ TargetTrackerResult * * Return);
};

#ifndef __EASYAR_OPTIONALOFTARGET__
#define __EASYAR_OPTIONALOFTARGET__
struct OptionalOfTarget
{
    bool has_value;
    Target * value;
};
static inline easyar_OptionalOfTarget OptionalOfTarget_to_c(Target * o);
#endif

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

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_TARGET_HXX__
#define __IMPLEMENTATION_EASYAR_TARGET_HXX__

#include "easyar/target.h"
#include "easyar/matrix.hxx"
#include "easyar/frame.hxx"

namespace easyar {

inline Target::Target(easyar_Target * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline Target::~Target()
{
    if (cdata_) {
        easyar_Target__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline Target::Target(const Target & data)
    :
    cdata_(NULL)
{
    easyar_Target * cdata = NULL;
    easyar_Target__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_Target * Target::get_cdata() const
{
    return cdata_;
}
inline easyar_Target * Target::get_cdata()
{
    return cdata_;
}
inline void Target::init_cdata(easyar_Target * cdata)
{
    cdata_ = cdata;
}
inline int Target::runtimeID()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_Target_runtimeID(cdata_);
    return _return_value_;
}
inline void Target::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_Target_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void Target::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_Target_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void Target::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_Target_setName(cdata_, arg0->get_cdata());
}
inline void Target::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_Target_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void Target::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_Target_setMeta(cdata_, arg0->get_cdata());
}

inline TargetInstance::TargetInstance(easyar_TargetInstance * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline TargetInstance::~TargetInstance()
{
    if (cdata_) {
        easyar_TargetInstance__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline TargetInstance::TargetInstance(const TargetInstance & data)
    :
    cdata_(NULL)
{
    easyar_TargetInstance * cdata = NULL;
    easyar_TargetInstance__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_TargetInstance * TargetInstance::get_cdata() const
{
    return cdata_;
}
inline easyar_TargetInstance * TargetInstance::get_cdata()
{
    return cdata_;
}
inline void TargetInstance::init_cdata(easyar_TargetInstance * cdata)
{
    cdata_ = cdata;
}
inline TargetInstance::TargetInstance()
    :
    cdata_(NULL)
{
    easyar_TargetInstance * _return_value_ = NULL;
    easyar_TargetInstance__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline TargetStatus TargetInstance::status()
{
    if (cdata_ == NULL) {
        return TargetStatus();
    }
    easyar_TargetStatus _return_value_ = easyar_TargetInstance_status(cdata_);
    return static_cast<TargetStatus>(_return_value_);
}
inline void TargetInstance::target(/* OUT */ Target * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OptionalOfTarget _return_value_ = {false, NULL};
    easyar_TargetInstance_target(cdata_, &_return_value_);
    *Return = (_return_value_.has_value ? new Target(_return_value_.value) : NULL);
}
inline Matrix44F TargetInstance::pose()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_TargetInstance_pose(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}

inline TargetTrackerResult::TargetTrackerResult(easyar_TargetTrackerResult * cdata)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline TargetTrackerResult::~TargetTrackerResult()
{
    if (cdata_) {
        easyar_TargetTrackerResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline TargetTrackerResult::TargetTrackerResult(const TargetTrackerResult & data)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    easyar_TargetTrackerResult * cdata = NULL;
    easyar_TargetTrackerResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_TargetTrackerResult * TargetTrackerResult::get_cdata() const
{
    return cdata_;
}
inline easyar_TargetTrackerResult * TargetTrackerResult::get_cdata()
{
    return cdata_;
}
inline void TargetTrackerResult::init_cdata(easyar_TargetTrackerResult * cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * cdata_inner = NULL;
        easyar_castTargetTrackerResultToFrameFilterResult(cdata, &cdata_inner);
        FrameFilterResult::init_cdata(cdata_inner);
    }
}
inline void TargetTrackerResult::targetInstances(/* OUT */ ListOfTargetInstance * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfTargetInstance * _return_value_ = NULL;
    easyar_TargetTrackerResult_targetInstances(cdata_, &_return_value_);
    *Return = new ListOfTargetInstance(_return_value_);
}
inline void TargetTrackerResult::setTargetInstances(ListOfTargetInstance * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_TargetTrackerResult_setTargetInstances(cdata_, arg0->get_cdata());
}
inline void TargetTrackerResult::tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ TargetTrackerResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_TargetTrackerResult * cdata = NULL;
    easyar_tryCastFrameFilterResultToTargetTrackerResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new TargetTrackerResult(cdata);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFTARGET__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFTARGET__
static inline easyar_OptionalOfTarget OptionalOfTarget_to_c(Target * o)
{
    if (o != NULL) {
        easyar_OptionalOfTarget _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfTarget _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

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

}

#endif
