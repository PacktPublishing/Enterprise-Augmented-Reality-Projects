using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Blinking : MonoBehaviour
{
    private IEnumerator coroutine;
    private bool blinking;
    // Start is called before the first frame update
    void Start()
    {
        coroutine = BlinkingArrow();
        blinking = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (GetComponentInParent<DefaultTrackableEventHandler>().found && !blinking)
        {
            blinking = true;
            StartCoroutine(coroutine);
        }
        else if (!GetComponentInParent<DefaultTrackableEventHandler>().found && blinking)
        {
            blinking = false;
            StopAllCoroutines();
            GetComponent<MeshRenderer>().enabled = false;
        }
    }
    private IEnumerator BlinkingArrow()
    {
        while (true)
        {
            GetComponent<MeshRenderer>().enabled = false;
            yield return new WaitForSeconds(0.5f);
            GetComponent<MeshRenderer>().enabled = true;
            yield return new WaitForSeconds(0.5f);
        }
    }
}
