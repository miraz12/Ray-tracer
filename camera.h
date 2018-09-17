//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "base.h"

struct Pixel
{
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
    int eyeChoice = 0;

    Pixel screen[800][800];

};


#endif //RAY_TRACER_CAMERA_H
