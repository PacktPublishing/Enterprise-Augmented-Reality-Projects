package com.banana.arprototype;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.net.Uri;
import android.view.Gravity;
import android.view.MotionEvent;
import android.widget.ImageButton;
import android.widget.Toast;
import com.google.ar.core.Anchor;
import com.google.ar.core.HitResult;
import com.google.ar.core.Plane;
import com.google.ar.sceneform.AnchorNode;
import com.google.ar.sceneform.rendering.ModelRenderable;
import com.google.ar.sceneform.ux.ArFragment;
import com.google.ar.sceneform.ux.TransformableNode;
import com.google.ar.sceneform.math.Quaternion;
import com.google.ar.sceneform.math.Vector3;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private ArFragment arFragment;
    private ModelRenderable modelRenderable;
    private ModelRenderable modelRenderable2;
    private ModelRenderable modelRenderable3;
    private ModelRenderable currentRenderable;
    private Anchor anchor;
    private AnchorNode anchorNode;
    private TransformableNode model;
    private ImageButton button1;
    private ImageButton button2;
    private ImageButton button3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        arFragment = (ArFragment) getSupportFragmentManager().findFragmentById(R.id.ux_fragment);

        ModelRenderable.builder()
                .setSource(this, Uri.parse("engine.sfb"))
                .build()
                .thenAccept(renderable -> currentRenderable = modelRenderable = renderable)
                .exceptionally(
                        throwable -> {
                            Toast toast = Toast.makeText(this, "Unable to load the model", Toast.LENGTH_LONG);
                            toast.setGravity(Gravity.CENTER, 0, 0);
                            toast.show();
                            return null;
                        });
        ModelRenderable.builder()
                .setSource(this, Uri.parse("engine2.sfb"))
                .build()
                .thenAccept(renderable -> modelRenderable2 = renderable)
                .exceptionally(
                        throwable -> {
                            Toast toast = Toast.makeText(this, "Unable to load andy renderable", Toast.LENGTH_LONG);
                            toast.setGravity(Gravity.CENTER, 0, 0);
                            toast.show();
                            return null;
                        });

        ModelRenderable.builder()
                .setSource(this, Uri.parse("engine3.sfb"))
                .build()
                .thenAccept(renderable -> modelRenderable3 = renderable)
                .exceptionally(
                        throwable -> {
                            Toast toast = Toast.makeText(this, "Unable to load andy renderable", Toast.LENGTH_LONG);
                            toast.setGravity(Gravity.CENTER, 0, 0);
                            toast.show();
                            return null;
                        });

        arFragment.setOnTapArPlaneListener(
                (HitResult hitResult, Plane plane, MotionEvent motionEvent) -> {
                    if (modelRenderable == null)
                        return;

                    //Remove previous anchor
                    if (anchor != null)
                    {
                        arFragment.getArSceneView().getScene().removeChild(anchorNode);
                        anchor.detach();
                        anchorNode.setParent(null);
                        anchorNode = null;
                    }

                     anchor = hitResult.createAnchor();
                     anchorNode = new AnchorNode(anchor);
                    anchorNode.setParent(arFragment.getArSceneView().getScene());

                     model = new TransformableNode(arFragment.getTransformationSystem());
                    model.setLocalScale(new Vector3(0.55f, 0.55f, 0.55f));
                    model.setLocalRotation(Quaternion.eulerAngles(new Vector3(-90,45,0)));
                    model.setParent(anchorNode);
                    model.setRenderable(currentRenderable);
                    model.select();
                });

        button1 = findViewById(R.id.engine1_button);
        button2 = findViewById(R.id.engine2_button);
        button3 = findViewById(R.id.engine3_button);

        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        button3.setOnClickListener(this);
    }

    @Override
    public void onClick(View view)
    {
        switch (view.getId()) {
            case R.id.engine1_button:
                currentRenderable = modelRenderable;
                button1.setBackgroundColor(0xFFA4FF50);
                button2.setBackgroundColor(0x40000000);
                button3.setBackgroundColor(0x40000000);
                break;
            case R.id.engine2_button:
                currentRenderable = modelRenderable2;
                button1.setBackgroundColor(0x40000000);
                button2.setBackgroundColor(0xFFA4FF50);
                button3.setBackgroundColor(0x40000000);
                break;
            case R.id.engine3_button:
                currentRenderable = modelRenderable3;
                button1.setBackgroundColor(0x40000000);
                button2.setBackgroundColor(0x40000000);
                button3.setBackgroundColor(0xFFA4FF50);
                break;
        }
        model.setRenderable(currentRenderable);
    }
}

