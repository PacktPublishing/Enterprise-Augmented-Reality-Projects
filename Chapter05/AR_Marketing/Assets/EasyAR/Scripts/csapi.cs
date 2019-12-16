//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
#if ENABLE_IL2CPP
using AOT;
#endif

namespace easyar
{
    internal static partial class Detail
    {
#if UNITY_IOS && !UNITY_EDITOR
        public const String BindingLibraryName = "__Internal";
#else
        public const String BindingLibraryName = "EasyAR";
#endif
    }

    public struct Unit {}
    public enum OptionalTag
    {
        None = 0,
        Some = 1
    }
    public struct Optional<T>
    {
        public OptionalTag _Tag;

        public Unit None;
        public T Some;

        public static Optional<T> CreateNone() { return new Optional<T> { _Tag = OptionalTag.None, None = new Unit() }; }
        public static Optional<T> CreateSome(T Value) { return new Optional<T> { _Tag = OptionalTag.Some, Some = Value }; }

        public Boolean OnNone { get { return _Tag == OptionalTag.None; } }
        public Boolean OnSome { get { return _Tag == OptionalTag.Some; } }

        public static Optional<T> Empty { get { return CreateNone(); } }
        public static implicit operator Optional<T>(T v)
        {
            if (v == null)
            {
                return CreateNone();
            }
            else
            {
                return CreateSome(v);
            }
        }
        public static explicit operator T(Optional<T> v)
        {
            if (v.OnNone)
            {
                throw new InvalidOperationException();
            }
            return v.Some;
        }
        public static Boolean operator ==(Optional<T> Left, Optional<T> Right)
        {
            return Equals(Left, Right);
        }
        public static Boolean operator !=(Optional<T> Left, Optional<T> Right)
        {
            return !Equals(Left, Right);
        }
        public static Boolean operator ==(Optional<T>? Left, Optional<T>? Right)
        {
            return Equals(Left, Right);
        }
        public static Boolean operator !=(Optional<T>? Left, Optional<T>? Right)
        {
            return !Equals(Left, Right);
        }
        public override Boolean Equals(Object obj)
        {
            if (obj == null) { return Equals(this, null); }
            if (obj.GetType() != typeof(Optional<T>)) { return false; }
            var o = (Optional<T>)(obj);
            return Equals(this, o);
        }
        public override Int32 GetHashCode()
        {
            if (OnNone) { return 0; }
            return Some.GetHashCode();
        }

        private static Boolean Equals(Optional<T> Left, Optional<T> Right)
        {
            if (Left.OnNone && Right.OnNone)
            {
                return true;
            }
            if (Left.OnNone || Right.OnNone)
            {
                return false;
            }
            return Left.Some.Equals(Right.Some);
        }
        private static Boolean Equals(Optional<T>? Left, Optional<T>? Right)
        {
            if ((!Left.HasValue || Left.Value.OnNone) && (!Right.HasValue || Right.Value.OnNone))
            {
                return true;
            }
            if (!Left.HasValue || Left.Value.OnNone || !Right.HasValue || Right.Value.OnNone)
            {
                return false;
            }
            return Equals(Left.Value, Right.Value);
        }

        public T Value
        {
            get
            {
                if (OnSome)
                {
                    return Some;
                }
                else
                {
                    throw new InvalidOperationException();
                }
            }
        }
        public T ValueOrDefault(T Default)
        {
            if (OnSome)
            {
                return Some;
            }
            else
            {
                return Default;
            }
        }

        public override String ToString()
        {
            if (OnSome)
            {
                return Some.ToString();
            }
            else
            {
                return "-";
            }
        }
    }

    public abstract class RefBase : IDisposable
    {
        internal IntPtr cdata_;
        internal Action<IntPtr> deleter_;
        internal delegate void Retainer(IntPtr This, out IntPtr Return);
        internal Retainer retainer_;

        internal RefBase(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer)
        {
            cdata_ = cdata;
            deleter_ = deleter;
            retainer_ = retainer;
        }

        internal IntPtr cdata
        {
            get
            {
                if (cdata_ == IntPtr.Zero) { throw new ObjectDisposedException(GetType().FullName); }
                return cdata_;
            }
        }

        ~RefBase()
        {
            if ((cdata_ != IntPtr.Zero) && (deleter_ != null))
            {
                deleter_(cdata_);
                cdata_ = IntPtr.Zero;
                deleter_ = null;
                retainer_ = null;
            }
        }

        public void Dispose()
        {
            if ((cdata_ != IntPtr.Zero) && (deleter_ != null))
            {
                deleter_(cdata_);
                cdata_ = IntPtr.Zero;
                deleter_ = null;
                retainer_ = null;
            }
            GC.SuppressFinalize(this);
        }

        protected abstract object CloneObject();
        public RefBase Clone()
        {
            return (RefBase)(CloneObject());
        }
    }

