#pragma once
#include "ofMain.h"

class Detector {
    static const int size = 20;
    static const int sphereRes = 2;
    
public:
    Detector();
    
    void setup(float x, float y, float z);
    void update();
    void draw();
    void hit(float mX, float mY, float mZ, float range, float thick);
    
    ofSpherePrimitive sphere;

private:
    ofVec3f pos;
    bool isHit;
    float energyR;
    float energyG;
    float energyB;
    float fadeSpeed;
};