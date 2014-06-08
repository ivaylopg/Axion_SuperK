#pragma once

#include "ofMain.h"
#include "ofxFPSCamera.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"

#include "superk.h"
#include "detNode.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxFPSCamera cam;
    bool camTargSet;
    ofVec3f camPos;
    
    Superk superk;
    detNode dt;
    
    ofxAssimpModelLoader mountain;
    //ofMesh mountMesh;
    //ofLight mountLight;
    
    
    float ringSize;
    float thickness;
    
    int numRows;
    float circSlices;
    
    float cylRadius;
    float wedgeAngle;
    
    ofSpherePrimitive centerSphere;
    
    bool showFR;
    
    ofImage myImage;
    bool printImages;
};
