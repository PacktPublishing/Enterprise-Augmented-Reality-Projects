using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.UI;
using Vuforia;

public class MainHandler : MonoBehaviour
{
    public DefaultTrackableEventHandler targetSide;
    public DefaultTrackableEventHandler targetClose;
    public DefaultTrackableEventHandler targetOpen;

    public GameObject mainMessage;
    public GameObject bottomMessage;
    public GameObject fileButton;
    public GameObject okButton;

    string originalPath;
    string savePath;

    public bool Finished { get; set; }

    private enum State
    {
        Init = 0,
        Side = 1,
        Engine = 2,
        Close = 3,
        Open = 4,
        Plug = 5
    }
    private State state;

    // Start is called before the first frame update
    IEnumerator Start()
    {
        while (!VuforiaARController.Instance.HasStarted) //waits until Vuforia has instanciated the three markers
            yield return null;
        state = State.Init;
        ShowElements();

        originalPath = Application.streamingAssetsPath + "/PDF/WorkOrder_0021.pdf";
        savePath = Application.persistentDataPath + "/WorkOrder_0021.pdf";
    }
    // Update is called once per frame
    void Update()
    {
        if ((state == State.Init && targetSide.found) || (state == State.Engine && targetClose.found) || (state == State.Close && targetOpen.found))
        {
            NextStep();
        }
        else if (state == State.Side)
        {
            if (Input.GetMouseButtonDown(0))
            {
                RaycastHit hit;
                Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
                if (Physics.Raycast(ray, out hit))
                    if (hit.transform.name == "Engine")
                        NextStep();
            }
        }
        else if (state == State.Open && Finished)
        {
            Finished = false;
            NextStep();
        }
    }

    private void ShowElements()
    {
        switch (state)
        {
            case State.Init:
                targetSide.gameObject.SetActive(true);
                targetOpen.gameObject.SetActive(false);
                targetClose.gameObject.SetActive(false);

                mainMessage.SetActive(true);
                bottomMessage.SetActive(false);
                fileButton.SetActive(false);
                okButton.SetActive(false);

                mainMessage.GetComponentInChildren<Text>().text = "Point with the camera at the side of the car to start the maintenance process.";
                break;
            case State.Side:
                mainMessage.SetActive(false);
                bottomMessage.SetActive(true);

                bottomMessage.GetComponentInChildren<Text>().text = "Touch the red components to see instructions.";
                break;
            case State.Engine:
                targetClose.gameObject.SetActive(true);

                mainMessage.SetActive(true);
                bottomMessage.SetActive(false);

                mainMessage.GetComponentInChildren<Text>().text = "One of the spark plugs is broken. Point at the trunk and follow the steps.";
                break;
            case State.Close:
                targetSide.gameObject.SetActive(false);
                targetOpen.gameObject.SetActive(true);

                mainMessage.SetActive(false);
                bottomMessage.SetActive(true);

                bottomMessage.GetComponentInChildren<Text>().text = "Open the trunk to access the engine.";
                break;
            case State.Open:
                targetClose.gameObject.SetActive(false);

                fileButton.SetActive(true);
                okButton.SetActive(true);

                bottomMessage.GetComponentInChildren<Text>().text = "Take the spark plug out and replace it. When you finish press 'Done'";
                break;
            case State.Plug:
                targetOpen.gameObject.SetActive(false);

                mainMessage.SetActive(true);
                bottomMessage.SetActive(false);
                fileButton.SetActive(false);
                okButton.SetActive(false);

                mainMessage.GetComponentInChildren<Text>().text = "Well done, you can take a coffee now :)";
                break;
        }
    }

    private void NextStep()
    {
        state++;
        ShowElements();
    }

    public void ResetInstructions()
    {
        state = 0;
        ShowElements();
    }

    private IEnumerator OpenFileCoroutine()
    {
        WWW www = new WWW(originalPath);
        yield return www;
        if (www.error != null)
            Debug.Log("Error loading: " + www.error);
        else
        {
            byte[] bytes = www.bytes;
            File.WriteAllBytes(savePath, bytes);
            Application.OpenURL(savePath);
        }
    }

    public void OpenPDFFile()
    {
        if (File.Exists(savePath))
            Application.OpenURL(savePath);
        else
            StartCoroutine(OpenFileCoroutine());
    }
}
