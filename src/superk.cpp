#include "superk.h"


//--------------------------------------------------------------
Superk::Superk(){
}

//--------------------------------------------------------------
void Superk::setup(){
    /*
    pos = ofVec3f(x,y,z);
    isHit = false;
    energyR = 0.0;
    energyB = 0.0;
    energyG = 0.0;
    fadeSpeed = 5 + ofRandom(-2,2);
    neutral = 90;
    */
    
    sphere.setRadius(size/2);
    sphere.setResolution(sphereRes);
    sphere.setMode(OF_PRIMITIVE_TRIANGLES);
    sphere.setPosition(0,0,0);
    ofMesh mesh = sphere.getMesh();
    vbo.setMesh(mesh, GL_STATIC_DRAW);
}


//--------------------------------------------------------------
void Superk::update(){
}

//--------------------------------------------------------------
void Superk::draw(){
    
    for (int i = 0; i < allNodes.size(); i++){
        ofPushMatrix();
        ofTranslate(allNodes[i].nodePos);
        if (allNodes[i].nodeIsHit) {
            allNodes[i].energyR-=allNodes[i].fadeSpeed;
        }
        
        allNodes[i].energyG-=allNodes[i].fadeSpeed;
        allNodes[i].energyB-=allNodes[i].fadeSpeed;
        
        
        if (allNodes[i].energyR < 0) {
            allNodes[i].nodeIsHit = false;
            allNodes[i].energyR = 0;
        }
        
        if (allNodes[i].energyG < neutral) {
            allNodes[i].energyG = neutral;
        }
        if (allNodes[i].energyB < neutral) {
            allNodes[i].energyB = neutral;
        }
        
        ofSetColor(allNodes[i].energyR,allNodes[i].energyG,allNodes[i].energyB);
        
        //sphere.drawWireframe();
        vbo.drawElements(GL_LINE_STRIP, vbo.getNumIndices());
        ofSetColor(255);
        ofPopMatrix();
    }
    
    
    
    /*
    ofPushMatrix();
    ofTranslate(pos.x, pos.y, pos.z);
    //    ofSetRectMode(OF_RECTMODE_CENTER);
    //    ofRect(0, 0, size, size);
    //sphere.setPosition(0,0,0);
    sphere.drawWireframe();
    
    ofPopMatrix();
     */
    
    //    ofSetColor(255, 0, 0);
    //    ofDrawBitmapString(ofToString(energyR,3), 50, ofGetHeight()-50);
    //    ofDrawBitmapString(ofToString(fadeSpeed,3), 50, ofGetHeight()-30);
}

//--------------------------------------------------------------
void Superk::hit(float mX, float mY, float mZ, float range, float thick){
    /*
    float dist = ofDistSquared(mX, mY, pos.x, pos.y);
    if (dist >= range && dist <= (range + thick) && ofRandom(0, 10) > 3) {
        isHit = true;
        energyR = 255;
        fadeSpeed = 5 + ofRandom(-2,2);
    }
    
    if (ofRandom(0,1000)>950) {
        energyB = ofRandom(neutral+40,255);
    }
    
    if (ofRandom(0,1000)>999) {
        energyG = ofRandom(neutral+40,255);
    }
    */
}

//--------------------------------------------------------------
void Superk::resize(int i){
    allNodes.resize(i);
}

//--------------------------------------------------------------
void Superk::addNode(int index, detNode d){
    allNodes[index] = d;
}
