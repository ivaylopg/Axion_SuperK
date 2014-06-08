#pragma once
#include "ofMain.h"
#include "detNode.h"

class Superk {
    static const int size = 20;
    static const int sphereRes = 2;
    
public:
    Superk();
    
    float neutral = 90;
    
    void setup();
    void update();
    void draw();
    void hit(float mX, float mY, float mZ, float range, float thick);
    
    void resize(int i);
    void addNode(int index, detNode d);
    
    
private:
    vector<detNode> allNodes;
    ofVbo vbo;
    ofSpherePrimitive sphere;
    
//    bool isHit;
//    float energyR;
//    float energyG;
//    float energyB;
//    float fadeSpeed;
//    float neutral;
};