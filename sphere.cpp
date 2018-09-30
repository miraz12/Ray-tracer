//
// Created by shaggy on 9/26/18.
//

#include "sphere.h"
#include "base.h"
#include <algorithm>

Sphere::Sphere(const glm::vec4 center, float radius) : center(center), radius(radius) {}

bool Sphere::RayIntersection(Ray* arg)
{

    float t0, t1;
    Direction rayDir;
    rayDir.dir = glm::normalize(glm::vec3(arg->end.vertex - arg->start.vertex));
    
    glm::vec3 L = arg->start.vertex - center;
    float a = glm::dot(rayDir.dir, rayDir.dir);
    float b = 2 * glm::dot(rayDir.dir, L);
    float c = glm::dot(L, L) - radius * radius;

    float d = b * b - 4 * a * c;
    if (d < 0)
    {
        return false;
    }
    if (d == 0)
    {
        t0 = t1 = -0.5 * b / a;
    }
    else
    {
        float q = (b > 0) ? -0.5 * (b + sqrtf(d)) : -0.5 * (b - sqrtf(d));
        t0 = q / a; 
        t1 = c / q;
    }

    if (t0 > t1)
        std::swap(t0, t1);

    if(t0 < 0)
    {
        t0 = t1;
        if(t0 < 0)
            return false;
    }

    arg->end.vertex = arg->start.vertex + glm::vec4(rayDir.dir, 1.0f) * t0;
    arg->color = color;
}

Sphere::~Sphere() {}
