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
    energy = 0.0;
    fadeSpeed = 5 + ofRandom(-2,2);
}


//--------------------------------------------------------------
void Detector::update(){
}

//--------------------------------------------------------------
void Detector::draw(){
    if (isHit) {
        energy-=fadeSpeed;
    }
    
    if (energy < 0) {
        isHit = false;
        energy = 0;
    }
    
    ofSetColor(energy,60,60);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofRect(0, 0, size, size);
    ofPopMatrix();
    
//    ofSetColor(255, 0, 0);
//    ofDrawBitmapString(ofToString(energy,3), 50, ofGetHeight()-50);
//    ofDrawBitmapString(ofToString(fadeSpeed,3), 50, ofGetHeight()-30);
}

//--------------------------------------------------------------
void Detector::hit(float mX, float mY){
    isHit = true;
    energy = 255;
    fadeSpeed = 5 + ofRandom(-2,2);
}