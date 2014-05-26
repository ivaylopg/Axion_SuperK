#include "detector.h"


//--------------------------------------------------------------
Detector::Detector(){
    xPos = 0;
    yPos = 0;
}

//--------------------------------------------------------------
void Detector::setup(float x, float y){
    xPos = x;
    yPos = y;
    isHit = false;
    energyR = 0.0;
    energyB = 0.0;
    energyG = 0.0;
    fadeSpeed = 5 + ofRandom(-2,2);
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
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofRect(0, 0, size, size);
    ofPopMatrix();
    
//    ofSetColor(255, 0, 0);
//    ofDrawBitmapString(ofToString(energyR,3), 50, ofGetHeight()-50);
//    ofDrawBitmapString(ofToString(fadeSpeed,3), 50, ofGetHeight()-30);
}

//--------------------------------------------------------------
void Detector::hit(float mX, float mY, float range, float thick){
    float dist = ofDistSquared(mX, mY, xPos, yPos);
    if (dist >= range && dist <= (range + thick)) {
        isHit = true;
        energyR = 255;
        fadeSpeed = 5 + ofRandom(-2,2);
    }
    
    if (ofRandom(0,1000)>950) {
        energyG = ofRandom(100,255);
    }
    
    if (ofRandom(0,1000)>999) {
        energyB = ofRandom(100,255);
    }
}