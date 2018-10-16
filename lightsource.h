//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_LIGHTSOURCE_H
#define RAY_TRACER_LIGHTSOURCE_H

#include <vector>
#include "triangle.h"


class LightSource {

public:
    LightSource();
    void SetLight(Vertex v1, Vertex v2, Vertex v3);
    void SetLight(Vertex v1, Vertex v2, Vertex v3, ColorDbl c);
    bool RayIntersection(Ray* arg);
    std::vector<Triangle> triangles;
    ColorDbl color;
    float emission = 10.0f;
};


#endif //RAY_TRACER_LIGHTSOURCE_H
