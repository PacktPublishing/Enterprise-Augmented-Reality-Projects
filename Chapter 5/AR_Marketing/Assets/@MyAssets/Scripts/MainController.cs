using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MainController : MonoBehaviour
{
    public Material[] materials;
    public Texture2D[] textures;

    public Image color_button;
    private Color32 red = new Color32(159, 40, 40, 255);
    private Color32 blue = new Color32(40, 74, 159, 255);

    // Start is called before the first frame update
    void Start()
    {
        foreach (Material material in materials)
        {
            material.mainTexture = textures[0];
        }

        color_button.color = red;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ChangeColor()
    {
        foreach (Material material in materials)
        {
            if (material.mainTexture == textures[0])
                material.mainTexture = textures[1];
            else
                material.mainTexture = textures[0];
        }

        if (color_button.color == red)
            color_button.color = blue;
        else
            color_button.color = red;
    }
}
