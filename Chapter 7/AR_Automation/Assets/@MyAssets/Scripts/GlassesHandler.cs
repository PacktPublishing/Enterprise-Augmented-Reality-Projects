using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GlassesHandler : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        foreach (Transform child in transform)
        {
            Vector3 scale = child.localScale;
            scale *= 2.5f;
            child.localScale = scale;

            Vector3 position = child.position;
            position += new Vector3(0.5f, 0, 0);
            child.position = position;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
