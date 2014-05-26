#pragma once
#include "ofMain.h"

class Detector {
public:
    Detector();
    
    void setup(float x, float y);
    void update();
    void draw();
    void hit(float mX, float mY);
    
    static const int size = 40;

private:
    float xPos;
    float yPos;
    bool isHit;
    float energy;
    float fadeSpeed;
};