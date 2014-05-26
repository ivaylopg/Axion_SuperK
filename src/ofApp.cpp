#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    numRows = 25;
    numCols = 45;
    ringSize = (ofGetWidth()/5) * (ofGetWidth()/5);
    thickness = (ofGetWidth()/6) * (ofGetWidth()/6);
    dets.resize(numCols*numRows);
    
    det.setup(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()));
    
    for (int j = 0; j < numRows; j++) {
        for (int i = 0; i < numCols; i++) {
            Detector d;
            d.setup(i * (ofGetWidth()/numCols), j * (ofGetHeight()/numRows));
            dets[j*numCols+i] = d;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofRandom(0,1000) > 993) {
        float xTrig = ofRandom(0,ofGetWidth());
        float yTrig = ofRandom(0, ofGetHeight());
        for (int i = 0; i < dets.size(); i++){
            dets[i].hit(xTrig,yTrig,ringSize,thickness);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    for (int i = 0; i < dets.size(); i++){
        dets[i].draw();
    }
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(),2), 50,ofGetHeight()-50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < dets.size(); i++){
        dets[i].hit(x,y,ringSize,thickness);
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
