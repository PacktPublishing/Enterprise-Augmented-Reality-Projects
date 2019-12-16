//
//  Portal.swift
//  ARPortal
//
//  Created by me on 19/09/2019.
//  Copyright © 2019 Banana. All rights reserved.
//

import ARKit

class Portal: SCNNode
{
    override init()
    {
        super.init()
        add3DModel()
        createPortal()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    
    func add3DModel()
    {
        let modelScene = SCNScene(named: "vangogh_room.obj")!
        let modelNode: SCNNode = modelScene.rootNode.childNodes[0]
        modelNode.renderingOrder = 200
        self.addChildNode(modelNode)
    }
    
    func createWall(width: CGFloat, height: CGFloat, length: CGFloat)->SCNNode
    {
        let node = SCNNode()
        
        //Visible wall
        let wall = SCNBox(width: width, height: height, length: length, chamferRadius: 0)
        //wall.firstMaterial?.diffuse.contents = UIColor.white
        wall.firstMaterial?.diffuse.contents = UIImage(named: "Media.scnassets/wood.jpg")
        let wallNode = SCNNode(geometry: wall)
        wallNode.renderingOrder = 100 //Last to render (inside)
        
        node.addChildNode(wallNode)
        
        //Masked wall
        let maskedWall = SCNBox(width: width, height: height, length: length, chamferRadius: 0)
        maskedWall.firstMaterial?.diffuse.contents = UIColor.white
        maskedWall.firstMaterial?.transparency = 0.000000001
        
        let maskedWallNode = SCNNode(geometry: maskedWall)
        maskedWallNode.renderingOrder = 10 //First to render (outside)
        maskedWallNode.position = SCNVector3.init(0, 0, length)
        
        node.addChildNode(maskedWallNode)
        
        return node
    }
    
    func createPortal()
    {
        let wallWidth: CGFloat = 2
        let doorWidth: CGFloat = 0.8
        let topWidth = 2 * wallWidth + doorWidth
        let height: CGFloat = 2
        let length: CGFloat = 0.05
        
        let portal = SCNNode()
        
        let leftWall = createWall(width: wallWidth, height: height, length: length)
        leftWall.position = SCNVector3(x: Float(-(wallWidth + doorWidth)/2), y: Float(height/2), z: 0)
        
        let rightWall = createWall(width: wallWidth, height: height, length: length)
        rightWall.position = SCNVector3(x: Float((wallWidth + doorWidth)/2), y: Float(height/2), z: 0)
        
        let topWall = createWall(width: topWidth, height: height, length: length)
        topWall.position = SCNVector3(x: 0, y: Float(height*3/2), z: 0)
        
        let bottomWall = createWall(width: topWidth, height: length, length: length)
        
        
        portal.addChildNode(leftWall)
        portal.addChildNode(rightWall)
        portal.addChildNode(topWall)
        portal.addChildNode(bottomWall)
        
        self.addChildNode(portal)
    }
}
