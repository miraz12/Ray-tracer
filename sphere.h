//
// Created by shaggy on 9/26/18.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H


#include <glm/vec4.hpp>
#include "base.h"

struct Ray;

class Sphere
{

public:
    Sphere(const glm::vec4 center, float radius);
    bool RayIntersection(Ray* arg);
    virtual ~Sphere();

private:

    glm::vec4 center;
    float radius;
    ColorDbl color = ColorDbl(0.3, 0.3, 0.3);
};


#endif //RAY_TRACER_SPHERE_H
