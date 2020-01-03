To test the app
---------------
Install ARGuide.apk from Apk folder in your Epson Moverio BT-350 glasses and run it.

The AR targets for this project are side.jpg, close.jpg and open.jpg located at Resouces|Images and inside the project. Point first at side.jpg and follow instructions.

NOTE: To open the pdf file you need a external app that opens pdf files. Make sure you have one installed before running the ARGuide.
NOTE II: This app is prepared to be run on the Epson Moverio glasses so it doesn't work like a regular mobile AR app (you won't be seeing the camera background). You should make a few changes in the project for that.


To build the project
--------------------
1- Login at https://developer.vuforia.com/ and create a new license at https://developer.vuforia.com/vui/develop/licenses
2- Copy it inside the Unity scene, in the AR Camera gameObject | Vuforia Behaviour Component | Open Vuforia Engine configuration | App License Key
3- Connect your device via USB (make sure your device allows USB debugging)
4- Press Ctrl+B or go to File|Build Settings|Build and Run