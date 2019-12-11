//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
namespace easyar
{
    public enum PathType
    {
        Absolute = 0,
        StreamingAssets = 1
    }

    public class Utility
    {
        public static UnityEngine.Matrix4x4 Matrix44FToMatrix4x4(easyar.Matrix44F matrix)
        {
            var _matrix = new Matrix4x4();
            _matrix.SetRow(0, new Vector4(matrix.data_0, matrix.data_1, matrix.data_2, matrix.data_3));
            _matrix.SetRow(1, new Vector4(matrix.data_4, matrix.data_5, matrix.data_6, matrix.data_7));
            _matrix.SetRow(2, new Vector4(matrix.data_8, matrix.data_9, matrix.data_10, matrix.data_11));
            _matrix.SetRow(3, new Vector4(matrix.data_12, matrix.data_13, matrix.data_14, matrix.data_15));
            return _matrix;
        }

        public static Vector3 GetPosition(Matrix4x4 matrix)
        {
            Vector3 position = matrix.GetColumn(3);
            position.z = -position.z;

            return position;
        }

        public static Quaternion GetRotation(Matrix4x4 matrix)
        {
            Quaternion rotation = QuaternionFromMatrix(matrix);
            rotation.z = -rotation.z;
            rotation.w = -rotation.w;

            return rotation;
        }


        static Quaternion QuaternionFromMatrix(Matrix4x4 m)
        {
            // Adapted from: http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
            Quaternion q = new Quaternion();
            q.w = Mathf.Sqrt(Mathf.Max(0, 1 + m[0, 0] + m[1, 1] + m[2, 2])) / 2;
            q.x = Mathf.Sqrt(Mathf.Max(0, 1 + m[0, 0] - m[1, 1] - m[2, 2])) / 2;
            q.y = Mathf.Sqrt(Mathf.Max(0, 1 - m[0, 0] + m[1, 1] - m[2, 2])) / 2;
            q.z = Mathf.Sqrt(Mathf.Max(0, 1 - m[0, 0] - m[1, 1] + m[2, 2])) / 2;
            q.x *= Mathf.Sign(q.x * (m[2, 1] - m[1, 2]));
            q.y *= Mathf.Sign(q.y * (m[0, 2] - m[2, 0]));
            q.z *= Mathf.Sign(q.z * (m[1, 0] - m[0, 1]));
            return q;
        }


        public static int GetScreenRotation()
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            using (var surfaceClass = new AndroidJavaClass("android.view.Surface"))
            using (var contextClass = new AndroidJavaClass("android.content.Context"))
            using (var WINDOW_SERVICE = contextClass.GetStatic<AndroidJavaObject>("WINDOW_SERVICE"))
            using (var unityPlayerClass = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
            using (var currentActivity = unityPlayerClass.GetStatic<AndroidJavaObject>("currentActivity"))
            using (var windowsService = currentActivity.Call<AndroidJavaObject>("getSystemService", WINDOW_SERVICE))
            using (var defaultDisplay = windowsService.Call<AndroidJavaObject>("getDefaultDisplay"))
            {
                var rotation = defaultDisplay.Call<int>("getRotation");
                if (rotation == surfaceClass.GetStatic<int>("ROTATION_0"))
                {
                    return 0;
                }
                else if (rotation == surfaceClass.GetStatic<int>("ROTATION_90"))
                {
                    return 90;
                }
                else if (rotation == surfaceClass.GetStatic<int>("ROTATION_180"))
                {
                    return 180;
                }
                else if (rotation == surfaceClass.GetStatic<int>("ROTATION_270"))
                {
                    return 270;
                }
                else
                {
                    return 0;
                }
            }
#elif UNITY_IOS && !UNITY_EDITOR
            var orientation = Screen.orientation;
            if (orientation == ScreenOrientation.Portrait)
            {
                return 0;
            }
            else if (orientation == ScreenOrientation.LandscapeLeft)
            {
                return 90;
            }
            else if (orientation == ScreenOrientation.PortraitUpsideDown)
            {
                return 180;
            }
            else if (orientation == ScreenOrientation.LandscapeRight)
            {
                return 270;
            }
            else
            {
                return 0;
            }
#endif
            return 0;
        }

