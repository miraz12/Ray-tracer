//
// Created by shaggy on 9/26/18.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H


#include <glm/vec4.hpp>

class Sphere
{

public:
    Sphere(const glm::vec4 &center, float radius);

    virtual ~Sphere();

private:

    glm::vec4 center;
    float radius;
};


#endif //RAY_TRACER_SPHERE_H
