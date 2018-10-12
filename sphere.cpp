//
// Created by shaggy on 9/26/18.
//

#include "sphere.h"
#include "base.h"
#include <algorithm>

Sphere::Sphere(const glm::vec4 center, float radius) : center(center), radius(radius) {}

Sphere::Sphere(const glm::vec4 center, float radius, Triangle* tri) : center(center), radius(radius), infoTri(tri) {}

bool Sphere::RayIntersection(Ray* arg)
{

    Direction rayDir;
    rayDir.dir = glm::normalize(glm::vec3(arg->end.vertex - arg->start.vertex));
    
    glm::vec3 L = arg->start.vertex - center;
    float a = glm::dot(rayDir.dir, rayDir.dir);
    float b = 2 * glm::dot(rayDir.dir, L);
    float c = glm::dot(center, center) + glm::dot(arg->start.vertex, arg->start.vertex) - 2.0f * glm::dot(arg->start.vertex, center) - radius * radius;
    float delta = b*b + (-4.0f) * a * c;


    if (delta < 0)
        return false;

    delta = sqrtf(delta);

    float t = (-0.5f) * (b + delta) / a;

    if (t > 0.0f)
    {
        if (t < arg->t)
        {
            arg->end.vertex = arg->start.vertex + glm::vec4(rayDir.dir, 1.0f) * t;
            arg->hitTri = infoTri;
            infoTri->Normal.dir = arg->end.vertex - center;
            arg->t = t;
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

Sphere::~Sphere() {}
