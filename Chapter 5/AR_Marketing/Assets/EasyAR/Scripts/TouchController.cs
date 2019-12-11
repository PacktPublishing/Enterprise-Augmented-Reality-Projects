//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
public class TouchController : MonoBehaviour
{
    private const float Rotate_Speed = 270f;
    private const float ANDROID_Move_Speed = 3f;
    private const float IPHONE_Move_Speed = 1f;

    private const float Standard_Calculation_Distance = 10f;
    private const float Gesture_Enable_Distance_Threshold = 10f;
    private GestureControl m_CurGesture = GestureControl.NoTouch;
    private bool m_NoMarkerModeOn = false;
    private Dictionary<int, Vector2> m_FingerRawPositionDict = new Dictionary<int, Vector2>();

    private Transform m_Target;
    private Camera m_Cam;

    private Quaternion m_OriginRotation;

    private bool m_IsDraggable;
    private bool m_IsScalable;
    private bool m_IsRotatable;

    private Vector3 m_target_cam_vec = Vector3.zero;

    private void Start()
    {
        TurnOn(transform, Camera.main, false, true, true);
    }

    public void TurnOn(Transform target, Camera cam, bool isDraggable, bool isScalable, bool isRotatable)
    {
        this.m_Target = target;
        m_OriginRotation = target.rotation;
        this.m_Cam = cam;
        this.m_IsDraggable = isDraggable;
        this.m_IsScalable = isScalable;
        this.m_IsRotatable = isRotatable;
        m_NoMarkerModeOn = true;
        m_CurGesture = GestureControl.NoTouch;
    }

    public void TurnOff()
    {
        if (m_Target != null)
        {
            m_Target.rotation = m_OriginRotation;
            this.m_Target = null;
            this.m_Cam = null;
        }
        m_NoMarkerModeOn = false;
        m_CurGesture = GestureControl.NoTouch;
    }

    void Update()
    {
        foreach (var touch in Input.touches)
        {
            if (touch.phase == TouchPhase.Began)
            {
                m_FingerRawPositionDict[touch.fingerId] = touch.position;
            }
            else if (touch.phase == TouchPhase.Ended)
            {
                m_FingerRawPositionDict.Remove(touch.fingerId);
            }
        }

        if (m_CurGesture == GestureControl.OutOfControl)
        {
            if (Input.touchCount == 0)
            {
                StopAllCoroutines();
                m_CurGesture = GestureControl.NoTouch;
            }
        }
        else if (m_CurGesture == GestureControl.TwoMove || m_CurGesture == GestureControl.TwoRotate || m_CurGesture == GestureControl.TwoScale)
        {
            if (Input.touchCount != 2)
            {
                StopAllCoroutines();
                m_CurGesture = GestureControl.OutOfControl;
            }
        }
        else if (m_CurGesture == GestureControl.TwoWait)
        {
            if (Input.touchCount != 2)
            {
                StopAllCoroutines();
                m_CurGesture = GestureControl.OutOfControl;
            }
            else
            {
                Vector2 touch1Delta = Input.GetTouch(0).position - m_FingerRawPositionDict[Input.GetTouch(0).fingerId];
                Vector2 touch2Delta = Input.GetTouch(1).position - m_FingerRawPositionDict[Input.GetTouch(1).fingerId];
                if (touch1Delta.magnitude > Gesture_Enable_Distance_Threshold && touch2Delta.magnitude > Gesture_Enable_Distance_Threshold)
                {
                    StopAllCoroutines();
                    if (Vector2.Dot(touch1Delta, touch2Delta) > 0)
                    {
                        Vector3 xMov;
                        Vector3 yMov;
                        GetRelativeTouch(touch1Delta + touch2Delta, out xMov, out yMov);
                        if (xMov.sqrMagnitude > yMov.sqrMagnitude)
                        {
                            m_CurGesture = GestureControl.TwoRotate;
                            if (m_IsRotatable)
                            {
                                if (m_NoMarkerModeOn) StartCoroutine(OnTwoRotate());
                            }
                        }
                        else
                        {
                            m_CurGesture = GestureControl.TwoMove;
                            if (m_IsDraggable)
                            {
                                if (m_NoMarkerModeOn) StartCoroutine(OnTwoMove());
                            }
                        }
                    }
                    else
                    {
                        m_CurGesture = GestureControl.TwoScale;
                        if (m_IsScalable)
                        {
                            if (m_NoMarkerModeOn) StartCoroutine(OnTwoScale());
                        }
                    }
                }
            }
        }
        else if (m_CurGesture == GestureControl.OneMove)
        {
            if (Input.touchCount == 2)
            {
                StopAllCoroutines();
                m_CurGesture = GestureControl.TwoWait;
            }
            else if (Input.touchCount != 1)
            {
                StopAllCoroutines();
                m_CurGesture = GestureControl.OutOfControl;
            }
        }
        else if (m_CurGesture == GestureControl.NoTouch)
        {
            if (Input.touchCount == 1)
            {
                m_CurGesture = GestureControl.OneMove;
                if (m_IsDraggable)
                {
                    StopAllCoroutines();
                    if (m_NoMarkerModeOn) StartCoroutine(OnOneMove());
                }
            }
            else if (Input.touchCount == 2)
            {
                m_CurGesture = GestureControl.TwoWait;
                StopAllCoroutines();
            }
        }
        if (m_Target != null)
        {
            m_target_cam_vec = m_Cam.transform.position - m_Target.position;
        }
    }