    internal static partial class Detail
    {
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_String_from_utf8(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_String_from_utf8_begin(IntPtr begin, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_String_begin(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_String_end(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_String_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_String__dtor(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_bufferDictionary(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setBufferDictionary(IntPtr This, IntPtr bufferDictionary);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_objPath(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setObjPath(IntPtr This, IntPtr objPath);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setUid(IntPtr This, IntPtr uid);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setMeta(IntPtr This, IntPtr meta);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_ObjectTargetParameters_scale(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters_setScale(IntPtr This, float size);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTargetParameters__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ObjectTargetParameters__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_createFromParameters(IntPtr parameters, out OptionalOfObjectTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_createFromObjectFile(IntPtr path, StorageType storageType, IntPtr name, IntPtr uid, IntPtr meta, float scale, out OptionalOfObjectTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_setupAll(IntPtr path, StorageType storageType, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_ObjectTarget_scale(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_boundingBox(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ObjectTarget_setScale(IntPtr This, float scale);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ObjectTarget_runtimeID(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget_setMeta(IntPtr This, IntPtr data);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTarget__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ObjectTarget__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castObjectTargetToTarget(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetToObjectTarget(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTrackerResult_targetInstances(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTrackerResult_setTargetInstances(IntPtr This, IntPtr instances);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ObjectTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castObjectTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToObjectTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castObjectTrackerResultToTargetTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetTrackerResultToObjectTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ObjectTracker_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_feedbackFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ObjectTracker_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_loadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_unloadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker_targets(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ObjectTracker_setSimultaneousNum(IntPtr This, int num);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ObjectTracker_simultaneousNum(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ObjectTracker__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ObjectTracker__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_createFromUnity(IntPtr vertices, IntPtr faces, Matrix44F transform, float localScale, out OptionalOfCADTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_updateTransform(IntPtr This, Matrix44F transform, float localScale);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_updateTrackConfig(IntPtr This, float threshContrast, float threshConsist, float threshQuality);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_createFromObjectFile(IntPtr path, StorageType storageType, IntPtr name, IntPtr uid, IntPtr meta, float scale, out OptionalOfCADTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_setupAll(IntPtr path, StorageType storageType, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_CADTarget_scale(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_boundingBox(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_boundingBoxGL(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CADTarget_setScale(IntPtr This, float scale);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CADTarget_runtimeID(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget_setMeta(IntPtr This, IntPtr data);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTarget__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CADTarget__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castCADTargetToTarget(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetToCADTarget(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTrackerResult_targetInstances(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTrackerResult_setTargetInstances(IntPtr This, IntPtr instances);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CADTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castCADTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToCADTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castCADTrackerResultToTargetTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetTrackerResultToCADTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CADTracker_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_feedbackFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CADTracker_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_loadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_unloadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker_targets(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CADTracker__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CADTracker__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CloudRecognizer_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer_inputFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer_create(IntPtr server, IntPtr appKey, IntPtr appSecret, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget callback, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CloudRecognizer_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CloudRecognizer__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CloudRecognizer__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_DenseSpatialMap_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_inputFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_DenseSpatialMap_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_saveMap(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap_getMesh(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_DenseSpatialMap_updateSceneMesh(IntPtr This, [MarshalAs(UnmanagedType.I1)] bool updateMeshAll);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DenseSpatialMap__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_DenseSpatialMap__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_SceneMesh_getNumOfVertexAll(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_SceneMesh_getNumOfIndexAll(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getVerticesAll(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getNormalsAll(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getIndicesAll(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_SceneMesh_getNumOfVertexIncremental(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_SceneMesh_getNumOfIndexIncremental(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getVerticesIncremental(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getNormalsIncremental(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getIndicesIncremental(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh_getBlocksInfoIncremental(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_SceneMesh_getBlockDimentionInMeters(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SceneMesh__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SceneMesh__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_SurfaceTrackerResult_transform(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern SurfaceTrackingStatus easyar_SurfaceTrackerResult_status(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SurfaceTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castSurfaceTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToSurfaceTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SurfaceTracker_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_inputFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SurfaceTracker_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker_alignTargetToCameraImagePoint(IntPtr This, Vec2F cameraImagePoint);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SurfaceTracker__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SurfaceTracker__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_MotionTrackerResult_transform(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern MotionTrackingStatus easyar_MotionTrackerResult_status(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_MotionTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castMotionTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToMotionTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_MotionTracker_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker_inputFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_MotionTracker_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTracker__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_MotionTracker__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerOutputFrameToInputFrameAdapter_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerOutputFrameToInputFrameAdapter_output(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerOutputFrameToInputFrameAdapter_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerOutputFrameToInputFrameAdapter__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_MotionTrackerOutputFrameToInputFrameAdapter__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_MotionTrackerOutputFrameToInputFrameAdapter__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_image(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_setImage(IntPtr This, IntPtr image);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_setUid(IntPtr This, IntPtr uid);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_setMeta(IntPtr This, IntPtr meta);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_ImageTargetParameters_scale(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters_setScale(IntPtr This, float scale);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTargetParameters__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ImageTargetParameters__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_createFromParameters(IntPtr parameters, out OptionalOfImageTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_createFromTargetFile(IntPtr path, StorageType storageType, out OptionalOfImageTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_createFromTargetData(IntPtr buffer, out OptionalOfImageTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ImageTarget_save(IntPtr This, IntPtr path);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_createFromImageFile(IntPtr path, StorageType storageType, IntPtr name, IntPtr uid, IntPtr meta, float scale, out OptionalOfImageTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_setupAll(IntPtr path, StorageType storageType, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_ImageTarget_scale(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_ImageTarget_aspectRatio(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ImageTarget_setScale(IntPtr This, float scale);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_images(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ImageTarget_runtimeID(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget_setMeta(IntPtr This, IntPtr data);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTarget__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ImageTarget__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castImageTargetToTarget(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetToImageTarget(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTrackerResult_targetInstances(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTrackerResult_setTargetInstances(IntPtr This, IntPtr instances);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ImageTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castImageTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToImageTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castImageTrackerResultToTargetTrackerResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastTargetTrackerResultToImageTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ImageTracker_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_feedbackFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_createWithMode(ImageTrackerMode trackMode, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ImageTracker_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_loadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_unloadTarget(IntPtr This, IntPtr target, IntPtr callbackScheduler, FunctorOfVoidFromTargetAndBool callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker_targets(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_ImageTracker_setSimultaneousNum(IntPtr This, int num);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ImageTracker_simultaneousNum(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageTracker__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ImageTracker__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Recorder_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder_requestPermissions(IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder_create(IntPtr config, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromRecordStatusAndString statusCallback, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder_updateFrame(IntPtr This, IntPtr texture, int width, int height);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Recorder_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Recorder__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_Recorder__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setOutputFile(IntPtr This, IntPtr path);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_RecorderConfiguration_setProfile(IntPtr This, RecordProfile profile);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setVideoSize(IntPtr This, RecordVideoSize framesize);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setVideoBitrate(IntPtr This, int bitrate);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setChannelCount(IntPtr This, int count);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setAudioSampleRate(IntPtr This, int samplerate);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setAudioBitrate(IntPtr This, int bitrate);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setVideoOrientation(IntPtr This, RecordVideoOrientation mode);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration_setZoomMode(IntPtr This, RecordZoomMode mode);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_RecorderConfiguration__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_RecorderConfiguration__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern MapTrackingStatus easyar_SparseSpatialMapResult_getMapTrackingStatus(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_SparseSpatialMapResult_getVioPose(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_SparseSpatialMapResult_getMapPose(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMapResult_getLocalizedStatus(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapResult_getCurrentLocalizedMapID(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SparseSpatialMapResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castSparseSpatialMapResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToSparseSpatialMapResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_PlaneData__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern PlaneType easyar_PlaneData_getType(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_PlaneData_getPose(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_PlaneData_getExtentX(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_PlaneData_getExtentZ(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_PlaneData__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_PlaneData__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_PlaneData__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapConfig__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapConfig_setLocalizeConfig(IntPtr This, LocalizeConfig @value);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern LocalizeConfig easyar_SparseSpatialMapConfig_getLocalizeConfig(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapConfig_setMapConfig(IntPtr This, MapConfig @value);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern MapConfig easyar_SparseSpatialMapConfig_getMapConfig(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapConfig__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMapConfig__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SparseSpatialMapConfig__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_inputFrameSink(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_outputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_getPointCloudBuffer(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_getMapPlanes(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_hitTestAgainstPointCloud(IntPtr This, Vec2F cameraImagePoint, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_hitTestAgainstPlanes(IntPtr This, Vec2F cameraImagePoint, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_saveMap(IntPtr This, IntPtr callbackScheduler, FunctorOfVoidFromOptionalOfBuffer resultCallBack);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_loadMap(IntPtr This, IntPtr pMapData, IntPtr mapID, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromBool resultCallBack);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_unloadMap(IntPtr This, IntPtr mapID, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromBool resultCallBack);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_setConfig(IntPtr This, IntPtr config);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap_getConfig(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_startLocalize(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_SparseSpatialMap_stopLocalize(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SparseSpatialMap__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SparseSpatialMap__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImageHelper_decode(IntPtr buffer, out OptionalOfImage Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CallbackScheduler__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CallbackScheduler__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CallbackScheduler__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DelayedCallbackScheduler__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_DelayedCallbackScheduler_runOne(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DelayedCallbackScheduler__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_DelayedCallbackScheduler__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_DelayedCallbackScheduler__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castDelayedCallbackSchedulerToCallbackScheduler(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastCallbackSchedulerToDelayedCallbackScheduler(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImmediateCallbackScheduler_getDefault(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImmediateCallbackScheduler__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ImmediateCallbackScheduler__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ImmediateCallbackScheduler__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castImmediateCallbackSchedulerToCallbackScheduler(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastCallbackSchedulerToImmediateCallbackScheduler(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_isAvailable();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern AndroidCameraApiType easyar_CameraDevice_androidCameraApiType(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_setAndroidCameraApiType(IntPtr This, AndroidCameraApiType type);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraDevice_bufferCapacity(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_setBufferCapacity(IntPtr This, int capacity);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_inputFrameSource(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_setStateChangedCallback(IntPtr This, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromCameraState stateChangedCallback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_requestPermissions(IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_openWithIndex(IntPtr This, int cameraIndex);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_openWithType(IntPtr This, CameraDeviceType type);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_start(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern CameraDeviceType easyar_CameraDevice_type(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_cameraParameters(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice_setCameraParameters(IntPtr This, IntPtr cameraParameters);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2I easyar_CameraDevice_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraDevice_supportedSizeCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2I easyar_CameraDevice_supportedSize(IntPtr This, int index);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_setSize(IntPtr This, Vec2I size);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraDevice_supportedFrameRateRangeCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_CameraDevice_supportedFrameRateRangeLower(IntPtr This, int index);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_CameraDevice_supportedFrameRateRangeUpper(IntPtr This, int index);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraDevice_frameRateRange(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_setFrameRateRange(IntPtr This, int index);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_setFlashTorchMode(IntPtr This, [MarshalAs(UnmanagedType.I1)] bool on);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_setFocusMode(IntPtr This, CameraDeviceFocusMode focusMode);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_autoFocus(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraDevice_setPresentProfile(IntPtr This, CameraDevicePresetProfile profile);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDevice__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CameraDevice__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraDeviceSelector_createCameraDevice(CameraDevicePreference preference, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSink_handle(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSink__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSink__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SignalSink__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSource_setHandler(IntPtr This, OptionalOfFunctorOfVoid handler);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSource_connect(IntPtr This, IntPtr sink);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSource_disconnect(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSource__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_SignalSource__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_SignalSource__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSink_handle(IntPtr This, IntPtr inputData);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSink__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSink__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameSink__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSource_setHandler(IntPtr This, OptionalOfFunctorOfVoidFromInputFrame handler);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSource_connect(IntPtr This, IntPtr sink);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSource_disconnect(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSource__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameSource__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameSource__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSink_handle(IntPtr This, IntPtr inputData);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSink__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSink__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrameSink__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSource_setHandler(IntPtr This, OptionalOfFunctorOfVoidFromOutputFrame handler);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSource_connect(IntPtr This, IntPtr sink);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSource_disconnect(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSource__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameSource__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrameSource__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSink_handle(IntPtr This, IntPtr inputData);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSink__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSink__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_FeedbackFrameSink__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSource_setHandler(IntPtr This, OptionalOfFunctorOfVoidFromFeedbackFrame handler);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSource_connect(IntPtr This, IntPtr sink);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSource_disconnect(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSource__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameSource__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_FeedbackFrameSource__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameFork_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameFork_output(IntPtr This, int index, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_InputFrameFork_outputCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameFork_create(int outputCount, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameFork__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameFork__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameFork__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameFork_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameFork_output(IntPtr This, int index, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_OutputFrameFork_outputCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameFork_create(int outputCount, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameFork__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameFork__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrameFork__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin_input(IntPtr This, int index, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin_output(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_OutputFrameJoin_inputCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin_create(int inputCount, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin_createWithJoiner(int inputCount, FunctorOfOutputFrameFromListOfOutputFrame joiner, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameJoin__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrameJoin__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameFork_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameFork_output(IntPtr This, int index, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_FeedbackFrameFork_outputCount(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameFork_create(int outputCount, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameFork__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrameFork__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_FeedbackFrameFork__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler_output(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler_signalInput(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameThrottler__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameThrottler__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer_signalOutput(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer_peek(IntPtr This, out OptionalOfOutputFrame Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrameBuffer__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrameBuffer__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToOutputFrameAdapter_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToOutputFrameAdapter_output(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToOutputFrameAdapter_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToOutputFrameAdapter__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToOutputFrameAdapter__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameToOutputFrameAdapter__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter_input(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter_sideInput(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter_output(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter_create(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrameToFeedbackFrameAdapter__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrameToFeedbackFrameAdapter__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_Engine_schemaHash();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Engine_initialize(IntPtr key);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Engine_onPause();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Engine_onResume();
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Engine_errorMessage(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Engine_versionString(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Engine_name(out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_InputFrame_index(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_image(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_InputFrame_hasCameraParameters(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_cameraParameters(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_InputFrame_hasTemporalInformation(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern double easyar_InputFrame_timestamp(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_InputFrame_hasSpatialInformation(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_InputFrame_cameraTransform(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern InputFrameTrackingStatus easyar_InputFrame_trackingStatus(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_create(IntPtr image, IntPtr cameraParameters, double timestamp, Matrix44F cameraTransform, InputFrameTrackingStatus trackingStatus, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(IntPtr image, IntPtr cameraParameters, double timestamp, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_createWithImageAndCameraParameters(IntPtr image, IntPtr cameraParameters, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame_createWithImage(IntPtr image, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_InputFrame__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_InputFrame__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FrameFilterResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FrameFilterResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_FrameFilterResult__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrame__ctor(IntPtr inputFrame, IntPtr results, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_OutputFrame_index(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrame_inputFrame(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrame_results(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrame__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_OutputFrame__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_OutputFrame__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrame__ctor(IntPtr inputFrame, OptionalOfOutputFrame previousOutputFrame, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrame_inputFrame(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrame_previousOutputFrame(IntPtr This, out OptionalOfOutputFrame Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrame__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_FeedbackFrame__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_FeedbackFrame__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_Target_runtimeID(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target_uid(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target_name(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target_setName(IntPtr This, IntPtr name);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target_meta(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target_setMeta(IntPtr This, IntPtr data);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Target__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_Target__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetInstance__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern TargetStatus easyar_TargetInstance_status(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetInstance_target(IntPtr This, out OptionalOfTarget Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_TargetInstance_pose(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetInstance__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetInstance__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_TargetInstance__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetTrackerResult_targetInstances(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetTrackerResult_setTargetInstances(IntPtr This, IntPtr instances);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetTrackerResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TargetTrackerResult__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_TargetTrackerResult__typeName(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_castTargetTrackerResultToFrameFilterResult(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_tryCastFrameFilterResultToTargetTrackerResult(IntPtr This, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_TextureId_getInt(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_TextureId_getPointer(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TextureId_fromInt(int @value, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TextureId_fromPointer(IntPtr ptr, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TextureId__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_TextureId__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_TextureId__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_setVideoType(IntPtr This, VideoType videoType);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_setRenderTexture(IntPtr This, IntPtr texture);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_open(IntPtr This, IntPtr path, StorageType storageType, IntPtr callbackScheduler, OptionalOfFunctorOfVoidFromVideoStatus callback);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_close(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_VideoPlayer_play(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_stop(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_pause(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_VideoPlayer_isRenderTextureAvailable(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer_updateFrame(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_VideoPlayer_duration(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_VideoPlayer_currentPosition(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_VideoPlayer_seek(IntPtr This, int position);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2I easyar_VideoPlayer_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float easyar_VideoPlayer_volume(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_VideoPlayer_setVolume(IntPtr This, float volume);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_VideoPlayer__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_VideoPlayer__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer_wrap(IntPtr ptr, int size, FunctorOfVoid deleter, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer_create(int size, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_Buffer_data(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_Buffer_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer_memoryCopy(IntPtr src, IntPtr dest, int length);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Buffer_tryCopyFrom(IntPtr This, IntPtr src, int srcIndex, int index, int length);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Buffer_tryCopyTo(IntPtr This, int index, IntPtr dest, int destIndex, int length);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer_partition(IntPtr This, int index, int length, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Buffer__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_Buffer__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary__ctor(out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_BufferDictionary_count(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_BufferDictionary_contains(IntPtr This, IntPtr path);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary_tryGet(IntPtr This, IntPtr path, out OptionalOfBuffer Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary_set(IntPtr This, IntPtr path, IntPtr buffer);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_BufferDictionary_remove(IntPtr This, IntPtr path);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary_clear(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferDictionary__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_BufferDictionary__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferPool__ctor(int block_size, int capacity, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_BufferPool_block_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_BufferPool_capacity(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_BufferPool_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferPool_tryAcquire(IntPtr This, out OptionalOfBuffer Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferPool__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_BufferPool__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_BufferPool__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraParameters__ctor(Vec2I size, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2I easyar_CameraParameters_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2F easyar_CameraParameters_focalLength(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2F easyar_CameraParameters_principalPoint(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern CameraDeviceType easyar_CameraParameters_cameraDeviceType(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraParameters_cameraOrientation(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraParameters_createWithDefaultIntrinsics(Vec2I size, CameraDeviceType cameraDeviceType, int cameraOrientation, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_CameraParameters_imageOrientation(IntPtr This, int screenRotation);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraParameters_imageHorizontalFlip(IntPtr This, [MarshalAs(UnmanagedType.I1)] bool manualHorizontalFlip);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_CameraParameters_projection(IntPtr This, float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, [MarshalAs(UnmanagedType.I1)] bool combiningFlip, [MarshalAs(UnmanagedType.I1)] bool manualHorizontalFlip);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Matrix44F easyar_CameraParameters_imageProjection(IntPtr This, float viewportAspectRatio, int screenRotation, [MarshalAs(UnmanagedType.I1)] bool combiningFlip, [MarshalAs(UnmanagedType.I1)] bool manualHorizontalFlip);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2F easyar_CameraParameters_screenCoordinatesFromImageCoordinates(IntPtr This, float viewportAspectRatio, int screenRotation, [MarshalAs(UnmanagedType.I1)] bool combiningFlip, [MarshalAs(UnmanagedType.I1)] bool manualHorizontalFlip, Vec2F imageCoordinates);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec2F easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(IntPtr This, float viewportAspectRatio, int screenRotation, [MarshalAs(UnmanagedType.I1)] bool combiningFlip, [MarshalAs(UnmanagedType.I1)] bool manualHorizontalFlip, Vec2F screenCoordinates);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_CameraParameters_equalsTo(IntPtr This, IntPtr other);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraParameters__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_CameraParameters__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_CameraParameters__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Image__ctor(IntPtr buffer, PixelFormat format, int width, int height, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Image_buffer(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern PixelFormat easyar_Image_format(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_Image_width(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_Image_height(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool easyar_Image_empty(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Image__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Image__retain(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_Image__typeName(IntPtr This);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_JniUtility_wrapByteArray(IntPtr bytes, [MarshalAs(UnmanagedType.I1)] bool readOnly, FunctorOfVoid deleter, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_JniUtility_wrapBuffer(IntPtr directBuffer, FunctorOfVoid deleter, out IntPtr Return);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Log_setLogFunc(FunctorOfVoidFromLogLevelAndString func);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_Log_resetLogFunc();

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfObjectTarget__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfObjectTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfObjectTarget_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfObjectTarget_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfObjectTarget_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfVec3F__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfVec3F__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfVec3F_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfVec3F_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern Vec3F easyar_ListOfVec3F_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTargetInstance__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTargetInstance__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTargetInstance_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfTargetInstance_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfTargetInstance_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOptionalOfFrameFilterResult__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOptionalOfFrameFilterResult__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOptionalOfFrameFilterResult_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfOptionalOfFrameFilterResult_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern OptionalOfFrameFilterResult easyar_ListOfOptionalOfFrameFilterResult_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTarget__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfTarget_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfTarget_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfTarget_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfCADTarget__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfCADTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfCADTarget_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfCADTarget_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfCADTarget_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfBlockInfo__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfBlockInfo__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfBlockInfo_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfBlockInfo_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern BlockInfo easyar_ListOfBlockInfo_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImageTarget__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImageTarget__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImageTarget_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfImageTarget_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfImageTarget_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImage__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImage__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfImage_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfImage_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfImage_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfPlaneData__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfPlaneData__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfPlaneData_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfPlaneData_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfPlaneData_at(IntPtr This, int index);

        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOutputFrame__ctor(IntPtr begin, IntPtr end, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOutputFrame__dtor(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void easyar_ListOfOutputFrame_copy(IntPtr This, out IntPtr Return);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int easyar_ListOfOutputFrame_size(IntPtr This);
        [DllImport(BindingLibraryName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr easyar_ListOfOutputFrame_at(IntPtr This, int index);

        private static Dictionary<String, Func<IntPtr, RefBase>> TypeNameToConstructor = new Dictionary<String, Func<IntPtr, RefBase>>
        {
            { "ObjectTargetParameters", cdata => new ObjectTargetParameters(cdata, easyar_ObjectTargetParameters__dtor, easyar_ObjectTargetParameters__retain) },
            { "ObjectTarget", cdata => new ObjectTarget(cdata, easyar_ObjectTarget__dtor, easyar_ObjectTarget__retain) },
            { "ObjectTrackerResult", cdata => new ObjectTrackerResult(cdata, easyar_ObjectTrackerResult__dtor, easyar_ObjectTrackerResult__retain) },
            { "ObjectTracker", cdata => new ObjectTracker(cdata, easyar_ObjectTracker__dtor, easyar_ObjectTracker__retain) },
            { "CADTarget", cdata => new CADTarget(cdata, easyar_CADTarget__dtor, easyar_CADTarget__retain) },
            { "CADTrackerResult", cdata => new CADTrackerResult(cdata, easyar_CADTrackerResult__dtor, easyar_CADTrackerResult__retain) },
            { "CADTracker", cdata => new CADTracker(cdata, easyar_CADTracker__dtor, easyar_CADTracker__retain) },
            { "CloudRecognizer", cdata => new CloudRecognizer(cdata, easyar_CloudRecognizer__dtor, easyar_CloudRecognizer__retain) },
            { "DenseSpatialMap", cdata => new DenseSpatialMap(cdata, easyar_DenseSpatialMap__dtor, easyar_DenseSpatialMap__retain) },
            { "SceneMesh", cdata => new SceneMesh(cdata, easyar_SceneMesh__dtor, easyar_SceneMesh__retain) },
            { "SurfaceTrackerResult", cdata => new SurfaceTrackerResult(cdata, easyar_SurfaceTrackerResult__dtor, easyar_SurfaceTrackerResult__retain) },
            { "SurfaceTracker", cdata => new SurfaceTracker(cdata, easyar_SurfaceTracker__dtor, easyar_SurfaceTracker__retain) },
            { "MotionTrackerResult", cdata => new MotionTrackerResult(cdata, easyar_MotionTrackerResult__dtor, easyar_MotionTrackerResult__retain) },
            { "MotionTracker", cdata => new MotionTracker(cdata, easyar_MotionTracker__dtor, easyar_MotionTracker__retain) },
            { "MotionTrackerOutputFrameToInputFrameAdapter", cdata => new MotionTrackerOutputFrameToInputFrameAdapter(cdata, easyar_MotionTrackerOutputFrameToInputFrameAdapter__dtor, easyar_MotionTrackerOutputFrameToInputFrameAdapter__retain) },
            { "ImageTargetParameters", cdata => new ImageTargetParameters(cdata, easyar_ImageTargetParameters__dtor, easyar_ImageTargetParameters__retain) },
            { "ImageTarget", cdata => new ImageTarget(cdata, easyar_ImageTarget__dtor, easyar_ImageTarget__retain) },
            { "ImageTrackerResult", cdata => new ImageTrackerResult(cdata, easyar_ImageTrackerResult__dtor, easyar_ImageTrackerResult__retain) },
            { "ImageTracker", cdata => new ImageTracker(cdata, easyar_ImageTracker__dtor, easyar_ImageTracker__retain) },
            { "Recorder", cdata => new Recorder(cdata, easyar_Recorder__dtor, easyar_Recorder__retain) },
            { "RecorderConfiguration", cdata => new RecorderConfiguration(cdata, easyar_RecorderConfiguration__dtor, easyar_RecorderConfiguration__retain) },
            { "SparseSpatialMapResult", cdata => new SparseSpatialMapResult(cdata, easyar_SparseSpatialMapResult__dtor, easyar_SparseSpatialMapResult__retain) },
            { "PlaneData", cdata => new PlaneData(cdata, easyar_PlaneData__dtor, easyar_PlaneData__retain) },
            { "SparseSpatialMapConfig", cdata => new SparseSpatialMapConfig(cdata, easyar_SparseSpatialMapConfig__dtor, easyar_SparseSpatialMapConfig__retain) },
            { "SparseSpatialMap", cdata => new SparseSpatialMap(cdata, easyar_SparseSpatialMap__dtor, easyar_SparseSpatialMap__retain) },
            { "CallbackScheduler", cdata => new CallbackScheduler(cdata, easyar_CallbackScheduler__dtor, easyar_CallbackScheduler__retain) },
            { "DelayedCallbackScheduler", cdata => new DelayedCallbackScheduler(cdata, easyar_DelayedCallbackScheduler__dtor, easyar_DelayedCallbackScheduler__retain) },
            { "ImmediateCallbackScheduler", cdata => new ImmediateCallbackScheduler(cdata, easyar_ImmediateCallbackScheduler__dtor, easyar_ImmediateCallbackScheduler__retain) },
            { "CameraDevice", cdata => new CameraDevice(cdata, easyar_CameraDevice__dtor, easyar_CameraDevice__retain) },
            { "SignalSink", cdata => new SignalSink(cdata, easyar_SignalSink__dtor, easyar_SignalSink__retain) },
            { "SignalSource", cdata => new SignalSource(cdata, easyar_SignalSource__dtor, easyar_SignalSource__retain) },
            { "InputFrameSink", cdata => new InputFrameSink(cdata, easyar_InputFrameSink__dtor, easyar_InputFrameSink__retain) },
            { "InputFrameSource", cdata => new InputFrameSource(cdata, easyar_InputFrameSource__dtor, easyar_InputFrameSource__retain) },
            { "OutputFrameSink", cdata => new OutputFrameSink(cdata, easyar_OutputFrameSink__dtor, easyar_OutputFrameSink__retain) },
            { "OutputFrameSource", cdata => new OutputFrameSource(cdata, easyar_OutputFrameSource__dtor, easyar_OutputFrameSource__retain) },
            { "FeedbackFrameSink", cdata => new FeedbackFrameSink(cdata, easyar_FeedbackFrameSink__dtor, easyar_FeedbackFrameSink__retain) },
            { "FeedbackFrameSource", cdata => new FeedbackFrameSource(cdata, easyar_FeedbackFrameSource__dtor, easyar_FeedbackFrameSource__retain) },
            { "InputFrameFork", cdata => new InputFrameFork(cdata, easyar_InputFrameFork__dtor, easyar_InputFrameFork__retain) },
            { "OutputFrameFork", cdata => new OutputFrameFork(cdata, easyar_OutputFrameFork__dtor, easyar_OutputFrameFork__retain) },
            { "OutputFrameJoin", cdata => new OutputFrameJoin(cdata, easyar_OutputFrameJoin__dtor, easyar_OutputFrameJoin__retain) },
            { "FeedbackFrameFork", cdata => new FeedbackFrameFork(cdata, easyar_FeedbackFrameFork__dtor, easyar_FeedbackFrameFork__retain) },
            { "InputFrameThrottler", cdata => new InputFrameThrottler(cdata, easyar_InputFrameThrottler__dtor, easyar_InputFrameThrottler__retain) },
            { "OutputFrameBuffer", cdata => new OutputFrameBuffer(cdata, easyar_OutputFrameBuffer__dtor, easyar_OutputFrameBuffer__retain) },
            { "InputFrameToOutputFrameAdapter", cdata => new InputFrameToOutputFrameAdapter(cdata, easyar_InputFrameToOutputFrameAdapter__dtor, easyar_InputFrameToOutputFrameAdapter__retain) },
            { "InputFrameToFeedbackFrameAdapter", cdata => new InputFrameToFeedbackFrameAdapter(cdata, easyar_InputFrameToFeedbackFrameAdapter__dtor, easyar_InputFrameToFeedbackFrameAdapter__retain) },
            { "InputFrame", cdata => new InputFrame(cdata, easyar_InputFrame__dtor, easyar_InputFrame__retain) },
            { "FrameFilterResult", cdata => new FrameFilterResult(cdata, easyar_FrameFilterResult__dtor, easyar_FrameFilterResult__retain) },
            { "OutputFrame", cdata => new OutputFrame(cdata, easyar_OutputFrame__dtor, easyar_OutputFrame__retain) },
            { "FeedbackFrame", cdata => new FeedbackFrame(cdata, easyar_FeedbackFrame__dtor, easyar_FeedbackFrame__retain) },
            { "Target", cdata => new Target(cdata, easyar_Target__dtor, easyar_Target__retain) },
            { "TargetInstance", cdata => new TargetInstance(cdata, easyar_TargetInstance__dtor, easyar_TargetInstance__retain) },
            { "TargetTrackerResult", cdata => new TargetTrackerResult(cdata, easyar_TargetTrackerResult__dtor, easyar_TargetTrackerResult__retain) },
            { "TextureId", cdata => new TextureId(cdata, easyar_TextureId__dtor, easyar_TextureId__retain) },
            { "VideoPlayer", cdata => new VideoPlayer(cdata, easyar_VideoPlayer__dtor, easyar_VideoPlayer__retain) },
            { "Buffer", cdata => new Buffer(cdata, easyar_Buffer__dtor, easyar_Buffer__retain) },
            { "BufferDictionary", cdata => new BufferDictionary(cdata, easyar_BufferDictionary__dtor, easyar_BufferDictionary__retain) },
            { "BufferPool", cdata => new BufferPool(cdata, easyar_BufferPool__dtor, easyar_BufferPool__retain) },
            { "CameraParameters", cdata => new CameraParameters(cdata, easyar_CameraParameters__dtor, easyar_CameraParameters__retain) },
            { "Image", cdata => new Image(cdata, easyar_Image__dtor, easyar_Image__retain) },
        };

        public class AutoRelease : IDisposable
        {
            private List<Action> actions;

            public void Add(Action deleter)
            {
                if (actions == null) { actions = new List<Action>(); }
                actions.Add(deleter);
            }
            public T Add<T>(T p, Action<T> deleter)
            {
                if (p.Equals(default(T))) { return p; }
                if (actions == null) { actions = new List<Action>(); }
                actions.Add(() => deleter(p));
                return p;
            }

            public void Dispose()
            {
                if (actions != null)
                {
                    foreach (var a in actions)
                    {
                        a();
                    }
                    actions = null;
                }
            }
        }

        public static IntPtr String_to_c(AutoRelease ar, string s)
        {
            if (s == null) { throw new ArgumentNullException(); }
            var bytes = System.Text.Encoding.UTF8.GetBytes(s);
            var handle = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(bytes, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + bytes.Length);
                var returnValue = IntPtr.Zero;
                easyar_String_from_utf8(beginPtr, endPtr, out returnValue);
                return ar.Add(returnValue, easyar_String__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static IntPtr String_to_c_inner(string s)
        {
            if (s == null) { throw new ArgumentNullException(); }
            var bytes = System.Text.Encoding.UTF8.GetBytes(s);
            var handle = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(bytes, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + bytes.Length);
                var returnValue = IntPtr.Zero;
                easyar_String_from_utf8(beginPtr, endPtr, out returnValue);
                return returnValue;
            }
            finally
            {
                handle.Free();
            }
        }
        public static String String_from_c(AutoRelease ar, IntPtr ptr)
        {
            if (ptr == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(ptr, easyar_String__dtor);
            IntPtr beginPtr = easyar_String_begin(ptr);
            IntPtr endPtr = easyar_String_end(ptr);
            var length = (int)(endPtr.ToInt64() - beginPtr.ToInt64());
            var bytes = new byte[length];
            Marshal.Copy(beginPtr, bytes, 0, length);
            return System.Text.Encoding.UTF8.GetString(bytes);
        }
        public static String String_from_cstring(IntPtr ptr)
        {
            if (ptr == IntPtr.Zero) { throw new ArgumentNullException(); }
            var length = 0;
            while (true)
            {
                var b = Marshal.ReadByte(ptr, length);
                if (b == 0) { break; }
                length += 1;
            }
            var bytes = new byte[length];
            Marshal.Copy(ptr, bytes, 0, length);
            return System.Text.Encoding.UTF8.GetString(bytes);
        }

        public static T Object_from_c<T>(IntPtr ptr, Func<IntPtr, IntPtr> typeNameGetter)
        {
            if (ptr == IntPtr.Zero) { throw new ArgumentNullException(); }
            var typeName = String_from_cstring(typeNameGetter(ptr));
            if (!TypeNameToConstructor.ContainsKey(typeName)) { throw new InvalidOperationException("ConstructorNotExistForType"); }
            var ctor = TypeNameToConstructor[typeName];
            var o = ctor(ptr);
            return (T)(Object)(o);
        }
        public static TValue map<TKey, TValue>(this TKey v, Func<TKey, TValue> f)
        {
            return f(v);
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfBuffer
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoid
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoid.FunctionDelegate))]
#endif
        public static void FunctorOfVoid_func(IntPtr state, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var f = (Action)((GCHandle)(state)).Target;
                    f();
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoid.DestroyDelegate))]
#endif
        public static void FunctorOfVoid_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoid FunctorOfVoid_to_c(Action f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoid { _state = (IntPtr)(s), _func = FunctorOfVoid_func, _destroy = FunctorOfVoid_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfObjectTarget
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        public static IntPtr ListOfObjectTarget_to_c(AutoRelease ar, List<ObjectTarget> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfObjectTarget__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfObjectTarget__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<ObjectTarget> ListOfObjectTarget_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfObjectTarget__dtor);
            var size = easyar_ListOfObjectTarget_size(l);
            var values = new List<ObjectTarget>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfObjectTarget_at(l, k);
                easyar_ObjectTarget__retain(v, out v);
                values.Add(Object_from_c<ObjectTarget>(v, easyar_ObjectTarget__typeName));
            }
            return values;
        }

        public static IntPtr ListOfVec3F_to_c(AutoRelease ar, List<Vec3F> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfVec3F__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfVec3F__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<Vec3F> ListOfVec3F_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfVec3F__dtor);
            var size = easyar_ListOfVec3F_size(l);
            var values = new List<Vec3F>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfVec3F_at(l, k);
                values.Add(v);
            }
            return values;
        }

        public static IntPtr ListOfTargetInstance_to_c(AutoRelease ar, List<TargetInstance> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfTargetInstance__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfTargetInstance__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<TargetInstance> ListOfTargetInstance_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfTargetInstance__dtor);
            var size = easyar_ListOfTargetInstance_size(l);
            var values = new List<TargetInstance>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfTargetInstance_at(l, k);
                easyar_TargetInstance__retain(v, out v);
                values.Add(Object_from_c<TargetInstance>(v, easyar_TargetInstance__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfTarget
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfOutputFrame
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        public static IntPtr ListOfOptionalOfFrameFilterResult_to_c(AutoRelease ar, List<Optional<FrameFilterResult>> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.map(p => p.OnSome ? new OptionalOfFrameFilterResult { has_value = true, value = p.Value.cdata } : new OptionalOfFrameFilterResult { has_value = false, value = default(IntPtr) })).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfOptionalOfFrameFilterResult__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfOptionalOfFrameFilterResult__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<Optional<FrameFilterResult>> ListOfOptionalOfFrameFilterResult_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfOptionalOfFrameFilterResult__dtor);
            var size = easyar_ListOfOptionalOfFrameFilterResult_size(l);
            var values = new List<Optional<FrameFilterResult>>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfOptionalOfFrameFilterResult_at(l, k);
                if (v.has_value) { easyar_FrameFilterResult__retain(v.value, out v.value); }
                values.Add(v.map(p => p.has_value ? Object_from_c<FrameFilterResult>(p.value, easyar_FrameFilterResult__typeName) : Optional<FrameFilterResult>.Empty));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFrameFilterResult
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromOutputFrame
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromOutputFrame value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromOutputFrame
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, IntPtr arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromOutputFrame.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromOutputFrame_func(IntPtr state, IntPtr arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    easyar_OutputFrame__retain(varg0, out varg0);
                    var sarg0 = Object_from_c<OutputFrame>(varg0, easyar_OutputFrame__typeName);
                    ar.Add(() => sarg0.Dispose());
                    var f = (Action<OutputFrame>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromOutputFrame.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromOutputFrame_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromOutputFrame FunctorOfVoidFromOutputFrame_to_c(Action<OutputFrame> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromOutputFrame { _state = (IntPtr)(s), _func = FunctorOfVoidFromOutputFrame_func, _destroy = FunctorOfVoidFromOutputFrame_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromTargetAndBool
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, IntPtr arg0, bool arg1, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromTargetAndBool.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromTargetAndBool_func(IntPtr state, IntPtr arg0, bool arg1, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    easyar_Target__retain(varg0, out varg0);
                    var sarg0 = Object_from_c<Target>(varg0, easyar_Target__typeName);
                    ar.Add(() => sarg0.Dispose());
                    var sarg1 = arg1;
                    var f = (Action<Target, bool>)((GCHandle)(state)).Target;
                    f(sarg0, sarg1);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromTargetAndBool.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromTargetAndBool_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(Action<Target, bool> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromTargetAndBool { _state = (IntPtr)(s), _func = FunctorOfVoidFromTargetAndBool_func, _destroy = FunctorOfVoidFromTargetAndBool_destroy };
        }

        public static IntPtr ListOfTarget_to_c(AutoRelease ar, List<Target> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfTarget__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfTarget__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<Target> ListOfTarget_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfTarget__dtor);
            var size = easyar_ListOfTarget_size(l);
            var values = new List<Target>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfTarget_at(l, k);
                easyar_Target__retain(v, out v);
                values.Add(Object_from_c<Target>(v, easyar_Target__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfCADTarget
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        public static IntPtr ListOfCADTarget_to_c(AutoRelease ar, List<CADTarget> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfCADTarget__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfCADTarget__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<CADTarget> ListOfCADTarget_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfCADTarget__dtor);
            var size = easyar_ListOfCADTarget_size(l);
            var values = new List<CADTarget>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfCADTarget_at(l, k);
                easyar_CADTarget__retain(v, out v);
                values.Add(Object_from_c<CADTarget>(v, easyar_CADTarget__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromCloudStatusAndListOfTarget value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromCloudStatusAndListOfTarget
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, CloudStatus arg0, IntPtr arg1, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromCloudStatusAndListOfTarget.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromCloudStatusAndListOfTarget_func(IntPtr state, CloudStatus arg0, IntPtr arg1, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var varg1 = arg1;
                    easyar_ListOfTarget_copy(varg1, out varg1);
                    var sarg1 = ListOfTarget_from_c(ar, varg1);
                    sarg1.ForEach(_v0_ => { ar.Add(() => _v0_.Dispose()); });
                    var f = (Action<CloudStatus, List<Target>>)((GCHandle)(state)).Target;
                    f(sarg0, sarg1);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromCloudStatusAndListOfTarget.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromCloudStatusAndListOfTarget_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromCloudStatusAndListOfTarget FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(Action<CloudStatus, List<Target>> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromCloudStatusAndListOfTarget { _state = (IntPtr)(s), _func = FunctorOfVoidFromCloudStatusAndListOfTarget_func, _destroy = FunctorOfVoidFromCloudStatusAndListOfTarget_destroy };
        }

        public static IntPtr ListOfBlockInfo_to_c(AutoRelease ar, List<BlockInfo> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfBlockInfo__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfBlockInfo__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<BlockInfo> ListOfBlockInfo_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfBlockInfo__dtor);
            var size = easyar_ListOfBlockInfo_size(l);
            var values = new List<BlockInfo>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfBlockInfo_at(l, k);
                values.Add(v);
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromInputFrame
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromInputFrame value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromInputFrame
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, IntPtr arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromInputFrame.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromInputFrame_func(IntPtr state, IntPtr arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    easyar_InputFrame__retain(varg0, out varg0);
                    var sarg0 = Object_from_c<InputFrame>(varg0, easyar_InputFrame__typeName);
                    ar.Add(() => sarg0.Dispose());
                    var f = (Action<InputFrame>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromInputFrame.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromInputFrame_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromInputFrame FunctorOfVoidFromInputFrame_to_c(Action<InputFrame> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromInputFrame { _state = (IntPtr)(s), _func = FunctorOfVoidFromInputFrame_func, _destroy = FunctorOfVoidFromInputFrame_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfImageTarget
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        public static IntPtr ListOfImageTarget_to_c(AutoRelease ar, List<ImageTarget> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfImageTarget__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfImageTarget__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<ImageTarget> ListOfImageTarget_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfImageTarget__dtor);
            var size = easyar_ListOfImageTarget_size(l);
            var values = new List<ImageTarget>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfImageTarget_at(l, k);
                easyar_ImageTarget__retain(v, out v);
                values.Add(Object_from_c<ImageTarget>(v, easyar_ImageTarget__typeName));
            }
            return values;
        }

        public static IntPtr ListOfImage_to_c(AutoRelease ar, List<Image> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfImage__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfImage__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<Image> ListOfImage_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfImage__dtor);
            var size = easyar_ListOfImage_size(l);
            var values = new List<Image>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfImage_at(l, k);
                easyar_Image__retain(v, out v);
                values.Add(Object_from_c<Image>(v, easyar_Image__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromPermissionStatusAndString
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromPermissionStatusAndString value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromPermissionStatusAndString
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, PermissionStatus arg0, IntPtr arg1, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromPermissionStatusAndString.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromPermissionStatusAndString_func(IntPtr state, PermissionStatus arg0, IntPtr arg1, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var varg1 = arg1;
                    easyar_String_copy(varg1, out varg1);
                    var sarg1 = String_from_c(ar, varg1);
                    var f = (Action<PermissionStatus, string>)((GCHandle)(state)).Target;
                    f(sarg0, sarg1);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromPermissionStatusAndString.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromPermissionStatusAndString_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(Action<PermissionStatus, string> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromPermissionStatusAndString { _state = (IntPtr)(s), _func = FunctorOfVoidFromPermissionStatusAndString_func, _destroy = FunctorOfVoidFromPermissionStatusAndString_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromRecordStatusAndString
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromRecordStatusAndString value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromRecordStatusAndString
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, RecordStatus arg0, IntPtr arg1, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromRecordStatusAndString.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromRecordStatusAndString_func(IntPtr state, RecordStatus arg0, IntPtr arg1, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var varg1 = arg1;
                    easyar_String_copy(varg1, out varg1);
                    var sarg1 = String_from_c(ar, varg1);
                    var f = (Action<RecordStatus, string>)((GCHandle)(state)).Target;
                    f(sarg0, sarg1);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromRecordStatusAndString.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromRecordStatusAndString_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromRecordStatusAndString FunctorOfVoidFromRecordStatusAndString_to_c(Action<RecordStatus, string> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromRecordStatusAndString { _state = (IntPtr)(s), _func = FunctorOfVoidFromRecordStatusAndString_func, _destroy = FunctorOfVoidFromRecordStatusAndString_destroy };
        }

        public static IntPtr ListOfPlaneData_to_c(AutoRelease ar, List<PlaneData> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfPlaneData__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfPlaneData__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<PlaneData> ListOfPlaneData_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfPlaneData__dtor);
            var size = easyar_ListOfPlaneData_size(l);
            var values = new List<PlaneData>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfPlaneData_at(l, k);
                easyar_PlaneData__retain(v, out v);
                values.Add(Object_from_c<PlaneData>(v, easyar_PlaneData__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromOptionalOfBuffer
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, OptionalOfBuffer arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromOptionalOfBuffer.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromOptionalOfBuffer_func(IntPtr state, OptionalOfBuffer arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    if (varg0.has_value) { easyar_Buffer__retain(varg0.value, out varg0.value); }
                    var sarg0 = varg0.map(p => p.has_value ? Object_from_c<Buffer>(p.value, easyar_Buffer__typeName) : Optional<Buffer>.Empty);
                    if (sarg0.OnSome) { ar.Add(() => sarg0.Value.Dispose()); }
                    var f = (Action<Optional<Buffer>>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromOptionalOfBuffer.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromOptionalOfBuffer_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromOptionalOfBuffer FunctorOfVoidFromOptionalOfBuffer_to_c(Action<Optional<Buffer>> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromOptionalOfBuffer { _state = (IntPtr)(s), _func = FunctorOfVoidFromOptionalOfBuffer_func, _destroy = FunctorOfVoidFromOptionalOfBuffer_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromBool
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromBool value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromBool
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, bool arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromBool.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromBool_func(IntPtr state, bool arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var f = (Action<bool>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromBool.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromBool_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(Action<bool> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromBool { _state = (IntPtr)(s), _func = FunctorOfVoidFromBool_func, _destroy = FunctorOfVoidFromBool_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfImage
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public IntPtr value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromCameraState
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromCameraState value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromCameraState
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, CameraState arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromCameraState.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromCameraState_func(IntPtr state, CameraState arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var f = (Action<CameraState>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromCameraState.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromCameraState_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(Action<CameraState> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromCameraState { _state = (IntPtr)(s), _func = FunctorOfVoidFromCameraState_func, _destroy = FunctorOfVoidFromCameraState_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoid
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoid value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromFeedbackFrame
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromFeedbackFrame value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromFeedbackFrame
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, IntPtr arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromFeedbackFrame.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromFeedbackFrame_func(IntPtr state, IntPtr arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    easyar_FeedbackFrame__retain(varg0, out varg0);
                    var sarg0 = Object_from_c<FeedbackFrame>(varg0, easyar_FeedbackFrame__typeName);
                    ar.Add(() => sarg0.Dispose());
                    var f = (Action<FeedbackFrame>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromFeedbackFrame.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromFeedbackFrame_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromFeedbackFrame FunctorOfVoidFromFeedbackFrame_to_c(Action<FeedbackFrame> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromFeedbackFrame { _state = (IntPtr)(s), _func = FunctorOfVoidFromFeedbackFrame_func, _destroy = FunctorOfVoidFromFeedbackFrame_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfOutputFrameFromListOfOutputFrame
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, IntPtr arg0, out IntPtr Return, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfOutputFrameFromListOfOutputFrame.FunctionDelegate))]
#endif
        public static void FunctorOfOutputFrameFromListOfOutputFrame_func(IntPtr state, IntPtr arg0, out IntPtr Return, out IntPtr exception)
        {
            Return = default(IntPtr);
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var varg0 = arg0;
                    easyar_ListOfOutputFrame_copy(varg0, out varg0);
                    var sarg0 = ListOfOutputFrame_from_c(ar, varg0);
                    sarg0.ForEach(_v0_ => { ar.Add(() => _v0_.Dispose()); });
                    var f = (Func<List<OutputFrame>, OutputFrame>)((GCHandle)(state)).Target;
                    var _return_value_ = f(sarg0);
                    var _return_value_c_ = _return_value_.cdata;
                    Return = _return_value_c_;
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfOutputFrameFromListOfOutputFrame.DestroyDelegate))]
#endif
        public static void FunctorOfOutputFrameFromListOfOutputFrame_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfOutputFrameFromListOfOutputFrame FunctorOfOutputFrameFromListOfOutputFrame_to_c(Func<List<OutputFrame>, OutputFrame> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfOutputFrameFromListOfOutputFrame { _state = (IntPtr)(s), _func = FunctorOfOutputFrameFromListOfOutputFrame_func, _destroy = FunctorOfOutputFrameFromListOfOutputFrame_destroy };
        }

        public static IntPtr ListOfOutputFrame_to_c(AutoRelease ar, List<OutputFrame> l)
        {
            if (l == null) { throw new ArgumentNullException(); }
            var arr = l.Select(e => e.cdata).ToArray();
            var handle = GCHandle.Alloc(arr, GCHandleType.Pinned);
            try
            {
                var beginPtr = Marshal.UnsafeAddrOfPinnedArrayElement(arr, 0);
                var endPtr = new IntPtr(beginPtr.ToInt64() + IntPtr.Size * arr.Length);
                var ptr = IntPtr.Zero;
                easyar_ListOfOutputFrame__ctor(beginPtr, endPtr, out ptr);
                return ar.Add(ptr, easyar_ListOfOutputFrame__dtor);
            }
            finally
            {
                handle.Free();
            }
        }
        public static List<OutputFrame> ListOfOutputFrame_from_c(AutoRelease ar, IntPtr l)
        {
            if (l == IntPtr.Zero) { throw new ArgumentNullException(); }
            ar.Add(l, easyar_ListOfOutputFrame__dtor);
            var size = easyar_ListOfOutputFrame_size(l);
            var values = new List<OutputFrame>();
            values.Capacity = size;
            for (int k = 0; k < size; k += 1)
            {
                var v = easyar_ListOfOutputFrame_at(l, k);
                easyar_OutputFrame__retain(v, out v);
                values.Add(Object_from_c<OutputFrame>(v, easyar_OutputFrame__typeName));
            }
            return values;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct OptionalOfFunctorOfVoidFromVideoStatus
        {
            private Byte has_value_;
            public bool has_value { get { return has_value_ != 0; } set { has_value_ = (Byte)(value ? 1 : 0); } }
            public FunctorOfVoidFromVideoStatus value;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromVideoStatus
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, VideoStatus arg0, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromVideoStatus.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromVideoStatus_func(IntPtr state, VideoStatus arg0, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var f = (Action<VideoStatus>)((GCHandle)(state)).Target;
                    f(sarg0);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromVideoStatus.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromVideoStatus_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromVideoStatus FunctorOfVoidFromVideoStatus_to_c(Action<VideoStatus> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromVideoStatus { _state = (IntPtr)(s), _func = FunctorOfVoidFromVideoStatus_func, _destroy = FunctorOfVoidFromVideoStatus_destroy };
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct FunctorOfVoidFromLogLevelAndString
        {
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void FunctionDelegate(IntPtr state, LogLevel arg0, IntPtr arg1, out IntPtr exception);
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)] public delegate void DestroyDelegate(IntPtr _state);

            public IntPtr _state;
            public FunctionDelegate _func;
            public DestroyDelegate _destroy;
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromLogLevelAndString.FunctionDelegate))]
#endif
        public static void FunctorOfVoidFromLogLevelAndString_func(IntPtr state, LogLevel arg0, IntPtr arg1, out IntPtr exception)
        {
            exception = IntPtr.Zero;
            try
            {
                using (var ar = new AutoRelease())
                {
                    var sarg0 = arg0;
                    var varg1 = arg1;
                    easyar_String_copy(varg1, out varg1);
                    var sarg1 = String_from_c(ar, varg1);
                    var f = (Action<LogLevel, string>)((GCHandle)(state)).Target;
                    f(sarg0, sarg1);
                }
            }
            catch (Exception ex)
            {
                exception = Detail.String_to_c_inner(ex.ToString());
            }
        }
#if ENABLE_IL2CPP
        [MonoPInvokeCallback(typeof(FunctorOfVoidFromLogLevelAndString.DestroyDelegate))]
#endif
        public static void FunctorOfVoidFromLogLevelAndString_destroy(IntPtr _state)
        {
            ((GCHandle)(_state)).Free();
        }
        public static FunctorOfVoidFromLogLevelAndString FunctorOfVoidFromLogLevelAndString_to_c(Action<LogLevel, string> f)
        {
            if (f == null) { throw new ArgumentNullException(); }
            var s = GCHandle.Alloc(f, GCHandleType.Normal);
            return new FunctorOfVoidFromLogLevelAndString { _state = (IntPtr)(s), _func = FunctorOfVoidFromLogLevelAndString_func, _destroy = FunctorOfVoidFromLogLevelAndString_destroy };
        }

    }

    public class ObjectTargetParameters : RefBase
    {
        internal ObjectTargetParameters(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ObjectTargetParameters(cdata_new, deleter_, retainer_);
        }
        public new ObjectTargetParameters Clone()
        {
            return (ObjectTargetParameters)(CloneObject());
        }
        public ObjectTargetParameters() : base(IntPtr.Zero, Detail.easyar_ObjectTargetParameters__dtor, Detail.easyar_ObjectTargetParameters__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_ObjectTargetParameters__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual BufferDictionary bufferDictionary()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTargetParameters_bufferDictionary(cdata, out _return_value_);
                return Detail.Object_from_c<BufferDictionary>(_return_value_, Detail.easyar_BufferDictionary__typeName);
            }
        }
        public virtual void setBufferDictionary(BufferDictionary bufferDictionary)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setBufferDictionary(cdata, bufferDictionary.cdata);
            }
        }
        public virtual string objPath()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTargetParameters_objPath(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setObjPath(string objPath)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setObjPath(cdata, Detail.String_to_c(ar, objPath));
            }
        }
        public virtual string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTargetParameters_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public virtual string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTargetParameters_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setUid(string uid)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setUid(cdata, Detail.String_to_c(ar, uid));
            }
        }
        public virtual string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTargetParameters_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setMeta(string meta)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setMeta(cdata, Detail.String_to_c(ar, meta));
            }
        }
        public virtual float scale()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTargetParameters_scale(cdata);
                return _return_value_;
            }
        }
        public virtual void setScale(float size)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTargetParameters_setScale(cdata, size);
            }
        }
    }

    public class ObjectTarget : Target
    {
        internal ObjectTarget(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ObjectTarget(cdata_new, deleter_, retainer_);
        }
        public new ObjectTarget Clone()
        {
            return (ObjectTarget)(CloneObject());
        }
        public ObjectTarget() : base(IntPtr.Zero, Detail.easyar_ObjectTarget__dtor, Detail.easyar_ObjectTarget__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_ObjectTarget__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public static Optional<ObjectTarget> createFromParameters(ObjectTargetParameters parameters)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfObjectTarget);
                Detail.easyar_ObjectTarget_createFromParameters(parameters.cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ObjectTarget>(p.value, Detail.easyar_ObjectTarget__typeName) : Optional<ObjectTarget>.Empty);
            }
        }
        public static Optional<ObjectTarget> createFromObjectFile(string path, StorageType storageType, string name, string uid, string meta, float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfObjectTarget);
                Detail.easyar_ObjectTarget_createFromObjectFile(Detail.String_to_c(ar, path), storageType, Detail.String_to_c(ar, name), Detail.String_to_c(ar, uid), Detail.String_to_c(ar, meta), scale, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ObjectTarget>(p.value, Detail.easyar_ObjectTarget__typeName) : Optional<ObjectTarget>.Empty);
            }
        }
        public static List<ObjectTarget> setupAll(string path, StorageType storageType)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTarget_setupAll(Detail.String_to_c(ar, path), storageType, out _return_value_);
                return Detail.ListOfObjectTarget_from_c(ar, _return_value_);
            }
        }
        public virtual float scale()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTarget_scale(cdata);
                return _return_value_;
            }
        }
        public virtual List<Vec3F> boundingBox()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTarget_boundingBox(cdata, out _return_value_);
                return Detail.ListOfVec3F_from_c(ar, _return_value_);
            }
        }
        public virtual bool setScale(float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTarget_setScale(cdata, scale);
                return _return_value_;
            }
        }
        public override int runtimeID()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTarget_runtimeID(cdata);
                return _return_value_;
            }
        }
        public override string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTarget_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTarget_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTarget_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public override string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTarget_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setMeta(string data)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTarget_setMeta(cdata, Detail.String_to_c(ar, data));
            }
        }
    }

    public class ObjectTrackerResult : TargetTrackerResult
    {
        internal ObjectTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ObjectTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new ObjectTrackerResult Clone()
        {
            return (ObjectTrackerResult)(CloneObject());
        }
        public override List<TargetInstance> targetInstances()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTrackerResult_targetInstances(cdata, out _return_value_);
                return Detail.ListOfTargetInstance_from_c(ar, _return_value_);
            }
        }
        public override void setTargetInstances(List<TargetInstance> instances)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTrackerResult_setTargetInstances(cdata, Detail.ListOfTargetInstance_to_c(ar, instances));
            }
        }
    }

    public class ObjectTracker : RefBase
    {
        internal ObjectTracker(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ObjectTracker(cdata_new, deleter_, retainer_);
        }
        public new ObjectTracker Clone()
        {
            return (ObjectTracker)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTracker_isAvailable();
                return _return_value_;
            }
        }
        public virtual FeedbackFrameSink feedbackFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTracker_feedbackFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSink>(_return_value_, Detail.easyar_FeedbackFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTracker_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static ObjectTracker create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTracker_create(out _return_value_);
                return Detail.Object_from_c<ObjectTracker>(_return_value_, Detail.easyar_ObjectTracker__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTracker_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTracker_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTracker_close(cdata);
            }
        }
        public virtual void loadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTracker_loadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual void unloadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ObjectTracker_unloadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual List<Target> targets()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ObjectTracker_targets(cdata, out _return_value_);
                return Detail.ListOfTarget_from_c(ar, _return_value_);
            }
        }
        public virtual bool setSimultaneousNum(int num)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTracker_setSimultaneousNum(cdata, num);
                return _return_value_;
            }
        }
        public virtual int simultaneousNum()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ObjectTracker_simultaneousNum(cdata);
                return _return_value_;
            }
        }
    }

    public class CADTarget : Target
    {
        internal CADTarget(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CADTarget(cdata_new, deleter_, retainer_);
        }
        public new CADTarget Clone()
        {
            return (CADTarget)(CloneObject());
        }
        public CADTarget() : base(IntPtr.Zero, Detail.easyar_CADTarget__dtor, Detail.easyar_CADTarget__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_CADTarget__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public static Optional<CADTarget> createFromUnity(Buffer vertices, Buffer faces, Matrix44F transform, float localScale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfCADTarget);
                Detail.easyar_CADTarget_createFromUnity(vertices.cdata, faces.cdata, transform, localScale, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<CADTarget>(p.value, Detail.easyar_CADTarget__typeName) : Optional<CADTarget>.Empty);
            }
        }
        public virtual void updateTransform(Matrix44F transform, float localScale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTarget_updateTransform(cdata, transform, localScale);
            }
        }
        public virtual void updateTrackConfig(float threshContrast, float threshConsist, float threshQuality)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTarget_updateTrackConfig(cdata, threshContrast, threshConsist, threshQuality);
            }
        }
        public static Optional<CADTarget> createFromObjectFile(string path, StorageType storageType, string name, string uid, string meta, float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfCADTarget);
                Detail.easyar_CADTarget_createFromObjectFile(Detail.String_to_c(ar, path), storageType, Detail.String_to_c(ar, name), Detail.String_to_c(ar, uid), Detail.String_to_c(ar, meta), scale, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<CADTarget>(p.value, Detail.easyar_CADTarget__typeName) : Optional<CADTarget>.Empty);
            }
        }
        public static List<CADTarget> setupAll(string path, StorageType storageType)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_setupAll(Detail.String_to_c(ar, path), storageType, out _return_value_);
                return Detail.ListOfCADTarget_from_c(ar, _return_value_);
            }
        }
        public virtual float scale()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CADTarget_scale(cdata);
                return _return_value_;
            }
        }
        public virtual List<Vec3F> boundingBox()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_boundingBox(cdata, out _return_value_);
                return Detail.ListOfVec3F_from_c(ar, _return_value_);
            }
        }
        public virtual List<Vec3F> boundingBoxGL()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_boundingBoxGL(cdata, out _return_value_);
                return Detail.ListOfVec3F_from_c(ar, _return_value_);
            }
        }
        public virtual bool setScale(float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CADTarget_setScale(cdata, scale);
                return _return_value_;
            }
        }
        public override int runtimeID()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CADTarget_runtimeID(cdata);
                return _return_value_;
            }
        }
        public override string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTarget_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public override string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTarget_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setMeta(string data)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTarget_setMeta(cdata, Detail.String_to_c(ar, data));
            }
        }
    }

    public class CADTrackerResult : TargetTrackerResult
    {
        internal CADTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CADTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new CADTrackerResult Clone()
        {
            return (CADTrackerResult)(CloneObject());
        }
        public override List<TargetInstance> targetInstances()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTrackerResult_targetInstances(cdata, out _return_value_);
                return Detail.ListOfTargetInstance_from_c(ar, _return_value_);
            }
        }
        public override void setTargetInstances(List<TargetInstance> instances)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTrackerResult_setTargetInstances(cdata, Detail.ListOfTargetInstance_to_c(ar, instances));
            }
        }
    }

    public class CADTracker : RefBase
    {
        internal CADTracker(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CADTracker(cdata_new, deleter_, retainer_);
        }
        public new CADTracker Clone()
        {
            return (CADTracker)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CADTracker_isAvailable();
                return _return_value_;
            }
        }
        public virtual FeedbackFrameSink feedbackFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTracker_feedbackFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSink>(_return_value_, Detail.easyar_FeedbackFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTracker_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static CADTracker create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTracker_create(out _return_value_);
                return Detail.Object_from_c<CADTracker>(_return_value_, Detail.easyar_CADTracker__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CADTracker_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTracker_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTracker_close(cdata);
            }
        }
        public virtual void loadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTracker_loadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual void unloadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CADTracker_unloadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual List<Target> targets()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CADTracker_targets(cdata, out _return_value_);
                return Detail.ListOfTarget_from_c(ar, _return_value_);
            }
        }
    }

    public enum CloudStatus
    {
        FoundTargets = 0,
        TargetsNotFound = 1,
        Reconnecting = 2,
        ProtocolError = 3,
    }

    public class CloudRecognizer : RefBase
    {
        internal CloudRecognizer(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CloudRecognizer(cdata_new, deleter_, retainer_);
        }
        public new CloudRecognizer Clone()
        {
            return (CloudRecognizer)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CloudRecognizer_isAvailable();
                return _return_value_;
            }
        }
        public virtual InputFrameSink inputFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CloudRecognizer_inputFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public static CloudRecognizer create(string server, string appKey, string appSecret, CallbackScheduler callbackScheduler, Optional<Action<CloudStatus, List<Target>>> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CloudRecognizer_create(Detail.String_to_c(ar, server), Detail.String_to_c(ar, appKey), Detail.String_to_c(ar, appSecret), callbackScheduler.cdata, callback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget { has_value = true, value = Detail.FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget { has_value = false, value = default(Detail.FunctorOfVoidFromCloudStatusAndListOfTarget) }), out _return_value_);
                return Detail.Object_from_c<CloudRecognizer>(_return_value_, Detail.easyar_CloudRecognizer__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CloudRecognizer_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CloudRecognizer_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CloudRecognizer_close(cdata);
            }
        }
    }

    public class DenseSpatialMap : RefBase
    {
        internal DenseSpatialMap(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new DenseSpatialMap(cdata_new, deleter_, retainer_);
        }
        public new DenseSpatialMap Clone()
        {
            return (DenseSpatialMap)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_DenseSpatialMap_isAvailable();
                return _return_value_;
            }
        }
        public virtual InputFrameSink inputFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_DenseSpatialMap_inputFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public static DenseSpatialMap create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_DenseSpatialMap_create(out _return_value_);
                return Detail.Object_from_c<DenseSpatialMap>(_return_value_, Detail.easyar_DenseSpatialMap__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_DenseSpatialMap_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_DenseSpatialMap_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_DenseSpatialMap_close(cdata);
            }
        }
        public virtual string saveMap()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_DenseSpatialMap_saveMap(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual SceneMesh getMesh()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_DenseSpatialMap_getMesh(cdata, out _return_value_);
                return Detail.Object_from_c<SceneMesh>(_return_value_, Detail.easyar_SceneMesh__typeName);
            }
        }
        public virtual bool updateSceneMesh(bool updateMeshAll)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_DenseSpatialMap_updateSceneMesh(cdata, updateMeshAll);
                return _return_value_;
            }
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct BlockInfo
    {
        public int x_;
        public int y_;
        public int z_;
        public int numOfVertex_;
        public int startPointOfVertex_;
        public int numOfIndex_;
        public int startPointOfIndex_;
        public int age_;

        public BlockInfo(int x_, int y_, int z_, int numOfVertex_, int startPointOfVertex_, int numOfIndex_, int startPointOfIndex_, int age_)
        {
            this.x_ = x_;
            this.y_ = y_;
            this.z_ = z_;
            this.numOfVertex_ = numOfVertex_;
            this.startPointOfVertex_ = startPointOfVertex_;
            this.numOfIndex_ = numOfIndex_;
            this.startPointOfIndex_ = startPointOfIndex_;
            this.age_ = age_;
        }
    }

    public class SceneMesh : RefBase
    {
        internal SceneMesh(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SceneMesh(cdata_new, deleter_, retainer_);
        }
        public new SceneMesh Clone()
        {
            return (SceneMesh)(CloneObject());
        }
        public SceneMesh() : base(IntPtr.Zero, Detail.easyar_SceneMesh__dtor, Detail.easyar_SceneMesh__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_SceneMesh__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual int getNumOfVertexAll()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SceneMesh_getNumOfVertexAll(cdata);
                return _return_value_;
            }
        }
        public virtual int getNumOfIndexAll()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SceneMesh_getNumOfIndexAll(cdata);
                return _return_value_;
            }
        }
        public virtual Buffer getVerticesAll()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getVerticesAll(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual Buffer getNormalsAll()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getNormalsAll(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual Buffer getIndicesAll()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getIndicesAll(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual int getNumOfVertexIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SceneMesh_getNumOfVertexIncremental(cdata);
                return _return_value_;
            }
        }
        public virtual int getNumOfIndexIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SceneMesh_getNumOfIndexIncremental(cdata);
                return _return_value_;
            }
        }
        public virtual Buffer getVerticesIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getVerticesIncremental(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual Buffer getNormalsIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getNormalsIncremental(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual Buffer getIndicesIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getIndicesIncremental(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual List<BlockInfo> getBlocksInfoIncremental()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SceneMesh_getBlocksInfoIncremental(cdata, out _return_value_);
                return Detail.ListOfBlockInfo_from_c(ar, _return_value_);
            }
        }
        public virtual float getBlockDimentionInMeters()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SceneMesh_getBlockDimentionInMeters(cdata);
                return _return_value_;
            }
        }
    }

    public enum SurfaceTrackingStatus
    {
        NotTracking = 0,
        BadTracking = 1,
        GoodTracking = 2,
    }

    public class SurfaceTrackerResult : FrameFilterResult
    {
        internal SurfaceTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SurfaceTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new SurfaceTrackerResult Clone()
        {
            return (SurfaceTrackerResult)(CloneObject());
        }
        public virtual Matrix44F transform()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SurfaceTrackerResult_transform(cdata);
                return _return_value_;
            }
        }
        public virtual SurfaceTrackingStatus status()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SurfaceTrackerResult_status(cdata);
                return _return_value_;
            }
        }
    }

    public class SurfaceTracker : RefBase
    {
        internal SurfaceTracker(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SurfaceTracker(cdata_new, deleter_, retainer_);
        }
        public new SurfaceTracker Clone()
        {
            return (SurfaceTracker)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SurfaceTracker_isAvailable();
                return _return_value_;
            }
        }
        public virtual InputFrameSink inputFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SurfaceTracker_inputFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SurfaceTracker_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static SurfaceTracker create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SurfaceTracker_create(out _return_value_);
                return Detail.Object_from_c<SurfaceTracker>(_return_value_, Detail.easyar_SurfaceTracker__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SurfaceTracker_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SurfaceTracker_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SurfaceTracker_close(cdata);
            }
        }
        public virtual void alignTargetToCameraImagePoint(Vec2F cameraImagePoint)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SurfaceTracker_alignTargetToCameraImagePoint(cdata, cameraImagePoint);
            }
        }
    }

    public enum MotionTrackingStatus
    {
        NotTracking = 0,
        BadTracking = 1,
        GoodTracking = 2,
    }

    public class MotionTrackerResult : FrameFilterResult
    {
        internal MotionTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new MotionTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new MotionTrackerResult Clone()
        {
            return (MotionTrackerResult)(CloneObject());
        }
        public virtual Matrix44F transform()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_MotionTrackerResult_transform(cdata);
                return _return_value_;
            }
        }
        public virtual MotionTrackingStatus status()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_MotionTrackerResult_status(cdata);
                return _return_value_;
            }
        }
    }

    public class MotionTracker : RefBase
    {
        internal MotionTracker(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new MotionTracker(cdata_new, deleter_, retainer_);
        }
        public new MotionTracker Clone()
        {
            return (MotionTracker)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_MotionTracker_isAvailable();
                return _return_value_;
            }
        }
        public virtual InputFrameSink inputFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTracker_inputFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTracker_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static MotionTracker create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTracker_create(out _return_value_);
                return Detail.Object_from_c<MotionTracker>(_return_value_, Detail.easyar_MotionTracker__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_MotionTracker_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_MotionTracker_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_MotionTracker_close(cdata);
            }
        }
    }

    public class MotionTrackerOutputFrameToInputFrameAdapter : RefBase
    {
        internal MotionTrackerOutputFrameToInputFrameAdapter(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new MotionTrackerOutputFrameToInputFrameAdapter(cdata_new, deleter_, retainer_);
        }
        public new MotionTrackerOutputFrameToInputFrameAdapter Clone()
        {
            return (MotionTrackerOutputFrameToInputFrameAdapter)(CloneObject());
        }
        public virtual OutputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTrackerOutputFrameToInputFrameAdapter_input(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSink>(_return_value_, Detail.easyar_OutputFrameSink__typeName);
            }
        }
        public virtual InputFrameSource output()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTrackerOutputFrameToInputFrameAdapter_output(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSource>(_return_value_, Detail.easyar_InputFrameSource__typeName);
            }
        }
        public static MotionTrackerOutputFrameToInputFrameAdapter create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_MotionTrackerOutputFrameToInputFrameAdapter_create(out _return_value_);
                return Detail.Object_from_c<MotionTrackerOutputFrameToInputFrameAdapter>(_return_value_, Detail.easyar_MotionTrackerOutputFrameToInputFrameAdapter__typeName);
            }
        }
    }

    public class ImageTargetParameters : RefBase
    {
        internal ImageTargetParameters(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ImageTargetParameters(cdata_new, deleter_, retainer_);
        }
        public new ImageTargetParameters Clone()
        {
            return (ImageTargetParameters)(CloneObject());
        }
        public ImageTargetParameters() : base(IntPtr.Zero, Detail.easyar_ImageTargetParameters__dtor, Detail.easyar_ImageTargetParameters__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_ImageTargetParameters__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual Image image()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTargetParameters_image(cdata, out _return_value_);
                return Detail.Object_from_c<Image>(_return_value_, Detail.easyar_Image__typeName);
            }
        }
        public virtual void setImage(Image image)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTargetParameters_setImage(cdata, image.cdata);
            }
        }
        public virtual string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTargetParameters_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTargetParameters_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public virtual string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTargetParameters_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setUid(string uid)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTargetParameters_setUid(cdata, Detail.String_to_c(ar, uid));
            }
        }
        public virtual string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTargetParameters_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setMeta(string meta)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTargetParameters_setMeta(cdata, Detail.String_to_c(ar, meta));
            }
        }
        public virtual float scale()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTargetParameters_scale(cdata);
                return _return_value_;
            }
        }
        public virtual void setScale(float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTargetParameters_setScale(cdata, scale);
            }
        }
    }

    public class ImageTarget : Target
    {
        internal ImageTarget(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ImageTarget(cdata_new, deleter_, retainer_);
        }
        public new ImageTarget Clone()
        {
            return (ImageTarget)(CloneObject());
        }
        public ImageTarget() : base(IntPtr.Zero, Detail.easyar_ImageTarget__dtor, Detail.easyar_ImageTarget__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_ImageTarget__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public static Optional<ImageTarget> createFromParameters(ImageTargetParameters parameters)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfImageTarget);
                Detail.easyar_ImageTarget_createFromParameters(parameters.cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ImageTarget>(p.value, Detail.easyar_ImageTarget__typeName) : Optional<ImageTarget>.Empty);
            }
        }
        public static Optional<ImageTarget> createFromTargetFile(string path, StorageType storageType)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfImageTarget);
                Detail.easyar_ImageTarget_createFromTargetFile(Detail.String_to_c(ar, path), storageType, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ImageTarget>(p.value, Detail.easyar_ImageTarget__typeName) : Optional<ImageTarget>.Empty);
            }
        }
        public static Optional<ImageTarget> createFromTargetData(Buffer buffer)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfImageTarget);
                Detail.easyar_ImageTarget_createFromTargetData(buffer.cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ImageTarget>(p.value, Detail.easyar_ImageTarget__typeName) : Optional<ImageTarget>.Empty);
            }
        }
        public virtual bool save(string path)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTarget_save(cdata, Detail.String_to_c(ar, path));
                return _return_value_;
            }
        }
        public static Optional<ImageTarget> createFromImageFile(string path, StorageType storageType, string name, string uid, string meta, float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfImageTarget);
                Detail.easyar_ImageTarget_createFromImageFile(Detail.String_to_c(ar, path), storageType, Detail.String_to_c(ar, name), Detail.String_to_c(ar, uid), Detail.String_to_c(ar, meta), scale, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<ImageTarget>(p.value, Detail.easyar_ImageTarget__typeName) : Optional<ImageTarget>.Empty);
            }
        }
        public static List<ImageTarget> setupAll(string path, StorageType storageType)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTarget_setupAll(Detail.String_to_c(ar, path), storageType, out _return_value_);
                return Detail.ListOfImageTarget_from_c(ar, _return_value_);
            }
        }
        public virtual float scale()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTarget_scale(cdata);
                return _return_value_;
            }
        }
        public virtual float aspectRatio()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTarget_aspectRatio(cdata);
                return _return_value_;
            }
        }
        public virtual bool setScale(float scale)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTarget_setScale(cdata, scale);
                return _return_value_;
            }
        }
        public virtual List<Image> images()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTarget_images(cdata, out _return_value_);
                return Detail.ListOfImage_from_c(ar, _return_value_);
            }
        }
        public override int runtimeID()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTarget_runtimeID(cdata);
                return _return_value_;
            }
        }
        public override string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTarget_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTarget_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTarget_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public override string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTarget_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public override void setMeta(string data)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTarget_setMeta(cdata, Detail.String_to_c(ar, data));
            }
        }
    }

    public enum ImageTrackerMode
    {
        PreferQuality = 0,
        PreferPerformance = 1,
    }

    public class ImageTrackerResult : TargetTrackerResult
    {
        internal ImageTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ImageTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new ImageTrackerResult Clone()
        {
            return (ImageTrackerResult)(CloneObject());
        }
        public override List<TargetInstance> targetInstances()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTrackerResult_targetInstances(cdata, out _return_value_);
                return Detail.ListOfTargetInstance_from_c(ar, _return_value_);
            }
        }
        public override void setTargetInstances(List<TargetInstance> instances)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTrackerResult_setTargetInstances(cdata, Detail.ListOfTargetInstance_to_c(ar, instances));
            }
        }
    }

    public class ImageTracker : RefBase
    {
        internal ImageTracker(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ImageTracker(cdata_new, deleter_, retainer_);
        }
        public new ImageTracker Clone()
        {
            return (ImageTracker)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTracker_isAvailable();
                return _return_value_;
            }
        }
        public virtual FeedbackFrameSink feedbackFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTracker_feedbackFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSink>(_return_value_, Detail.easyar_FeedbackFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTracker_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static ImageTracker create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTracker_create(out _return_value_);
                return Detail.Object_from_c<ImageTracker>(_return_value_, Detail.easyar_ImageTracker__typeName);
            }
        }
        public static ImageTracker createWithMode(ImageTrackerMode trackMode)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTracker_createWithMode(trackMode, out _return_value_);
                return Detail.Object_from_c<ImageTracker>(_return_value_, Detail.easyar_ImageTracker__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTracker_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTracker_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTracker_close(cdata);
            }
        }
        public virtual void loadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTracker_loadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual void unloadTarget(Target target, CallbackScheduler callbackScheduler, Action<Target, bool> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_ImageTracker_unloadTarget(cdata, target.cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromTargetAndBool_to_c(callback));
            }
        }
        public virtual List<Target> targets()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImageTracker_targets(cdata, out _return_value_);
                return Detail.ListOfTarget_from_c(ar, _return_value_);
            }
        }
        public virtual bool setSimultaneousNum(int num)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTracker_setSimultaneousNum(cdata, num);
                return _return_value_;
            }
        }
        public virtual int simultaneousNum()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_ImageTracker_simultaneousNum(cdata);
                return _return_value_;
            }
        }
    }

    public class Recorder : RefBase
    {
        internal Recorder(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new Recorder(cdata_new, deleter_, retainer_);
        }
        public new Recorder Clone()
        {
            return (Recorder)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Recorder_isAvailable();
                return _return_value_;
            }
        }
        public static void requestPermissions(CallbackScheduler callbackScheduler, Optional<Action<PermissionStatus, string>> permissionCallback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Recorder_requestPermissions(callbackScheduler.cdata, permissionCallback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromPermissionStatusAndString { has_value = true, value = Detail.FunctorOfVoidFromPermissionStatusAndString_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromPermissionStatusAndString { has_value = false, value = default(Detail.FunctorOfVoidFromPermissionStatusAndString) }));
            }
        }
        public static Recorder create(RecorderConfiguration config, CallbackScheduler callbackScheduler, Optional<Action<RecordStatus, string>> statusCallback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Recorder_create(config.cdata, callbackScheduler.cdata, statusCallback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromRecordStatusAndString { has_value = true, value = Detail.FunctorOfVoidFromRecordStatusAndString_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromRecordStatusAndString { has_value = false, value = default(Detail.FunctorOfVoidFromRecordStatusAndString) }), out _return_value_);
                return Detail.Object_from_c<Recorder>(_return_value_, Detail.easyar_Recorder__typeName);
            }
        }
        public virtual void start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Recorder_start(cdata);
            }
        }
        public virtual void updateFrame(TextureId texture, int width, int height)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Recorder_updateFrame(cdata, texture.cdata, width, height);
            }
        }
        public virtual bool stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Recorder_stop(cdata);
                return _return_value_;
            }
        }
    }

    public enum RecordProfile
    {
        Quality_1080P_Low = 0x00000001,
        Quality_1080P_Middle = 0x00000002,
        Quality_1080P_High = 0x00000004,
        Quality_720P_Low = 0x00000008,
        Quality_720P_Middle = 0x00000010,
        Quality_720P_High = 0x00000020,
        Quality_480P_Low = 0x00000040,
        Quality_480P_Middle = 0x00000080,
        Quality_480P_High = 0x00000100,
        Quality_Default = 0x00000010,
    }

    public enum RecordVideoSize
    {
        Vid1080p = 0x00000002,
        Vid720p = 0x00000010,
        Vid480p = 0x00000080,
    }

    public enum RecordZoomMode
    {
        NoZoomAndClip = 0x00000000,
        ZoomInWithAllContent = 0x00000001,
    }

    public enum RecordVideoOrientation
    {
        Landscape = 0x00000000,
        Portrait = 0x00000001,
    }

    public enum RecordStatus
    {
        OnStarted = 0x00000002,
        OnStopped = 0x00000004,
        FailedToStart = 0x00000202,
        FileSucceeded = 0x00000400,
        FileFailed = 0x00000401,
        LogInfo = 0x00000800,
        LogError = 0x00001000,
    }

    public class RecorderConfiguration : RefBase
    {
        internal RecorderConfiguration(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new RecorderConfiguration(cdata_new, deleter_, retainer_);
        }
        public new RecorderConfiguration Clone()
        {
            return (RecorderConfiguration)(CloneObject());
        }
        public RecorderConfiguration() : base(IntPtr.Zero, Detail.easyar_RecorderConfiguration__dtor, Detail.easyar_RecorderConfiguration__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_RecorderConfiguration__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual void setOutputFile(string path)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setOutputFile(cdata, Detail.String_to_c(ar, path));
            }
        }
        public virtual bool setProfile(RecordProfile profile)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_RecorderConfiguration_setProfile(cdata, profile);
                return _return_value_;
            }
        }
        public virtual void setVideoSize(RecordVideoSize framesize)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setVideoSize(cdata, framesize);
            }
        }
        public virtual void setVideoBitrate(int bitrate)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setVideoBitrate(cdata, bitrate);
            }
        }
        public virtual void setChannelCount(int count)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setChannelCount(cdata, count);
            }
        }
        public virtual void setAudioSampleRate(int samplerate)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setAudioSampleRate(cdata, samplerate);
            }
        }
        public virtual void setAudioBitrate(int bitrate)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setAudioBitrate(cdata, bitrate);
            }
        }
        public virtual void setVideoOrientation(RecordVideoOrientation mode)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setVideoOrientation(cdata, mode);
            }
        }
        public virtual void setZoomMode(RecordZoomMode mode)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_RecorderConfiguration_setZoomMode(cdata, mode);
            }
        }
    }

    public enum MapTrackingStatus
    {
        NotTracking = 0,
        Tracking = 1,
    }

    public class SparseSpatialMapResult : FrameFilterResult
    {
        internal SparseSpatialMapResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SparseSpatialMapResult(cdata_new, deleter_, retainer_);
        }
        public new SparseSpatialMapResult Clone()
        {
            return (SparseSpatialMapResult)(CloneObject());
        }
        public virtual MapTrackingStatus getMapTrackingStatus()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapResult_getMapTrackingStatus(cdata);
                return _return_value_;
            }
        }
        public virtual Matrix44F getVioPose()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapResult_getVioPose(cdata);
                return _return_value_;
            }
        }
        public virtual Matrix44F getMapPose()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapResult_getMapPose(cdata);
                return _return_value_;
            }
        }
        public virtual bool getLocalizedStatus()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapResult_getLocalizedStatus(cdata);
                return _return_value_;
            }
        }
        public virtual string getCurrentLocalizedMapID()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMapResult_getCurrentLocalizedMapID(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
    }

    public enum PlaneType
    {
        Horizontal = 0,
        Vertical = 1,
    }

    public class PlaneData : RefBase
    {
        internal PlaneData(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new PlaneData(cdata_new, deleter_, retainer_);
        }
        public new PlaneData Clone()
        {
            return (PlaneData)(CloneObject());
        }
        public PlaneData() : base(IntPtr.Zero, Detail.easyar_PlaneData__dtor, Detail.easyar_PlaneData__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_PlaneData__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual PlaneType getType()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_PlaneData_getType(cdata);
                return _return_value_;
            }
        }
        public virtual Matrix44F getPose()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_PlaneData_getPose(cdata);
                return _return_value_;
            }
        }
        public virtual float getExtentX()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_PlaneData_getExtentX(cdata);
                return _return_value_;
            }
        }
        public virtual float getExtentZ()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_PlaneData_getExtentZ(cdata);
                return _return_value_;
            }
        }
    }

    public enum LocalizeConfig
    {
        UntilSuccess = 0,
        Keep = 1,
        Once = 2,
        KeepUpdate = 3,
    }

    public enum MapConfig
    {
        NotExtend = 0,
        Extend = 1,
    }

    public class SparseSpatialMapConfig : RefBase
    {
        internal SparseSpatialMapConfig(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SparseSpatialMapConfig(cdata_new, deleter_, retainer_);
        }
        public new SparseSpatialMapConfig Clone()
        {
            return (SparseSpatialMapConfig)(CloneObject());
        }
        public SparseSpatialMapConfig() : base(IntPtr.Zero, Detail.easyar_SparseSpatialMapConfig__dtor, Detail.easyar_SparseSpatialMapConfig__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_SparseSpatialMapConfig__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual void setLocalizeConfig(LocalizeConfig @value)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SparseSpatialMapConfig_setLocalizeConfig(cdata, @value);
            }
        }
        public virtual LocalizeConfig getLocalizeConfig()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapConfig_getLocalizeConfig(cdata);
                return _return_value_;
            }
        }
        public virtual void setMapConfig(MapConfig @value)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SparseSpatialMapConfig_setMapConfig(cdata, @value);
            }
        }
        public virtual MapConfig getMapConfig()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMapConfig_getMapConfig(cdata);
                return _return_value_;
            }
        }
    }

    public class SparseSpatialMap : RefBase
    {
        internal SparseSpatialMap(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SparseSpatialMap(cdata_new, deleter_, retainer_);
        }
        public new SparseSpatialMap Clone()
        {
            return (SparseSpatialMap)(CloneObject());
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_isAvailable();
                return _return_value_;
            }
        }
        public virtual InputFrameSink inputFrameSink()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_inputFrameSink(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource outputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_outputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static SparseSpatialMap create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_create(out _return_value_);
                return Detail.Object_from_c<SparseSpatialMap>(_return_value_, Detail.easyar_SparseSpatialMap__typeName);
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SparseSpatialMap_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SparseSpatialMap_close(cdata);
            }
        }
        public virtual Buffer getPointCloudBuffer()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_getPointCloudBuffer(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual List<PlaneData> getMapPlanes()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_getMapPlanes(cdata, out _return_value_);
                return Detail.ListOfPlaneData_from_c(ar, _return_value_);
            }
        }
        public virtual List<Vec3F> hitTestAgainstPointCloud(Vec2F cameraImagePoint)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_hitTestAgainstPointCloud(cdata, cameraImagePoint, out _return_value_);
                return Detail.ListOfVec3F_from_c(ar, _return_value_);
            }
        }
        public virtual List<Vec3F> hitTestAgainstPlanes(Vec2F cameraImagePoint)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_hitTestAgainstPlanes(cdata, cameraImagePoint, out _return_value_);
                return Detail.ListOfVec3F_from_c(ar, _return_value_);
            }
        }
        public virtual bool saveMap(CallbackScheduler callbackScheduler, Action<Optional<Buffer>> resultCallBack)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_saveMap(cdata, callbackScheduler.cdata, Detail.FunctorOfVoidFromOptionalOfBuffer_to_c(resultCallBack));
                return _return_value_;
            }
        }
        public virtual bool loadMap(Buffer pMapData, string mapID, CallbackScheduler callbackScheduler, Optional<Action<bool>> resultCallBack)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_loadMap(cdata, pMapData.cdata, Detail.String_to_c(ar, mapID), callbackScheduler.cdata, resultCallBack.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromBool { has_value = true, value = Detail.FunctorOfVoidFromBool_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromBool { has_value = false, value = default(Detail.FunctorOfVoidFromBool) }));
                return _return_value_;
            }
        }
        public virtual bool unloadMap(string mapID, CallbackScheduler callbackScheduler, Optional<Action<bool>> resultCallBack)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_unloadMap(cdata, Detail.String_to_c(ar, mapID), callbackScheduler.cdata, resultCallBack.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromBool { has_value = true, value = Detail.FunctorOfVoidFromBool_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromBool { has_value = false, value = default(Detail.FunctorOfVoidFromBool) }));
                return _return_value_;
            }
        }
        public virtual void setConfig(SparseSpatialMapConfig config)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SparseSpatialMap_setConfig(cdata, config.cdata);
            }
        }
        public virtual SparseSpatialMapConfig getConfig()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_SparseSpatialMap_getConfig(cdata, out _return_value_);
                return Detail.Object_from_c<SparseSpatialMapConfig>(_return_value_, Detail.easyar_SparseSpatialMapConfig__typeName);
            }
        }
        public virtual bool startLocalize()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_startLocalize(cdata);
                return _return_value_;
            }
        }
        public virtual bool stopLocalize()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_SparseSpatialMap_stopLocalize(cdata);
                return _return_value_;
            }
        }
    }

    public class ImageHelper
    {
        public static Optional<Image> decode(Buffer buffer)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfImage);
                Detail.easyar_ImageHelper_decode(buffer.cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<Image>(p.value, Detail.easyar_Image__typeName) : Optional<Image>.Empty);
            }
        }
    }

    public class CallbackScheduler : RefBase
    {
        internal CallbackScheduler(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CallbackScheduler(cdata_new, deleter_, retainer_);
        }
        public new CallbackScheduler Clone()
        {
            return (CallbackScheduler)(CloneObject());
        }
    }

    public class DelayedCallbackScheduler : CallbackScheduler
    {
        internal DelayedCallbackScheduler(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new DelayedCallbackScheduler(cdata_new, deleter_, retainer_);
        }
        public new DelayedCallbackScheduler Clone()
        {
            return (DelayedCallbackScheduler)(CloneObject());
        }
        public DelayedCallbackScheduler() : base(IntPtr.Zero, Detail.easyar_DelayedCallbackScheduler__dtor, Detail.easyar_DelayedCallbackScheduler__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_DelayedCallbackScheduler__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual bool runOne()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_DelayedCallbackScheduler_runOne(cdata);
                return _return_value_;
            }
        }
    }

    public class ImmediateCallbackScheduler : CallbackScheduler
    {
        internal ImmediateCallbackScheduler(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new ImmediateCallbackScheduler(cdata_new, deleter_, retainer_);
        }
        public new ImmediateCallbackScheduler Clone()
        {
            return (ImmediateCallbackScheduler)(CloneObject());
        }
        public static ImmediateCallbackScheduler getDefault()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_ImmediateCallbackScheduler_getDefault(out _return_value_);
                return Detail.Object_from_c<ImmediateCallbackScheduler>(_return_value_, Detail.easyar_ImmediateCallbackScheduler__typeName);
            }
        }
    }

    public enum CameraDeviceFocusMode
    {
        Normal = 0,
        Continousauto = 2,
        Infinity = 3,
        Macro = 4,
        Medium = 5,
    }

    public enum AndroidCameraApiType
    {
        Camera1 = 0,
        Camera2 = 1,
    }

    public enum CameraDevicePresetProfile
    {
        Photo = 0,
        High = 1,
        Medium = 2,
        Low = 3,
    }

    public enum CameraState
    {
        Unknown = 0x00000000,
        Disconnected = 0x00000001,
        Preempted = 0x00000002,
    }

    public class CameraDevice : RefBase
    {
        internal CameraDevice(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CameraDevice(cdata_new, deleter_, retainer_);
        }
        public new CameraDevice Clone()
        {
            return (CameraDevice)(CloneObject());
        }
        public CameraDevice() : base(IntPtr.Zero, Detail.easyar_CameraDevice__dtor, Detail.easyar_CameraDevice__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_CameraDevice__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public static bool isAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_isAvailable();
                return _return_value_;
            }
        }
        public virtual AndroidCameraApiType androidCameraApiType()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_androidCameraApiType(cdata);
                return _return_value_;
            }
        }
        public virtual void setAndroidCameraApiType(AndroidCameraApiType type)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_setAndroidCameraApiType(cdata, type);
            }
        }
        public virtual int bufferCapacity()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_bufferCapacity(cdata);
                return _return_value_;
            }
        }
        public virtual void setBufferCapacity(int capacity)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_setBufferCapacity(cdata, capacity);
            }
        }
        public virtual InputFrameSource inputFrameSource()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CameraDevice_inputFrameSource(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSource>(_return_value_, Detail.easyar_InputFrameSource__typeName);
            }
        }
        public virtual void setStateChangedCallback(CallbackScheduler callbackScheduler, Optional<Action<CameraState>> stateChangedCallback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_setStateChangedCallback(cdata, callbackScheduler.cdata, stateChangedCallback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromCameraState { has_value = true, value = Detail.FunctorOfVoidFromCameraState_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromCameraState { has_value = false, value = default(Detail.FunctorOfVoidFromCameraState) }));
            }
        }
        public static void requestPermissions(CallbackScheduler callbackScheduler, Optional<Action<PermissionStatus, string>> permissionCallback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_requestPermissions(callbackScheduler.cdata, permissionCallback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromPermissionStatusAndString { has_value = true, value = Detail.FunctorOfVoidFromPermissionStatusAndString_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromPermissionStatusAndString { has_value = false, value = default(Detail.FunctorOfVoidFromPermissionStatusAndString) }));
            }
        }
        public virtual bool openWithIndex(int cameraIndex)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_openWithIndex(cdata, cameraIndex);
                return _return_value_;
            }
        }
        public virtual bool openWithType(CameraDeviceType type)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_openWithType(cdata, type);
                return _return_value_;
            }
        }
        public virtual bool start()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_start(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_stop(cdata);
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_close(cdata);
            }
        }
        public virtual CameraDeviceType type()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_type(cdata);
                return _return_value_;
            }
        }
        public virtual CameraParameters cameraParameters()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CameraDevice_cameraParameters(cdata, out _return_value_);
                return Detail.Object_from_c<CameraParameters>(_return_value_, Detail.easyar_CameraParameters__typeName);
            }
        }
        public virtual void setCameraParameters(CameraParameters cameraParameters)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_CameraDevice_setCameraParameters(cdata, cameraParameters.cdata);
            }
        }
        public virtual Vec2I size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_size(cdata);
                return _return_value_;
            }
        }
        public virtual int supportedSizeCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_supportedSizeCount(cdata);
                return _return_value_;
            }
        }
        public virtual Vec2I supportedSize(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_supportedSize(cdata, index);
                return _return_value_;
            }
        }
        public virtual bool setSize(Vec2I size)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_setSize(cdata, size);
                return _return_value_;
            }
        }
        public virtual int supportedFrameRateRangeCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_supportedFrameRateRangeCount(cdata);
                return _return_value_;
            }
        }
        public virtual float supportedFrameRateRangeLower(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_supportedFrameRateRangeLower(cdata, index);
                return _return_value_;
            }
        }
        public virtual float supportedFrameRateRangeUpper(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_supportedFrameRateRangeUpper(cdata, index);
                return _return_value_;
            }
        }
        public virtual int frameRateRange()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_frameRateRange(cdata);
                return _return_value_;
            }
        }
        public virtual bool setFrameRateRange(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_setFrameRateRange(cdata, index);
                return _return_value_;
            }
        }
        public virtual bool setFlashTorchMode(bool on)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_setFlashTorchMode(cdata, on);
                return _return_value_;
            }
        }
        public virtual bool setFocusMode(CameraDeviceFocusMode focusMode)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_setFocusMode(cdata, focusMode);
                return _return_value_;
            }
        }
        public virtual bool autoFocus()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_autoFocus(cdata);
                return _return_value_;
            }
        }
        public virtual bool setPresentProfile(CameraDevicePresetProfile profile)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraDevice_setPresentProfile(cdata, profile);
                return _return_value_;
            }
        }
    }

    public enum CameraDevicePreference
    {
        PreferObjectSensing = 0,
        PreferSurfaceTracking = 1,
        PreferMotionTracking = 2,
    }

    public class CameraDeviceSelector
    {
        public static CameraDevice createCameraDevice(CameraDevicePreference preference)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CameraDeviceSelector_createCameraDevice(preference, out _return_value_);
                return Detail.Object_from_c<CameraDevice>(_return_value_, Detail.easyar_CameraDevice__typeName);
            }
        }
    }

    public class SignalSink : RefBase
    {
        internal SignalSink(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SignalSink(cdata_new, deleter_, retainer_);
        }
        public new SignalSink Clone()
        {
            return (SignalSink)(CloneObject());
        }
        public virtual void handle()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SignalSink_handle(cdata);
            }
        }
    }

    public class SignalSource : RefBase
    {
        internal SignalSource(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new SignalSource(cdata_new, deleter_, retainer_);
        }
        public new SignalSource Clone()
        {
            return (SignalSource)(CloneObject());
        }
        public virtual void setHandler(Optional<Action> handler)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SignalSource_setHandler(cdata, handler.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoid { has_value = true, value = Detail.FunctorOfVoid_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoid { has_value = false, value = default(Detail.FunctorOfVoid) }));
            }
        }
        public virtual void connect(SignalSink sink)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SignalSource_connect(cdata, sink.cdata);
            }
        }
        public virtual void disconnect()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_SignalSource_disconnect(cdata);
            }
        }
    }

    public class InputFrameSink : RefBase
    {
        internal InputFrameSink(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameSink(cdata_new, deleter_, retainer_);
        }
        public new InputFrameSink Clone()
        {
            return (InputFrameSink)(CloneObject());
        }
        public virtual void handle(InputFrame inputData)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_InputFrameSink_handle(cdata, inputData.cdata);
            }
        }
    }

    public class InputFrameSource : RefBase
    {
        internal InputFrameSource(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameSource(cdata_new, deleter_, retainer_);
        }
        public new InputFrameSource Clone()
        {
            return (InputFrameSource)(CloneObject());
        }
        public virtual void setHandler(Optional<Action<InputFrame>> handler)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_InputFrameSource_setHandler(cdata, handler.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromInputFrame { has_value = true, value = Detail.FunctorOfVoidFromInputFrame_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromInputFrame { has_value = false, value = default(Detail.FunctorOfVoidFromInputFrame) }));
            }
        }
        public virtual void connect(InputFrameSink sink)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_InputFrameSource_connect(cdata, sink.cdata);
            }
        }
        public virtual void disconnect()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_InputFrameSource_disconnect(cdata);
            }
        }
    }

    public class OutputFrameSink : RefBase
    {
        internal OutputFrameSink(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrameSink(cdata_new, deleter_, retainer_);
        }
        public new OutputFrameSink Clone()
        {
            return (OutputFrameSink)(CloneObject());
        }
        public virtual void handle(OutputFrame inputData)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_OutputFrameSink_handle(cdata, inputData.cdata);
            }
        }
    }

    public class OutputFrameSource : RefBase
    {
        internal OutputFrameSource(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrameSource(cdata_new, deleter_, retainer_);
        }
        public new OutputFrameSource Clone()
        {
            return (OutputFrameSource)(CloneObject());
        }
        public virtual void setHandler(Optional<Action<OutputFrame>> handler)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_OutputFrameSource_setHandler(cdata, handler.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromOutputFrame { has_value = true, value = Detail.FunctorOfVoidFromOutputFrame_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromOutputFrame { has_value = false, value = default(Detail.FunctorOfVoidFromOutputFrame) }));
            }
        }
        public virtual void connect(OutputFrameSink sink)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_OutputFrameSource_connect(cdata, sink.cdata);
            }
        }
        public virtual void disconnect()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_OutputFrameSource_disconnect(cdata);
            }
        }
    }

    public class FeedbackFrameSink : RefBase
    {
        internal FeedbackFrameSink(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new FeedbackFrameSink(cdata_new, deleter_, retainer_);
        }
        public new FeedbackFrameSink Clone()
        {
            return (FeedbackFrameSink)(CloneObject());
        }
        public virtual void handle(FeedbackFrame inputData)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_FeedbackFrameSink_handle(cdata, inputData.cdata);
            }
        }
    }

    public class FeedbackFrameSource : RefBase
    {
        internal FeedbackFrameSource(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new FeedbackFrameSource(cdata_new, deleter_, retainer_);
        }
        public new FeedbackFrameSource Clone()
        {
            return (FeedbackFrameSource)(CloneObject());
        }
        public virtual void setHandler(Optional<Action<FeedbackFrame>> handler)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_FeedbackFrameSource_setHandler(cdata, handler.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromFeedbackFrame { has_value = true, value = Detail.FunctorOfVoidFromFeedbackFrame_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromFeedbackFrame { has_value = false, value = default(Detail.FunctorOfVoidFromFeedbackFrame) }));
            }
        }
        public virtual void connect(FeedbackFrameSink sink)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_FeedbackFrameSource_connect(cdata, sink.cdata);
            }
        }
        public virtual void disconnect()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_FeedbackFrameSource_disconnect(cdata);
            }
        }
    }

    public class InputFrameFork : RefBase
    {
        internal InputFrameFork(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameFork(cdata_new, deleter_, retainer_);
        }
        public new InputFrameFork Clone()
        {
            return (InputFrameFork)(CloneObject());
        }
        public virtual InputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameFork_input(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual InputFrameSource output(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameFork_output(cdata, index, out _return_value_);
                return Detail.Object_from_c<InputFrameSource>(_return_value_, Detail.easyar_InputFrameSource__typeName);
            }
        }
        public virtual int outputCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrameFork_outputCount(cdata);
                return _return_value_;
            }
        }
        public static InputFrameFork create(int outputCount)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameFork_create(outputCount, out _return_value_);
                return Detail.Object_from_c<InputFrameFork>(_return_value_, Detail.easyar_InputFrameFork__typeName);
            }
        }
    }

    public class OutputFrameFork : RefBase
    {
        internal OutputFrameFork(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrameFork(cdata_new, deleter_, retainer_);
        }
        public new OutputFrameFork Clone()
        {
            return (OutputFrameFork)(CloneObject());
        }
        public virtual OutputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameFork_input(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSink>(_return_value_, Detail.easyar_OutputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource output(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameFork_output(cdata, index, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public virtual int outputCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_OutputFrameFork_outputCount(cdata);
                return _return_value_;
            }
        }
        public static OutputFrameFork create(int outputCount)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameFork_create(outputCount, out _return_value_);
                return Detail.Object_from_c<OutputFrameFork>(_return_value_, Detail.easyar_OutputFrameFork__typeName);
            }
        }
    }

    public class OutputFrameJoin : RefBase
    {
        internal OutputFrameJoin(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrameJoin(cdata_new, deleter_, retainer_);
        }
        public new OutputFrameJoin Clone()
        {
            return (OutputFrameJoin)(CloneObject());
        }
        public virtual OutputFrameSink input(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameJoin_input(cdata, index, out _return_value_);
                return Detail.Object_from_c<OutputFrameSink>(_return_value_, Detail.easyar_OutputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource output()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameJoin_output(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public virtual int inputCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_OutputFrameJoin_inputCount(cdata);
                return _return_value_;
            }
        }
        public static OutputFrameJoin create(int inputCount)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameJoin_create(inputCount, out _return_value_);
                return Detail.Object_from_c<OutputFrameJoin>(_return_value_, Detail.easyar_OutputFrameJoin__typeName);
            }
        }
        public static OutputFrameJoin createWithJoiner(int inputCount, Func<List<OutputFrame>, OutputFrame> joiner)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameJoin_createWithJoiner(inputCount, Detail.FunctorOfOutputFrameFromListOfOutputFrame_to_c(joiner), out _return_value_);
                return Detail.Object_from_c<OutputFrameJoin>(_return_value_, Detail.easyar_OutputFrameJoin__typeName);
            }
        }
    }

    public class FeedbackFrameFork : RefBase
    {
        internal FeedbackFrameFork(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new FeedbackFrameFork(cdata_new, deleter_, retainer_);
        }
        public new FeedbackFrameFork Clone()
        {
            return (FeedbackFrameFork)(CloneObject());
        }
        public virtual FeedbackFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_FeedbackFrameFork_input(cdata, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSink>(_return_value_, Detail.easyar_FeedbackFrameSink__typeName);
            }
        }
        public virtual FeedbackFrameSource output(int index)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_FeedbackFrameFork_output(cdata, index, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSource>(_return_value_, Detail.easyar_FeedbackFrameSource__typeName);
            }
        }
        public virtual int outputCount()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_FeedbackFrameFork_outputCount(cdata);
                return _return_value_;
            }
        }
        public static FeedbackFrameFork create(int outputCount)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_FeedbackFrameFork_create(outputCount, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameFork>(_return_value_, Detail.easyar_FeedbackFrameFork__typeName);
            }
        }
    }

    public class InputFrameThrottler : RefBase
    {
        internal InputFrameThrottler(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameThrottler(cdata_new, deleter_, retainer_);
        }
        public new InputFrameThrottler Clone()
        {
            return (InputFrameThrottler)(CloneObject());
        }
        public virtual InputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameThrottler_input(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual InputFrameSource output()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameThrottler_output(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSource>(_return_value_, Detail.easyar_InputFrameSource__typeName);
            }
        }
        public virtual SignalSink signalInput()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameThrottler_signalInput(cdata, out _return_value_);
                return Detail.Object_from_c<SignalSink>(_return_value_, Detail.easyar_SignalSink__typeName);
            }
        }
        public static InputFrameThrottler create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameThrottler_create(out _return_value_);
                return Detail.Object_from_c<InputFrameThrottler>(_return_value_, Detail.easyar_InputFrameThrottler__typeName);
            }
        }
    }

    public class OutputFrameBuffer : RefBase
    {
        internal OutputFrameBuffer(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrameBuffer(cdata_new, deleter_, retainer_);
        }
        public new OutputFrameBuffer Clone()
        {
            return (OutputFrameBuffer)(CloneObject());
        }
        public virtual OutputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameBuffer_input(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSink>(_return_value_, Detail.easyar_OutputFrameSink__typeName);
            }
        }
        public virtual SignalSource signalOutput()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameBuffer_signalOutput(cdata, out _return_value_);
                return Detail.Object_from_c<SignalSource>(_return_value_, Detail.easyar_SignalSource__typeName);
            }
        }
        public virtual Optional<OutputFrame> peek()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfOutputFrame);
                Detail.easyar_OutputFrameBuffer_peek(cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<OutputFrame>(p.value, Detail.easyar_OutputFrame__typeName) : Optional<OutputFrame>.Empty);
            }
        }
        public static OutputFrameBuffer create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrameBuffer_create(out _return_value_);
                return Detail.Object_from_c<OutputFrameBuffer>(_return_value_, Detail.easyar_OutputFrameBuffer__typeName);
            }
        }
    }

    public class InputFrameToOutputFrameAdapter : RefBase
    {
        internal InputFrameToOutputFrameAdapter(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameToOutputFrameAdapter(cdata_new, deleter_, retainer_);
        }
        public new InputFrameToOutputFrameAdapter Clone()
        {
            return (InputFrameToOutputFrameAdapter)(CloneObject());
        }
        public virtual InputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToOutputFrameAdapter_input(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSource output()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToOutputFrameAdapter_output(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSource>(_return_value_, Detail.easyar_OutputFrameSource__typeName);
            }
        }
        public static InputFrameToOutputFrameAdapter create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToOutputFrameAdapter_create(out _return_value_);
                return Detail.Object_from_c<InputFrameToOutputFrameAdapter>(_return_value_, Detail.easyar_InputFrameToOutputFrameAdapter__typeName);
            }
        }
    }

    public class InputFrameToFeedbackFrameAdapter : RefBase
    {
        internal InputFrameToFeedbackFrameAdapter(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrameToFeedbackFrameAdapter(cdata_new, deleter_, retainer_);
        }
        public new InputFrameToFeedbackFrameAdapter Clone()
        {
            return (InputFrameToFeedbackFrameAdapter)(CloneObject());
        }
        public virtual InputFrameSink input()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToFeedbackFrameAdapter_input(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrameSink>(_return_value_, Detail.easyar_InputFrameSink__typeName);
            }
        }
        public virtual OutputFrameSink sideInput()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToFeedbackFrameAdapter_sideInput(cdata, out _return_value_);
                return Detail.Object_from_c<OutputFrameSink>(_return_value_, Detail.easyar_OutputFrameSink__typeName);
            }
        }
        public virtual FeedbackFrameSource output()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToFeedbackFrameAdapter_output(cdata, out _return_value_);
                return Detail.Object_from_c<FeedbackFrameSource>(_return_value_, Detail.easyar_FeedbackFrameSource__typeName);
            }
        }
        public static InputFrameToFeedbackFrameAdapter create()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrameToFeedbackFrameAdapter_create(out _return_value_);
                return Detail.Object_from_c<InputFrameToFeedbackFrameAdapter>(_return_value_, Detail.easyar_InputFrameToFeedbackFrameAdapter__typeName);
            }
        }
    }

    public class Engine
    {
        public static int schemaHash()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Engine_schemaHash();
                return _return_value_;
            }
        }
        public static bool initialize(string key)
        {
            if (Detail.easyar_Engine_schemaHash() != -1339788856)
            {
                throw new InvalidOperationException("SchemaHashNotMatched");
            }
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Engine_initialize(Detail.String_to_c(ar, key));
                return _return_value_;
            }
        }
        public static void onPause()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Engine_onPause();
            }
        }
        public static void onResume()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Engine_onResume();
            }
        }
        public static string errorMessage()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Engine_errorMessage(out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public static string versionString()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Engine_versionString(out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public static string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Engine_name(out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
    }

    public enum InputFrameTrackingStatus
    {
        NotTracking = 0,
        Tracking = 1,
    }

    public class InputFrame : RefBase
    {
        internal InputFrame(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new InputFrame(cdata_new, deleter_, retainer_);
        }
        public new InputFrame Clone()
        {
            return (InputFrame)(CloneObject());
        }
        public virtual int index()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_index(cdata);
                return _return_value_;
            }
        }
        public virtual Image image()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_image(cdata, out _return_value_);
                return Detail.Object_from_c<Image>(_return_value_, Detail.easyar_Image__typeName);
            }
        }
        public virtual bool hasCameraParameters()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_hasCameraParameters(cdata);
                return _return_value_;
            }
        }
        public virtual CameraParameters cameraParameters()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_cameraParameters(cdata, out _return_value_);
                return Detail.Object_from_c<CameraParameters>(_return_value_, Detail.easyar_CameraParameters__typeName);
            }
        }
        public virtual bool hasTemporalInformation()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_hasTemporalInformation(cdata);
                return _return_value_;
            }
        }
        public virtual double timestamp()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_timestamp(cdata);
                return _return_value_;
            }
        }
        public virtual bool hasSpatialInformation()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_hasSpatialInformation(cdata);
                return _return_value_;
            }
        }
        public virtual Matrix44F cameraTransform()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_cameraTransform(cdata);
                return _return_value_;
            }
        }
        public virtual InputFrameTrackingStatus trackingStatus()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_InputFrame_trackingStatus(cdata);
                return _return_value_;
            }
        }
        public static InputFrame create(Image image, CameraParameters cameraParameters, double timestamp, Matrix44F cameraTransform, InputFrameTrackingStatus trackingStatus)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_create(image.cdata, cameraParameters.cdata, timestamp, cameraTransform, trackingStatus, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
        public static InputFrame createWithImageAndCameraParametersAndTemporal(Image image, CameraParameters cameraParameters, double timestamp)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(image.cdata, cameraParameters.cdata, timestamp, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
        public static InputFrame createWithImageAndCameraParameters(Image image, CameraParameters cameraParameters)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_createWithImageAndCameraParameters(image.cdata, cameraParameters.cdata, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
        public static InputFrame createWithImage(Image image)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_InputFrame_createWithImage(image.cdata, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
    }

    public class FrameFilterResult : RefBase
    {
        internal FrameFilterResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new FrameFilterResult(cdata_new, deleter_, retainer_);
        }
        public new FrameFilterResult Clone()
        {
            return (FrameFilterResult)(CloneObject());
        }
    }

    public class OutputFrame : RefBase
    {
        internal OutputFrame(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new OutputFrame(cdata_new, deleter_, retainer_);
        }
        public new OutputFrame Clone()
        {
            return (OutputFrame)(CloneObject());
        }
        public OutputFrame(InputFrame inputFrame, List<Optional<FrameFilterResult>> results) : base(IntPtr.Zero, Detail.easyar_OutputFrame__dtor, Detail.easyar_OutputFrame__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_OutputFrame__ctor(inputFrame.cdata, Detail.ListOfOptionalOfFrameFilterResult_to_c(ar, results), out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual int index()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_OutputFrame_index(cdata);
                return _return_value_;
            }
        }
        public virtual InputFrame inputFrame()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrame_inputFrame(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
        public virtual List<Optional<FrameFilterResult>> results()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_OutputFrame_results(cdata, out _return_value_);
                return Detail.ListOfOptionalOfFrameFilterResult_from_c(ar, _return_value_);
            }
        }
    }

    public class FeedbackFrame : RefBase
    {
        internal FeedbackFrame(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new FeedbackFrame(cdata_new, deleter_, retainer_);
        }
        public new FeedbackFrame Clone()
        {
            return (FeedbackFrame)(CloneObject());
        }
        public FeedbackFrame(InputFrame inputFrame, Optional<OutputFrame> previousOutputFrame) : base(IntPtr.Zero, Detail.easyar_FeedbackFrame__dtor, Detail.easyar_FeedbackFrame__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_FeedbackFrame__ctor(inputFrame.cdata, previousOutputFrame.map(p => p.OnSome ? new Detail.OptionalOfOutputFrame { has_value = true, value = p.Value.cdata } : new Detail.OptionalOfOutputFrame { has_value = false, value = default(IntPtr) }), out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual InputFrame inputFrame()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_FeedbackFrame_inputFrame(cdata, out _return_value_);
                return Detail.Object_from_c<InputFrame>(_return_value_, Detail.easyar_InputFrame__typeName);
            }
        }
        public virtual Optional<OutputFrame> previousOutputFrame()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfOutputFrame);
                Detail.easyar_FeedbackFrame_previousOutputFrame(cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<OutputFrame>(p.value, Detail.easyar_OutputFrame__typeName) : Optional<OutputFrame>.Empty);
            }
        }
    }

    public enum PermissionStatus
    {
        Granted = 0x00000000,
        Denied = 0x00000001,
        Error = 0x00000002,
    }

    public enum StorageType
    {
        App = 0,
        Assets = 1,
        Absolute = 2,
    }

    public class Target : RefBase
    {
        internal Target(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new Target(cdata_new, deleter_, retainer_);
        }
        public new Target Clone()
        {
            return (Target)(CloneObject());
        }
        public virtual int runtimeID()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Target_runtimeID(cdata);
                return _return_value_;
            }
        }
        public virtual string uid()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Target_uid(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual string name()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Target_name(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setName(string name)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Target_setName(cdata, Detail.String_to_c(ar, name));
            }
        }
        public virtual string meta()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Target_meta(cdata, out _return_value_);
                return Detail.String_from_c(ar, _return_value_);
            }
        }
        public virtual void setMeta(string data)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Target_setMeta(cdata, Detail.String_to_c(ar, data));
            }
        }
    }

    public enum TargetStatus
    {
        Unknown = 0,
        Undefined = 1,
        Detected = 2,
        Tracked = 3,
    }

    public class TargetInstance : RefBase
    {
        internal TargetInstance(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new TargetInstance(cdata_new, deleter_, retainer_);
        }
        public new TargetInstance Clone()
        {
            return (TargetInstance)(CloneObject());
        }
        public TargetInstance() : base(IntPtr.Zero, Detail.easyar_TargetInstance__dtor, Detail.easyar_TargetInstance__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_TargetInstance__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual TargetStatus status()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_TargetInstance_status(cdata);
                return _return_value_;
            }
        }
        public virtual Optional<Target> target()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfTarget);
                Detail.easyar_TargetInstance_target(cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<Target>(p.value, Detail.easyar_Target__typeName) : Optional<Target>.Empty);
            }
        }
        public virtual Matrix44F pose()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_TargetInstance_pose(cdata);
                return _return_value_;
            }
        }
    }

    public class TargetTrackerResult : FrameFilterResult
    {
        internal TargetTrackerResult(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new TargetTrackerResult(cdata_new, deleter_, retainer_);
        }
        public new TargetTrackerResult Clone()
        {
            return (TargetTrackerResult)(CloneObject());
        }
        public virtual List<TargetInstance> targetInstances()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_TargetTrackerResult_targetInstances(cdata, out _return_value_);
                return Detail.ListOfTargetInstance_from_c(ar, _return_value_);
            }
        }
        public virtual void setTargetInstances(List<TargetInstance> instances)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_TargetTrackerResult_setTargetInstances(cdata, Detail.ListOfTargetInstance_to_c(ar, instances));
            }
        }
    }

    public class TextureId : RefBase
    {
        internal TextureId(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new TextureId(cdata_new, deleter_, retainer_);
        }
        public new TextureId Clone()
        {
            return (TextureId)(CloneObject());
        }
        public virtual int getInt()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_TextureId_getInt(cdata);
                return _return_value_;
            }
        }
        public virtual IntPtr getPointer()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_TextureId_getPointer(cdata);
                return _return_value_;
            }
        }
        public static TextureId fromInt(int @value)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_TextureId_fromInt(@value, out _return_value_);
                return Detail.Object_from_c<TextureId>(_return_value_, Detail.easyar_TextureId__typeName);
            }
        }
        public static TextureId fromPointer(IntPtr ptr)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_TextureId_fromPointer(ptr, out _return_value_);
                return Detail.Object_from_c<TextureId>(_return_value_, Detail.easyar_TextureId__typeName);
            }
        }
    }

    public enum VideoStatus
    {
        Error = -1,
        Ready = 0,
        Completed = 1,
    }

    public enum VideoType
    {
        Normal = 0,
        TransparentSideBySide = 1,
        TransparentTopAndBottom = 2,
    }

    public class VideoPlayer : RefBase
    {
        internal VideoPlayer(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new VideoPlayer(cdata_new, deleter_, retainer_);
        }
        public new VideoPlayer Clone()
        {
            return (VideoPlayer)(CloneObject());
        }
        public VideoPlayer() : base(IntPtr.Zero, Detail.easyar_VideoPlayer__dtor, Detail.easyar_VideoPlayer__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_VideoPlayer__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual void setVideoType(VideoType videoType)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_setVideoType(cdata, videoType);
            }
        }
        public virtual void setRenderTexture(TextureId texture)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_setRenderTexture(cdata, texture.cdata);
            }
        }
        public virtual void open(string path, StorageType storageType, CallbackScheduler callbackScheduler, Optional<Action<VideoStatus>> callback)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_open(cdata, Detail.String_to_c(ar, path), storageType, callbackScheduler.cdata, callback.map(p => p.OnSome ? new Detail.OptionalOfFunctorOfVoidFromVideoStatus { has_value = true, value = Detail.FunctorOfVoidFromVideoStatus_to_c(p.Value) } : new Detail.OptionalOfFunctorOfVoidFromVideoStatus { has_value = false, value = default(Detail.FunctorOfVoidFromVideoStatus) }));
            }
        }
        public virtual void close()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_close(cdata);
            }
        }
        public virtual bool play()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_play(cdata);
                return _return_value_;
            }
        }
        public virtual void stop()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_stop(cdata);
            }
        }
        public virtual void pause()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_pause(cdata);
            }
        }
        public virtual bool isRenderTextureAvailable()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_isRenderTextureAvailable(cdata);
                return _return_value_;
            }
        }
        public virtual void updateFrame()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_VideoPlayer_updateFrame(cdata);
            }
        }
        public virtual int duration()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_duration(cdata);
                return _return_value_;
            }
        }
        public virtual int currentPosition()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_currentPosition(cdata);
                return _return_value_;
            }
        }
        public virtual bool seek(int position)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_seek(cdata, position);
                return _return_value_;
            }
        }
        public virtual Vec2I size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_size(cdata);
                return _return_value_;
            }
        }
        public virtual float volume()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_volume(cdata);
                return _return_value_;
            }
        }
        public virtual bool setVolume(float volume)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_VideoPlayer_setVolume(cdata, volume);
                return _return_value_;
            }
        }
    }

    public class Buffer : RefBase
    {
        internal Buffer(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new Buffer(cdata_new, deleter_, retainer_);
        }
        public new Buffer Clone()
        {
            return (Buffer)(CloneObject());
        }
        public static Buffer wrap(IntPtr ptr, int size, Action deleter)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Buffer_wrap(ptr, size, Detail.FunctorOfVoid_to_c(deleter), out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public static Buffer create(int size)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Buffer_create(size, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual IntPtr data()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Buffer_data(cdata);
                return _return_value_;
            }
        }
        public virtual int size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Buffer_size(cdata);
                return _return_value_;
            }
        }
        public static void memoryCopy(IntPtr src, IntPtr dest, int length)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Buffer_memoryCopy(src, dest, length);
            }
        }
        public virtual bool tryCopyFrom(IntPtr src, int srcIndex, int index, int length)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Buffer_tryCopyFrom(cdata, src, srcIndex, index, length);
                return _return_value_;
            }
        }
        public virtual bool tryCopyTo(int index, IntPtr dest, int destIndex, int length)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Buffer_tryCopyTo(cdata, index, dest, destIndex, length);
                return _return_value_;
            }
        }
        public virtual Buffer partition(int index, int length)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Buffer_partition(cdata, index, length, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public static Buffer wrapByteArray(byte[] bytes)
        {
            var Length = bytes.Length;
            var h = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            return Buffer.wrap(h.AddrOfPinnedObject(), Length, () => h.Free());
        }
        public static Buffer wrapByteArray(byte[] bytes, int index, int length)
        {
            return wrapByteArray(bytes, index, length, () => { });
        }
        public static Buffer wrapByteArray(byte[] bytes, int index, int length, Action deleter)
        {
            if ((length < 0) || (index < 0) || (index > bytes.Length) || (index + length > bytes.Length))
            {
                throw new ArgumentException("BufferRangeOverflow");
            }
            var h = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            var ptr = new IntPtr(h.AddrOfPinnedObject().ToInt64() + index);
            return Buffer.wrap(ptr, length, () =>
            {
                h.Free();
                if (deleter != null)
                {
                    deleter();
                }
            });
        }
        public void copyFromByteArray(byte[] src)
        {
            copyFromByteArray(src, 0, 0, src.Length);
        }
        public void copyFromByteArray(byte[] src, int srcIndex, int index, int length)
        {
            var srcSize = src.Length;
            var destSize = size();
            if ((length < 0) || (srcIndex < 0) || (srcIndex > srcSize) || (srcIndex + length > srcSize) || (index < 0) || (index > destSize) || (index + length > destSize))
            {
                throw new ArgumentException("BufferRangeOverflow");
            }
            Marshal.Copy(src, srcIndex, data(), length);
        }
        public void copyToByteArray(byte[] dest)
        {
            copyToByteArray(0, dest, 0, size());
        }
        public void copyToByteArray(int index, byte[] dest, int destIndex, int length)
        {
            var srcSize = size();
            var destSize = dest.Length;
            if ((length < 0) || (index < 0) || (index > srcSize) || (index + length > srcSize) || (destIndex < 0) || (destIndex > destSize) || (destIndex + length > destSize))
            {
                throw new ArgumentException("BufferRangeOverflow");
            }
            var ptr = new IntPtr(data().ToInt64() + index);
            Marshal.Copy(ptr, dest, destIndex, length);
        }
    }

    public class BufferDictionary : RefBase
    {
        internal BufferDictionary(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new BufferDictionary(cdata_new, deleter_, retainer_);
        }
        public new BufferDictionary Clone()
        {
            return (BufferDictionary)(CloneObject());
        }
        public BufferDictionary() : base(IntPtr.Zero, Detail.easyar_BufferDictionary__dtor, Detail.easyar_BufferDictionary__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_BufferDictionary__ctor(out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual int count()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferDictionary_count(cdata);
                return _return_value_;
            }
        }
        public virtual bool contains(string path)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferDictionary_contains(cdata, Detail.String_to_c(ar, path));
                return _return_value_;
            }
        }
        public virtual Optional<Buffer> tryGet(string path)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfBuffer);
                Detail.easyar_BufferDictionary_tryGet(cdata, Detail.String_to_c(ar, path), out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<Buffer>(p.value, Detail.easyar_Buffer__typeName) : Optional<Buffer>.Empty);
            }
        }
        public virtual void @set(string path, Buffer buffer)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_BufferDictionary_set(cdata, Detail.String_to_c(ar, path), buffer.cdata);
            }
        }
        public virtual bool remove(string path)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferDictionary_remove(cdata, Detail.String_to_c(ar, path));
                return _return_value_;
            }
        }
        public virtual void clear()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_BufferDictionary_clear(cdata);
            }
        }
    }

    public class BufferPool : RefBase
    {
        internal BufferPool(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new BufferPool(cdata_new, deleter_, retainer_);
        }
        public new BufferPool Clone()
        {
            return (BufferPool)(CloneObject());
        }
        public BufferPool(int block_size, int capacity) : base(IntPtr.Zero, Detail.easyar_BufferPool__dtor, Detail.easyar_BufferPool__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_BufferPool__ctor(block_size, capacity, out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual int block_size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferPool_block_size(cdata);
                return _return_value_;
            }
        }
        public virtual int capacity()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferPool_capacity(cdata);
                return _return_value_;
            }
        }
        public virtual int size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_BufferPool_size(cdata);
                return _return_value_;
            }
        }
        public virtual Optional<Buffer> tryAcquire()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(Detail.OptionalOfBuffer);
                Detail.easyar_BufferPool_tryAcquire(cdata, out _return_value_);
                return _return_value_.map(p => p.has_value ? Detail.Object_from_c<Buffer>(p.value, Detail.easyar_Buffer__typeName) : Optional<Buffer>.Empty);
            }
        }
    }

    public enum CameraDeviceType
    {
        Default = 0,
        Back = 1,
        Front = 2,
    }

    public class CameraParameters : RefBase
    {
        internal CameraParameters(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new CameraParameters(cdata_new, deleter_, retainer_);
        }
        public new CameraParameters Clone()
        {
            return (CameraParameters)(CloneObject());
        }
        public CameraParameters(Vec2I size, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation) : base(IntPtr.Zero, Detail.easyar_CameraParameters__dtor, Detail.easyar_CameraParameters__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_CameraParameters__ctor(size, focalLength, principalPoint, cameraDeviceType, cameraOrientation, out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual Vec2I size()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_size(cdata);
                return _return_value_;
            }
        }
        public virtual Vec2F focalLength()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_focalLength(cdata);
                return _return_value_;
            }
        }
        public virtual Vec2F principalPoint()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_principalPoint(cdata);
                return _return_value_;
            }
        }
        public virtual CameraDeviceType cameraDeviceType()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_cameraDeviceType(cdata);
                return _return_value_;
            }
        }
        public virtual int cameraOrientation()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_cameraOrientation(cdata);
                return _return_value_;
            }
        }
        public static CameraParameters createWithDefaultIntrinsics(Vec2I size, CameraDeviceType cameraDeviceType, int cameraOrientation)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_CameraParameters_createWithDefaultIntrinsics(size, cameraDeviceType, cameraOrientation, out _return_value_);
                return Detail.Object_from_c<CameraParameters>(_return_value_, Detail.easyar_CameraParameters__typeName);
            }
        }
        public virtual int imageOrientation(int screenRotation)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_imageOrientation(cdata, screenRotation);
                return _return_value_;
            }
        }
        public virtual bool imageHorizontalFlip(bool manualHorizontalFlip)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_imageHorizontalFlip(cdata, manualHorizontalFlip);
                return _return_value_;
            }
        }
        public virtual Matrix44F projection(float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_projection(cdata, nearPlane, farPlane, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip);
                return _return_value_;
            }
        }
        public virtual Matrix44F imageProjection(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_imageProjection(cdata, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip);
                return _return_value_;
            }
        }
        public virtual Vec2F screenCoordinatesFromImageCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F imageCoordinates)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_screenCoordinatesFromImageCoordinates(cdata, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, imageCoordinates);
                return _return_value_;
            }
        }
        public virtual Vec2F imageCoordinatesFromScreenCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F screenCoordinates)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(cdata, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, screenCoordinates);
                return _return_value_;
            }
        }
        public virtual bool equalsTo(CameraParameters other)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_CameraParameters_equalsTo(cdata, other.cdata);
                return _return_value_;
            }
        }
    }

    public enum PixelFormat
    {
        Unknown = 0,
        Gray = 1,
        YUV_NV21 = 2,
        YUV_NV12 = 3,
        YUV_I420 = 4,
        YUV_YV12 = 5,
        RGB888 = 6,
        BGR888 = 7,
        RGBA8888 = 8,
        BGRA8888 = 9,
    }

    public class Image : RefBase
    {
        internal Image(IntPtr cdata, Action<IntPtr> deleter, Retainer retainer) : base(cdata, deleter, retainer)
        {
        }
        protected override object CloneObject()
        {
            var cdata_new = IntPtr.Zero;
            if (retainer_ != null) { retainer_(cdata, out cdata_new); }
            return new Image(cdata_new, deleter_, retainer_);
        }
        public new Image Clone()
        {
            return (Image)(CloneObject());
        }
        public Image(Buffer buffer, PixelFormat format, int width, int height) : base(IntPtr.Zero, Detail.easyar_Image__dtor, Detail.easyar_Image__retain)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = IntPtr.Zero;
                Detail.easyar_Image__ctor(buffer.cdata, format, width, height, out _return_value_);
                cdata_ = _return_value_;
            }
        }
        public virtual Buffer buffer()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_Image_buffer(cdata, out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public virtual PixelFormat format()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Image_format(cdata);
                return _return_value_;
            }
        }
        public virtual int width()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Image_width(cdata);
                return _return_value_;
            }
        }
        public virtual int height()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Image_height(cdata);
                return _return_value_;
            }
        }
        public virtual bool empty()
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = Detail.easyar_Image_empty(cdata);
                return _return_value_;
            }
        }
    }

    public class JniUtility
    {
        public static Buffer wrapByteArray(IntPtr bytes, bool readOnly, Action deleter)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_JniUtility_wrapByteArray(bytes, readOnly, Detail.FunctorOfVoid_to_c(deleter), out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
        public static Buffer wrapBuffer(IntPtr directBuffer, Action deleter)
        {
            using (var ar = new Detail.AutoRelease())
            {
                var _return_value_ = default(IntPtr);
                Detail.easyar_JniUtility_wrapBuffer(directBuffer, Detail.FunctorOfVoid_to_c(deleter), out _return_value_);
                return Detail.Object_from_c<Buffer>(_return_value_, Detail.easyar_Buffer__typeName);
            }
        }
    }

    public enum LogLevel
    {
        Error = 0,
        Warning = 1,
        Info = 2,
    }

    public class Log
    {
        public static void setLogFunc(Action<LogLevel, string> func)
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Log_setLogFunc(Detail.FunctorOfVoidFromLogLevelAndString_to_c(func));
            }
        }
        public static void resetLogFunc()
        {
            using (var ar = new Detail.AutoRelease())
            {
                Detail.easyar_Log_resetLogFunc();
            }
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Matrix44F
    {
        public float data_0;
        public float data_1;
        public float data_2;
        public float data_3;
        public float data_4;
        public float data_5;
        public float data_6;
        public float data_7;
        public float data_8;
        public float data_9;
        public float data_10;
        public float data_11;
        public float data_12;
        public float data_13;
        public float data_14;
        public float data_15;
        public float[] data
        {
            get
            {
                return new float[] { data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8, data_9, data_10, data_11, data_12, data_13, data_14, data_15 };
            }
            set
            {
                if (value.Length != 16) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
                this.data_2 = value[2];
                this.data_3 = value[3];
                this.data_4 = value[4];
                this.data_5 = value[5];
                this.data_6 = value[6];
                this.data_7 = value[7];
                this.data_8 = value[8];
                this.data_9 = value[9];
                this.data_10 = value[10];
                this.data_11 = value[11];
                this.data_12 = value[12];
                this.data_13 = value[13];
                this.data_14 = value[14];
                this.data_15 = value[15];
            }
        }

        public Matrix44F(float data_0, float data_1, float data_2, float data_3, float data_4, float data_5, float data_6, float data_7, float data_8, float data_9, float data_10, float data_11, float data_12, float data_13, float data_14, float data_15)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
            this.data_2 = data_2;
            this.data_3 = data_3;
            this.data_4 = data_4;
            this.data_5 = data_5;
            this.data_6 = data_6;
            this.data_7 = data_7;
            this.data_8 = data_8;
            this.data_9 = data_9;
            this.data_10 = data_10;
            this.data_11 = data_11;
            this.data_12 = data_12;
            this.data_13 = data_13;
            this.data_14 = data_14;
            this.data_15 = data_15;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Matrix33F
    {
        public float data_0;
        public float data_1;
        public float data_2;
        public float data_3;
        public float data_4;
        public float data_5;
        public float data_6;
        public float data_7;
        public float data_8;
        public float[] data
        {
            get
            {
                return new float[] { data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8 };
            }
            set
            {
                if (value.Length != 9) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
                this.data_2 = value[2];
                this.data_3 = value[3];
                this.data_4 = value[4];
                this.data_5 = value[5];
                this.data_6 = value[6];
                this.data_7 = value[7];
                this.data_8 = value[8];
            }
        }

        public Matrix33F(float data_0, float data_1, float data_2, float data_3, float data_4, float data_5, float data_6, float data_7, float data_8)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
            this.data_2 = data_2;
            this.data_3 = data_3;
            this.data_4 = data_4;
            this.data_5 = data_5;
            this.data_6 = data_6;
            this.data_7 = data_7;
            this.data_8 = data_8;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec4F
    {
        public float data_0;
        public float data_1;
        public float data_2;
        public float data_3;
        public float[] data
        {
            get
            {
                return new float[] { data_0, data_1, data_2, data_3 };
            }
            set
            {
                if (value.Length != 4) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
                this.data_2 = value[2];
                this.data_3 = value[3];
            }
        }

        public Vec4F(float data_0, float data_1, float data_2, float data_3)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
            this.data_2 = data_2;
            this.data_3 = data_3;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec3F
    {
        public float data_0;
        public float data_1;
        public float data_2;
        public float[] data
        {
            get
            {
                return new float[] { data_0, data_1, data_2 };
            }
            set
            {
                if (value.Length != 3) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
                this.data_2 = value[2];
            }
        }

        public Vec3F(float data_0, float data_1, float data_2)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
            this.data_2 = data_2;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec2F
    {
        public float data_0;
        public float data_1;
        public float[] data
        {
            get
            {
                return new float[] { data_0, data_1 };
            }
            set
            {
                if (value.Length != 2) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
            }
        }

        public Vec2F(float data_0, float data_1)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec4I
    {
        public int data_0;
        public int data_1;
        public int data_2;
        public int data_3;
        public int[] data
        {
            get
            {
                return new int[] { data_0, data_1, data_2, data_3 };
            }
            set
            {
                if (value.Length != 4) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
                this.data_2 = value[2];
                this.data_3 = value[3];
            }
        }

        public Vec4I(int data_0, int data_1, int data_2, int data_3)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
            this.data_2 = data_2;
            this.data_3 = data_3;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec2I
    {
        public int data_0;
        public int data_1;
        public int[] data
        {
            get
            {
                return new int[] { data_0, data_1 };
            }
            set
            {
                if (value.Length != 2) { throw new ArgumentException(); }
                this.data_0 = value[0];
                this.data_1 = value[1];
            }
        }

        public Vec2I(int data_0, int data_1)
        {
            this.data_0 = data_0;
            this.data_1 = data_1;
        }
    }

}