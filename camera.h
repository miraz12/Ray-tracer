//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "base.h"
#include "scene.h"

struct Pixel
{
    Pixel(){}
    
    ColorDbl colInt;
};

class Camera {

public:
    Camera();
    virtual ~Camera();
    void Render();
    ColorDbl BounceRay(Ray* arg, int bounce);
    void CreateImage();
    void CreateRays();


private:
    inline double toInt(double x) {
        return pow(x, 1 / 2.2f) * 255;
    }


    Vertex eye0, eye1;
    int eyeChoice = 0;
    float clrMax = 0;
    Scene* scene;
    Random rand;


    //800 × 800
    static const int width = 800;
    static const int  height = 800;

    Pixel screen[width][height];


    int missedRays;
};


#endif //RAY_TRACER_CAMERA_H