    IEnumerator OnOneMove()
    {
        yield return new WaitForSeconds(0.1f);
        foreach (var touch in Input.touches)
        {
            m_FingerRawPositionDict[touch.fingerId] = touch.position;
        }

        while (Input.touchCount == 1 && m_FingerRawPositionDict.ContainsKey(Input.GetTouch(0).fingerId))
        {
            var touchV3 = new Vector3(Input.GetTouch(0).deltaPosition.x / Screen.width, Input.GetTouch(0).deltaPosition.y / Screen.height, 0);
            var _addV3 = m_Cam.transform.localToWorldMatrix.MultiplyVector(touchV3);
#if UNITY_ANDROID
            var NewPos = m_Target.position + _addV3 * m_target_cam_vec.magnitude * ANDROID_Move_Speed;
#elif UNITY_IOS
                var NewPos = m_Target.position + _addV3 * m_target_cam_vec.magnitude * IPHONE_Move_Speed;
#else
                var NewPos = m_Target.position + _addV3 * m_target_cam_vec.magnitude;
#endif
            m_Target.position = NewPos;
            yield return 0;
        }
    }

    IEnumerator OnTwoMove()
    {
        Vector3 xMovement;
        Vector3 yMovement;

        var rawTargetPos = m_Target.position;

        foreach (var touch in Input.touches)
        {
            m_FingerRawPositionDict[touch.fingerId] = touch.position;
        }

        while (Input.touchCount == 2 &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(0).fingerId) &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(1).fingerId))
        {
            Vector2 fixedDelta = (Input.GetTouch(0).position + Input.GetTouch(1).position - m_FingerRawPositionDict[Input.GetTouch(0).fingerId] - m_FingerRawPositionDict[Input.GetTouch(1).fingerId]);
            GetRelativeTouch(fixedDelta, out xMovement, out yMovement);
            if (yMovement != Vector3.zero)
            {
                var Cam_Forward = m_Cam.transform.forward;
                var Cam_Forward_XZ = Vector3.ProjectOnPlane(Cam_Forward, Vector3.up);

                var newPos = rawTargetPos + (Vector3.Dot(yMovement, Cam_Forward) > 0 ? Cam_Forward_XZ : -Cam_Forward_XZ) * yMovement.magnitude * m_target_cam_vec.magnitude * 2 / 1000;
                m_Target.position = newPos;
            }
            yield return 0;
        }
    }

    IEnumerator OnTwoRotate()
    {
        Vector3 xMovement;
        Vector3 yMovement;
        Quaternion rawRotation = m_Target.rotation;
        foreach (var touch in Input.touches)
        {
            m_FingerRawPositionDict[touch.fingerId] = touch.position;
        }

        while (Input.touchCount == 2 &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(0).fingerId) &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(1).fingerId))
        {
            Vector2 fixedDelta = (Input.GetTouch(0).position + Input.GetTouch(1).position - m_FingerRawPositionDict[Input.GetTouch(0).fingerId] - m_FingerRawPositionDict[Input.GetTouch(1).fingerId]) * 0.5f / Screen.width * Rotate_Speed;
            GetRelativeTouch(fixedDelta, out xMovement, out yMovement);
            if (xMovement != Vector3.zero)
            {
                if (Vector3.Dot(Vector3.Cross(xMovement.normalized, Vector3.up), Camera.main.transform.forward) < 0f)
                {
                    m_Target.rotation = rawRotation * Quaternion.Euler(0f, xMovement.sqrMagnitude / Mathf.PI, 0f);
                }
                else
                {
                    m_Target.rotation = rawRotation * Quaternion.Euler(0f, -xMovement.sqrMagnitude / Mathf.PI, 0f);
                }
            }
            yield return 0;
        }
    }

    IEnumerator OnTwoScale()
    {

        Vector3 rawCameraPos = m_Cam.transform.position;
        Vector3 rawCamTargetV3 = rawCameraPos - m_Target.position;
        Vector3 rawScale = m_Target.localScale;
        foreach (var touch in Input.touches)
        {
            m_FingerRawPositionDict[touch.fingerId] = touch.position;
        }

        float rawFingersDistance = Vector2.Distance(m_FingerRawPositionDict[Input.GetTouch(0).fingerId], m_FingerRawPositionDict[Input.GetTouch(1).fingerId]);

        while (Input.touchCount == 2 &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(0).fingerId) &&
                m_FingerRawPositionDict.ContainsKey(Input.GetTouch(1).fingerId))
        {
            float scaleFactor = rawFingersDistance / Vector2.Distance(Input.GetTouch(0).position, Input.GetTouch(1).position);
            m_Target.localScale = rawScale / scaleFactor;

            yield return 0;
        }
    }

    void GetRelativeTouch(Vector2 delta, out Vector3 xMovement, out Vector3 yMovement)
    {
        if (delta != Vector2.zero)
        {
            Vector3 startPoint = Camera.main.ScreenToWorldPoint(new Vector3(0f, 0f, 300f));
            Vector3 endPoint = Camera.main.ScreenToWorldPoint(new Vector3(delta.x, delta.y, 300f));
            Vector3 moveDirection = endPoint - startPoint;
            Vector3 relaForward = Vector3.ProjectOnPlane(Camera.main.transform.forward, Vector3.up).normalized;
            if (relaForward == Vector3.zero)
            {
                xMovement = moveDirection;
                yMovement = Vector3.zero;
            }
            else
            {
                Vector3 relaRight = Vector3.Cross(Vector3.up, relaForward);
                xMovement = Vector3.Project(moveDirection, relaRight);
                Vector3 temp = moveDirection - xMovement;
                if (temp != Vector3.zero)
                {
                    if (Vector3.Dot(Vector3.up, temp.normalized) == 0)
                    {
                        yMovement = temp.magnitude * ((Vector3.Dot(relaForward, temp.normalized) > 0 ? relaForward : -relaForward));
                    }
                    else
                    {
                        yMovement = temp.magnitude * ((Vector3.Dot(Vector3.up, temp.normalized) > 0 ? relaForward : -relaForward));
                    }
                }
                else
                {
                    yMovement = Vector3.zero;
                }
            }
        }
        else
        {
            xMovement = Vector3.zero;
            yMovement = Vector3.zero;
        }
    }

    public enum GestureControl
    {
        NoTouch,
        OneMove,
        TwoWait,
        TwoMove,
        TwoRotate,
        TwoScale,
        OutOfControl,
    }
}
