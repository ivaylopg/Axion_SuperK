#include "detector.h"


//--------------------------------------------------------------
Detector::Detector(){
}

//--------------------------------------------------------------
void Detector::setup(float x, float y){
    pos = ofVec3f(x,y,0);
    isHit = false;
    energyR = 0.0;
    energyB = 0.0;
    energyG = 0.0;
    fadeSpeed = 5 + ofRandom(-2,2);
    sphere.setRadius(size/2);
    sphere.setResolution(sphereRes);
    sphere.setMode(OF_PRIMITIVE_TRIANGLES);
}


//--------------------------------------------------------------
void Detector::update(){
}

//--------------------------------------------------------------
void Detector::draw(){
    if (isHit) {
        energyR-=fadeSpeed;
    }
    energyG-=fadeSpeed;
    energyB-=fadeSpeed;
    
    
    if (energyR < 0) {
        isHit = false;
        energyR = 0;
    }
    
    if (energyG < 60) {
        energyG = 60;
    }
    if (energyB < 60) {
        energyB = 60;
    }
    
    ofSetColor(energyR,energyG,energyB);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRect(0, 0, size, size);
    sphere.setPosition(0,0,0);
    sphere.drawWireframe();
    
    ofPopMatrix();
    
//    ofSetColor(255, 0, 0);
//    ofDrawBitmapString(ofToString(energyR,3), 50, ofGetHeight()-50);
//    ofDrawBitmapString(ofToString(fadeSpeed,3), 50, ofGetHeight()-30);
}

//--------------------------------------------------------------
void Detector::hit(float mX, float mY, float range, float thick){
    float dist = ofDistSquared(mX, mY, pos.x, pos.y);
    if (dist >= range && dist <= (range + thick)) {
        isHit = true;
        energyR = 255;
        fadeSpeed = 5 + ofRandom(-2,2);
    }
    
    if (ofRandom(0,1000)>950) {
        energyB = ofRandom(100,255);
    }
    
    if (ofRandom(0,1000)>999) {
        energyG = ofRandom(100,255);
    }
}