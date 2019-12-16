using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Vuforia;

public class OnTheGoHandler : MonoBehaviour
{
    public GameObject chairButton;
    public Sprite[] buttonSprites;
    private ContentPositioningBehaviour contentPosBehaviour;
    private bool multipleChairs = false;

    // Start is called before the first frame update
    void Start()
    {
        contentPosBehaviour = GetComponent<ContentPositioningBehaviour>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void SwitchMultipleChairs()
    {
        if (!multipleChairs)
        {
            chairButton.GetComponent<UnityEngine.UI.Image>().sprite = buttonSprites[1];
            contentPosBehaviour.DuplicateStage = true;
            multipleChairs = true;
        }
        else
        {
            chairButton.GetComponent<UnityEngine.UI.Image>().sprite = buttonSprites[0];
            contentPosBehaviour.DuplicateStage = false;
            multipleChairs = false;
        }
    }
}