        public static void SetMatrixOnTransform(Transform t, Matrix4x4 mat)
        {
            //Notice: assume no reflection

            var scale = new Vector3 { x = Mathf.Sqrt(mat.GetColumn(0).sqrMagnitude), y = Mathf.Sqrt(mat.GetColumn(1).sqrMagnitude), z = Mathf.Sqrt(mat.GetColumn(2).sqrMagnitude) };
            var m = new Matrix4x4();
            m.SetColumn(0, mat.GetColumn(0) / scale.x);
            m.SetColumn(1, mat.GetColumn(1) / scale.y);
            m.SetColumn(2, mat.GetColumn(2) / scale.z);
            m.SetColumn(3, mat.GetColumn(3));

            // Adapted from: http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
            var q = new Quaternion
            {
                w = Mathf.Sqrt(Mathf.Max(0, 1 + m[0, 0] + m[1, 1] + m[2, 2])) / 2,
                x = Mathf.Sqrt(Mathf.Max(0, 1 + m[0, 0] - m[1, 1] - m[2, 2])) / 2,
                y = Mathf.Sqrt(Mathf.Max(0, 1 - m[0, 0] + m[1, 1] - m[2, 2])) / 2,
                z = Mathf.Sqrt(Mathf.Max(0, 1 - m[0, 0] - m[1, 1] + m[2, 2])) / 2
            };

            q.x *= Mathf.Sign(q.x * (m[2, 1] - m[1, 2]));
            q.y *= Mathf.Sign(q.y * (m[0, 2] - m[2, 0]));
            q.z *= Mathf.Sign(q.z * (m[1, 0] - m[0, 1]));

            var translation = m.GetColumn(3);

            t.localRotation = new Quaternion { w = q.w, x = -q.x, y = -q.y, z = q.z };
            t.localPosition = new Vector3 { x = translation.x, y = translation.y, z = -translation.z };
            t.localScale = scale;
        }

        public static Quaternion ExtractRotation(Matrix4x4 matrix)
        {
            Vector3 forward;
            forward.x = matrix.m02;
            forward.y = matrix.m12;
            forward.z = matrix.m22;

            Vector3 upwards;
            upwards.x = matrix.m01;
            upwards.y = matrix.m11;
            upwards.z = matrix.m21;

            return Quaternion.LookRotation(forward, upwards);
        }

        public static Vector3 ExtractPosition(Matrix4x4 matrix)
        {
            Vector3 position;
            position.x = matrix.m03;
            position.y = matrix.m13;
            position.z = matrix.m23;
            return position;
        }

        public static Vector3 ExtractScale(Matrix4x4 matrix)
        {
            Vector3 scale;
            scale.x = new Vector4(matrix.m00, matrix.m10, matrix.m20, matrix.m30).magnitude;
            scale.y = new Vector4(matrix.m01, matrix.m11, matrix.m21, matrix.m31).magnitude;
            scale.z = new Vector4(matrix.m02, matrix.m12, matrix.m22, matrix.m32).magnitude;
            return scale;
        }

        public static Vec2F Vector2ToVec2F(Vector2 vec2)
        {
            return new Vec2F(vec2.x, vec2.y);
        }

        public static Vec3F Vector3ToVec3F(Vector3 vec3)
        {
            return new Vec3F(vec3.x, vec3.y, vec3.z);
        }

        public static Vector2 Vec2FToVector2(Vec2F vec2)
        {
            return new Vector2(vec2.data_0, vec2.data_1);
        }

        public static Vector3 Vec3FToVector3(Vec3F vec3)
        {
            return new Vector3(vec3.data_0, vec3.data_1, vec3.data_2);
        }

        public static string AddFileHeader(string path)
        {
            if (Application.platform == RuntimePlatform.OSXEditor || Application.platform == RuntimePlatform.OSXPlayer || Application.platform == RuntimePlatform.IPhonePlayer)
            {
                path = "file://" + path;
            }
            else if(Application.platform == RuntimePlatform.WindowsEditor || Application.platform == RuntimePlatform.WindowsPlayer)
            {
                path = "file:///" + path;
            }
            return path;
        }

    }
}
