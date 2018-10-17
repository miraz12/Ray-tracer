//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_SPHERELIGHTSOURCE_H
#define RAY_TRACER_SPHERELIGHTSOURCE_H

#include <vector>
#include "base.h"
#include "sphere.h"

class SphereLightSource {

public:
    SphereLightSource() = default;
    SphereLightSource(const glm::vec4 center, float radius);
    bool RayIntersection(Ray* arg);
    ColorDbl color;
    float emission = 600;
    Sphere sphere; 
};


#endif //RAY_TRACER_SPHERELIGHTSOURCE_H
