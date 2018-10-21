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
    Sphere() = default;
    Sphere(const glm::vec4 center, float radius);
    Sphere(const glm::vec4 center, float radius, Triangle* infoTri);
    virtual ~Sphere();

    ///Find out if ray intersects with sphere
    bool RayIntersection(Ray* arg);
    ///Generate a random point on the sphere
    glm::vec3 GetPointOnSphere();
    ColorDbl GetColor();
    float GetEmission();

private:
    glm::vec4 center;
    float radius;
    Triangle* infoTri;
    Random rand;
};


#endif //RAY_TRACER_SPHERE_H
