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
    Ray* ray;
};

class Camera {

public:
    Camera();
    virtual ~Camera();
    void Render();
    void CreateImage();

private:
    Vertex eye0, eye1;
    Pixel screen[800][800];
    Scene scene; 
    int eyeChoice = 0;
    float clrMax = 0;
};


#endif //RAY_TRACER_CAMERA_H
