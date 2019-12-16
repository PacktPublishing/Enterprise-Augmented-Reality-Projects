using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChairHandler : MonoBehaviour
{
    public GameObject rotateGO;
    private float rotateSpeed = 0.8f;

    // Start is called before the first frame update
    void Start()
    {
        rotateGO.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        Touch[] touches = Input.touches;
        if (Input.touchCount == 2 && (touches[0].phase == TouchPhase.Moved || touches[1].phase == TouchPhase.Moved))
        {
            rotateGO.SetActive(true);

            Vector2 previousPosition = touches[1].position - touches[1].deltaPosition - (touches[0].position - touches[0].deltaPosition);
            Vector2 currentPosition = touches[1].position - touches[0].position;
            float angleDelta = Vector2.Angle(previousPosition, currentPosition);
            Vector3 cross = Vector3.Cross(previousPosition, currentPosition);

            Vector3 previousRotation = transform.localEulerAngles;
            if (cross.z > 0)
            {
                transform.localEulerAngles = previousRotation - new Vector3(0, angleDelta * rotateSpeed, 0);
            }
            else if (cross.z < 0)
            {
                transform.localEulerAngles = previousRotation + new Vector3(0, angleDelta * rotateSpeed, 0);
            }
        }
        else
        {
            rotateGO.SetActive(false);
        }
    }
}
