//
// Created by shaggy on 9/26/18.
//

#ifndef RAY_TRACER_TETRAHEDRON_H
#define RAY_TRACER_TETRAHEDRON_H


#include "triangle.h"

class Tetrahedron {

public:

    Tetrahedron();
    Tetrahedron(Vertex v1, Vertex v2, Vertex v3, Vertex v4, ColorDbl c);

    bool RayIntersection(Ray* arg);
    Triangle mesh[4];


private:
    ColorDbl color;
};


#endif //RAY_TRACER_TETRAHEDRON_H
