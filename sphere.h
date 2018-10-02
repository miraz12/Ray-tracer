//
// Created by shaggy on 9/26/18.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H


#include <glm/vec4.hpp>
#include "base.h"
#include "triangle.h"


struct Ray;

class Sphere
{

public:
    Sphere(const glm::vec4 center, float radius);
    Sphere(const glm::vec4 center, float radius, Triangle* infoTri);
    bool RayIntersection(Ray* arg);
    virtual ~Sphere();

private:

    glm::vec4 center;
    float radius;
    Triangle* infoTri;
};


#endif //RAY_TRACER_SPHERE_H
