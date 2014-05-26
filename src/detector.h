#pragma once
#include "ofMain.h"

class Detector {
public:
    Detector();
    
    void setup(float x, float y);
    void update();
    void draw();
    void hit(float mX, float mY, float range, float thick);
    
    static const int size = 20;

private:
    float xPos;
    float yPos;
    bool isHit;
    float energyR;
    float energyG;
    float energyB;
    float fadeSpeed;
};