//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_TRIANGLE_H
#define RAY_TRACER_TRIANGLE_H

#include <vector>
#include "base.h"

class Triangle {
public:
    Triangle();
    virtual ~Triangle();

    bool RayInstersection(Ray arg);


private:
    Vertex tri[3];
    ColorDbl color;
    Direction Normal;
};


#endif //RAY_TRACER_TRIANGLE_H