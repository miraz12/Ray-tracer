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
    std::vector<Ray*> rays;

    Ray* ray;
};

class Camera {

public:
    Camera();
    virtual ~Camera();
    void Render();
    ColorDbl BounceRay(Ray* arg);
    void CreateImage();
    void CreateRays();


private:
    Vertex eye0, eye1;
    int eyeChoice = 0;
    float clrMax = 0;
    Scene* scene;
    Random rand;


    //800 × 800
    static const int width = 800;
    static const int  height = 800;

    Pixel screen[width][height];
};


#endif //RAY_TRACER_CAMERA_H
