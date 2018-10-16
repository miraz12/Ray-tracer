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

    float t; 
    float radius2 = radius * radius;
    Direction rayDir;
    rayDir.dir = glm::normalize(glm::vec3(arg->end.vertex - arg->start.vertex));

    glm::vec3 L = center - arg->start.vertex;
    float tca = glm::dot(L, rayDir.dir);
    float d2 = glm::dot(L, L) - tca * tca;
    if (d2 > radius2) 
        return false;
    float thc = sqrt(radius2 - d2);
    float t0 = tca - thc;
    float t1 = tca + thc;

    if (t0 > t1) std::swap(t0, t1);

    if (t0 < 0)
    {
        t0 = t1;
        if (t0 < 0) 
            return false;
    }

    t = t0;
    if (t < arg->t)
    {
        arg->end.vertex = arg->start.vertex + glm::vec4(rayDir.dir, 1.0f) * t;
        arg->hitTri = infoTri;
        infoTri->Normal.dir = glm::normalize(glm::vec3(arg->end.vertex - center));
        if (glm::dot(infoTri->Normal.dir, rayDir.dir) > 0)
        {
            infoTri->Normal.dir = infoTri->Normal.dir * -1.f;
        }
        arg->t = t;
        return true;
    }
    
    return false;
}

Sphere::~Sphere() {}
