using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeHandler : MonoBehaviour
{
    private float speed;
    public Texture2D texture;

    // Start is called before the first frame update
    void Start()
    {
        speed = 0.5f;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(Vector3.up * speed);

        if (Input.GetKeyDown(KeyCode.A))
            GetComponent<Renderer>().material.mainTexture = texture;
    }
}
