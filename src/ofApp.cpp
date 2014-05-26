#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    mountain.loadModel("mountainBiggest.obj");
    mountain.setPosition(0, -100, 0);

    showFR = false;
    
    cam.setup();
    cam.reset(-35);
    //cam.lockHeight = false;
    cam.setMinMaxY(40, 40);
    cam.speed = 0.5f;
    //camTargSet = false;
    
    centerSphere.setRadius(30);
    centerSphere.setResolution(12);
    centerSphere.setMode(OF_PRIMITIVE_TRIANGLES);
    
//    ringSize = (ofGetWidth()/5) * (ofGetWidth()/5);
//    thickness = (ofGetWidth()/6) * (ofGetWidth()/6);
    
    ringSize = 150;
    thickness = 170;
    
    ringSize*=ringSize;
    thickness*=thickness;
    
//    cout << "ring size: " << sqrt(ringSize) << endl;
//    cout << "thickness: " << sqrt(thickness) << endl;
    
    cylRadius = 400;
    circSlices = 50;
    numRows = 40;
    wedgeAngle = ofDegToRad(360.0/circSlices);
    
    int cirCount = 0;
    float radSqared = 400 * 400;
    int step = 40;
    for (int i = -cylRadius; i < cylRadius; i+=step) {
        for (int j = -cylRadius; j < cylRadius; j+=step) {
            if (ofDistSquared(i, j, 0, 0) < radSqared) {
                cirCount++;
            }
        }
    }
//    cout << cirCount << endl;
    int numDetectors = (circSlices * numRows) + 2 * cirCount;
    
    dets.resize(numDetectors);
    int counter = 0;
    
    
    for (int i = -cylRadius; i < cylRadius; i+=step) {
        for (int j = -cylRadius; j < cylRadius; j+=step) {
            if (ofDistSquared(i, j, 0, 0) < radSqared) {
                
                counter = (int) ofClamp(counter, 0, numDetectors);
                
                Detector d;
                d.setup(i, -(numRows/2)*20, j);
                dets[counter] = d;
                counter++;
            }
        }
    }
    
    
    
    for (float j = -(numRows/2); j < numRows/2; j++) {
        for (float i = 0; i < ofDegToRad(360); i+=wedgeAngle) {
            
            counter = (int) ofClamp(counter, 0, numDetectors);
            
            float x = cylRadius * cos(i);
            float z = cylRadius * sin(i);
            
            Detector d;
            d.setup(x, j*20, z);
            dets[counter] = d;
            counter++;
            
        }
    }
    
    for (int i = -cylRadius; i < cylRadius; i+=step) {
        for (int j = -cylRadius; j < cylRadius; j+=step) {
            if (ofDistSquared(i, j, 0, 0) < radSqared) {
                
                counter = (int) ofClamp(counter, 0, numDetectors);
                
                Detector d;
                d.setup(i, (numRows/2)*20, j);
                dets[counter] = d;
                counter++;
            }
        }
    }
    
    mountain.update();
    mountMesh = mountain.getCurrentAnimatedMesh(0);
    
    
    
    #ifdef __APPLE__
        CGDisplayHideCursor(NULL); // <- Sometimes necessary to hide cursor on Macs
    #endif
    ofHideCursor();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    glShadeModel(GL_SMOOTH);
    ofEnableSeparateSpecularLight();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofRandom(0,1000) > 991) {
        float xTrig = ofRandom(-400,400);
        float yTrig = ofRandom(-400,400);
        float zTrig = ofRandom(-400,400);
        for (int i = 0; i < dets.size(); i++){
            dets[i].hit(xTrig,yTrig,zTrig,ringSize,thickness);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDisableLighting();
    ofBackground(0);

    cam.begin();
    
    ofPushMatrix();
    ofScale(0.1, 0.1, 0.1);
    glLineWidth(2);
    for (int i = 0; i < dets.size(); i++){
        dets[i].draw();
    }
    
    ofSetColor(255);
    
//    centerSphere.setPosition(0,0,0);
//    centerSphere.drawWireframe();
    
    ofPopMatrix();
    
    float mountainColor = ofClamp(ofMap(ofDistSquared(0, 0, cam.getPosition().x, cam.getPosition().z), 0, 10000, 0, 120),0,120);
    cam.speed = ofMap(mountainColor, 0, 120, 0.5, 1.2);
    ofSetColor(mountainColor);
    glLineWidth(1);
    mountain.drawWireframe();
    
    
    cam.end();
    
    
    if (showFR) {
        ofSetColor(255);
        ofDrawBitmapString(ofToString(ofGetFrameRate(),2), 50,ofGetHeight()-50);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':{
            float xTrig = ofRandom(-400,400);
            float yTrig = ofRandom(-400,400);
            float zTrig = ofRandom(-400,400);
            for (int i = 0; i < dets.size(); i++){
                dets[i].hit(xTrig,yTrig,zTrig,ringSize,thickness);
            }
            break;
        }
            
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'z':
            showFR = !showFR;
            break;
            
        default:
            break;
    }

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
    
    float xTrig = ofRandom(-400,400);
    float yTrig = ofRandom(-400,400);
    float zTrig = ofRandom(-400,400);
    for (int i = 0; i < dets.size(); i++){
        dets[i].hit(xTrig,yTrig,zTrig,ringSize,thickness);
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
