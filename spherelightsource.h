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
    ///Intersection check for lightsource
    bool RayIntersection(Ray* arg);
    ///Generate a random point on the sphere
    glm::vec3 GetPointOnSphere();
    ColorDbl GetColor();
    float GetEmission();
    Sphere sphere;

private:
};


#endif //RAY_TRACER_SPHERELIGHTSOURCE_H
