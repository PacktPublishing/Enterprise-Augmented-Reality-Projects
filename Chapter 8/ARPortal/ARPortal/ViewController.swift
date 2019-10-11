//
//  ViewController.swift
//  ARPortal
//
//  Created by me on 17/09/2019.
//  Copyright © 2019 Banana. All rights reserved.
//

import UIKit
import SceneKit
import ARKit

class ViewController: UIViewController, ARSCNViewDelegate, ARSessionDelegate {

    @IBOutlet var sceneView: ARSCNView!
    @IBOutlet weak var infoLabel: UILabel!
    var planes = [ARPlaneAnchor: SCNPlane]()
    var portal: SCNNode? = nil
    var compass: SCNNode? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Set the view's delegate
        sceneView.delegate = self
        
        // Show statistics such as fps and timing information
        sceneView.showsStatistics = true
        // Uncomment to see the feature points
        //sceneView.debugOptions = ARSCNDebugOptions.showFeaturePoints
        
        // Create a new scene
        let scene = SCNScene()
        
        // Set the scene to the view
        sceneView.scene = scene
        
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        // Create a session configuration
        let configuration = ARWorldTrackingConfiguration()
        configuration.planeDetection = .horizontal
        // Run the view's session
        sceneView.session.run(configuration)
        sceneView.session.delegate = self
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Pause the view's session
        sceneView.session.pause()
    }

    
    //Uncomment to see the anchor planes
    func renderer(_ renderer: SCNSceneRenderer, nodeFor anchor: ARAnchor) -> SCNNode? {
        if portal == nil && compass == nil
        {
            let node = SCNNode()

            guard let planeAnchor = anchor as? ARPlaneAnchor else {return nil}

            let plane = SCNPlane(width: 0.8, height: 0.8)
            plane.firstMaterial?.diffuse.contents = UIImage(named: "Media.scnassets/compass.png")
            plane.firstMaterial?.transparency = 0.8

            let planeNode = SCNNode(geometry: plane)
            planeNode.position = SCNVector3(x: planeAnchor.center.x, y: planeAnchor.center.y, z: planeAnchor.center.z)
            planeNode.eulerAngles.x = -Float.pi/2

            node.addChildNode(planeNode)

            planes[planeAnchor] = plane
            compass = node

            return node
        }
        return nil
    }

    

    
    func renderer(_ renderer: SCNSceneRenderer, didUpdate node: SCNNode, for anchor: ARAnchor)
    {
//        guard let planeAnchor = anchor as? ARPlaneAnchor else {return}

//        if let plane = planes[planeAnchor]
//        {
            //plane.width = CGFloat(planeAnchor.extent.x)
            //plane.height = CGFloat(planeAnchor.extent.z)

//            node.childNodes.first?.position = SCNVector3(planeAnchor.center.x, planeAnchor.center.y, planeAnchor.center.z)
//        }
        
    }
    
    
    func session(_ session: ARSession, didFailWithError error: Error) {
        // Present an error message to the user
        infoLabel.text = "Session failed : \(error.localizedDescription)."
    }
    
    func sessionWasInterrupted(_ session: ARSession) {
        // Inform the user that the session has been interrupted, for example, by presenting an overlay
        infoLabel.text = "Session was interrupted."
        portal?.removeFromParentNode()
        portal = nil
    }
    
    func sessionInterruptionEnded(_ session: ARSession) {
        // Reset tracking and/or remove existing anchors if consistent tracking is required
        infoLabel.text = "Session interruption ended."
        let configuration = ARWorldTrackingConfiguration()
        configuration.planeDetection = .horizontal
        sceneView.session.run(configuration, options: [.resetTracking, .removeExistingAnchors])
    }
    
    
    func session(_ session: ARSession, didAdd anchors: [ARAnchor])
    {
        //new plane detected but no portal has been added yet
        if portal == nil
        {
            infoLabel.text = "Tap on the floor to create the portal."
        }
    }
    
    func session(_ session: ARSession, cameraDidChangeTrackingState camera: ARCamera) {
        // Update the UI to provide feedback on the state of the AR experience.
        let message: String
        
        switch camera.trackingState {
        case .normal where session.currentFrame!.anchors.isEmpty:
            // No planes detected
            message = "Move the device around to detect horizontal surfaces."
            
        case .notAvailable:
            message = "Tracking unavailable."
            
        case .limited(.excessiveMotion):
            message = "Tracking limited - Move the device more slowly."
            
        case .limited(.insufficientFeatures):
            message = "Tracking limited - Point the device at an area with visible surface detail, or improve lighting conditions."
            
        case .limited(.initializing):
            message = "Initializing AR session."
            
        default:
            // No feedback needed when tracking is normal and planes are visible.
            // (Nor when in unreachable limited-tracking states.)
            message = ""
            
        }
        
        infoLabel.text = message
    }
    
    
    @IBAction func didTapOnScreen(_ sender: UITapGestureRecognizer)
    {
        
        let location = sender.location(in: sceneView)
        
        let hitResults = sceneView.hitTest(location, types: ARHitTestResult.ResultType.existingPlaneUsingExtent)
        
        guard let result = hitResults.first else {return}
        
        //delete previous portal
        if portal != nil
        {
            portal?.removeFromParentNode()
        }
        
        portal = Portal()
            
        if (compass != nil)
        {
            portal?.position = compass!.position
            portal?.rotation = compass!.rotation

            compass?.removeFromParentNode()
            compass = nil
        }
        else
        {
            portal?.position = SCNVector3(x: result.worldTransform.columns.3.x, y: result.worldTransform.columns.3.y, z: result.worldTransform.columns.3.z)
        }
        self.sceneView.scene.rootNode.addChildNode(portal!)
        
        infoLabel.text = ""
    }
}
