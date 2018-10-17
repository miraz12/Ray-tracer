//
// Created by shaggy on 9/26/18.
//

#include "sphere.h"
#include "base.h"
#include <algorithm>
#include <glm/ext/scalar_constants.inl>

Sphere::Sphere(const glm::vec4 center, float radius) : center(center), radius(radius) {}

Sphere::Sphere(const glm::vec4 center, float radius, Triangle* tri) : center(center), radius(radius), infoTri(tri) {}

bool Sphere::RayIntersection(Ray* arg)
{
    const float EPSILON = 0.001f;

    glm::vec3 dir = glm::normalize(arg->end.vertex - arg->start.vertex);
    glm::vec3 offset = arg->start.vertex - center;
    double a = glm::dot(dir, dir);
    double b = 2 * glm::dot(offset, dir);
    double c = glm::dot(offset, offset) - radius * radius;

    double disc = b * b - 4 * a *c;

    if (disc < 0 )
    {
        return false;
    }


    disc = sqrt(disc);

    double t = -b - disc;
    if (t > EPSILON)
    {
        t /= 2;

        if (t < arg->t)
        {
            arg->end.vertex = arg->start.vertex + glm::vec4(dir, 1.0f) * (float)t;
            arg->hitTri = infoTri;
            infoTri->Normal.dir = glm::normalize(glm::vec3(arg->end.vertex - center));
            if (glm::dot(infoTri->Normal.dir, dir) > 0)
            {
                infoTri->Normal.dir = infoTri->Normal.dir * -1.f;
            }
            arg->t = t;
            return true;
        }
    }
    t = -b + disc;
    if (t > EPSILON)
    {
        t /= 2;

        if (t < arg->t)
        {
            arg->end.vertex = arg->start.vertex + glm::vec4(dir, 1.0f) * (float)t;
            arg->hitTri = infoTri;
            infoTri->Normal.dir = glm::normalize(glm::vec3(arg->end.vertex - center));
            if (glm::dot(infoTri->Normal.dir, dir) > 0)
            {
                infoTri->Normal.dir = infoTri->Normal.dir * -1.f;
            }
            arg->t = t;
            return true;
        }
    }

    return false;



    /*
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
    if (t > EPSILON) // ray intersection
    {
        if (t < arg->t)
        {
            arg->end.vertex = arg->start.vertex + glm::vec4(rayDir.dir, 1.0f) * t;
            arg->hitTri = infoTri;
            infoTri->Normal.dir = glm::normalize(glm::vec3(arg->end.vertex - center / radius));
            if (glm::dot(infoTri->Normal.dir, rayDir.dir) > 0)
            {
                infoTri->Normal.dir = infoTri->Normal.dir * -1.f;
            }
            arg->t = t;
            return true;
        }
    }
    
    return false;*/
}

glm::vec3 Sphere::GetPointOnSphere()
{
    double theta = rand.GetRandomDouble(0.0, 1.0);
    double phi = rand.GetRandomDouble(0.0, 1.0) * 2.0 * glm::pi<double>();

    double dxr = radius * sin(theta) * cos(phi);
    double dyr = radius * sin(theta) * sin(phi);
    double dzr = radius * cos(theta);
    return glm::vec3(center.x + dzr, center.y + dxr, center.z + dyr);
}

Sphere::~Sphere() {}
