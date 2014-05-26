#pragma once
#include "ofMain.h"

class Detector {
    static const int size = 20;
    static const int sphereRes = 3;
    
public:
    Detector();
    
    void setup(float x, float y);
    void update();
    void draw();
    void hit(float mX, float mY, float range, float thick);
    
    ofSpherePrimitive sphere;

private:
    ofVec3f pos;
    bool isHit;
    float energyR;
    float energyG;
    float energyB;
    float fadeSpeed;
};