//
// Created by shaggy on 9/17/18.
//

#include "material.h"
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include "triangle.h"
#include "scene.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/rotate_vector.hpp> 

Material::Material()
{
}

Material::~Material()
{
}

Material::Material(const ColorDbl& color, double reflection_coefficient, ReflectionType type)
{
    this->color = color;
    this->reflectionCoefficient = reflection_coefficient;
    this->type = type;
}

ColorDbl Material::Hit(Ray* arg, Scene* s)
{
    if (type == lambertian)
    {
        ColorDbl c;
        c.color = color.color * (float)reflectionCoefficient / glm::pi<float>();
        return c;
    }
    if (type == diffuse)
    {
        ColorDbl c;
        c.color = color.color * (float)reflectionCoefficient / glm::pi<float>();
        return c;
    }
    if (type == specular)
    {
        return color;
    }
    if(transparent)//Transparent, Snell's law
    {
        /*
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::refract(dir.dir, arg->normal, float(1.f/ reflectionCoefficient));
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s, ++iter);*/
    }
    if(light)
    {
        return color;
    }
}

Ray* Material::Reflect(Ray* arg, Scene* s)
{

    if (type == lambertian)
    {
        
        return LambertianReflection(arg);;
    }
    if (type == diffuse)
    {
        return DiffuseReflection(arg);
    }
    if (type == specular)
    {
        Ray* r = new Ray();
        Direction dir;
        dir.dir = glm::normalize(arg->end.vertex - arg->start.vertex);
        glm::vec3 newDir = glm::reflect(dir.dir, arg->hitTri->Normal.dir);
        if (glm::dot(newDir, arg->dir.dir) > 0)
        {
            newDir *= -1;
        }
        r->start.vertex = arg->end.vertex;
        r->end.vertex = r->start.vertex + 100.0f * glm::vec4(newDir, 1.0f);
        return r;
    }
    if (transparent)//Transparent, Snell's law
    {
        /*
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::refract(dir.dir, arg->normal, float(1.f/ reflectionCoefficient));
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s, ++iter);*/
    }
    else 
    {
        return arg;
    }


}

Ray* Material::LambertianReflection(Ray* arg)
{
    float xi = rand.GetRandomFloat(0.0, 1.0);
    float yj = rand.GetRandomFloat(0.0, 1.0);

    glm::vec3 v1 = glm::normalize(-arg->dir.dir - glm::dot(-arg->dir.dir, arg->hitTri->GetNormal()*arg->hitTri->GetNormal()));
    glm::vec3 v2 = -glm::cross(v1, arg->hitTri->GetNormal());
    glm::vec3 v3 = arg->hitTri->GetNormal();

    float altitude = 2.f * glm::pi<float>() * xi;
    float azimuth = asin(sqrtf(yj));

    //Create new random ray direction
    glm::vec3 newraydir = glm::normalize(glm::rotate(arg->hitTri->GetNormal(), azimuth, v2));
    newraydir = glm::normalize(glm::rotate(newraydir, altitude, v3));


    Ray* r = new Ray();

    r->start.vertex = arg->end.vertex;
    r->end.vertex = arg->start.vertex + glm::vec4(newraydir * 100.f, 0.0f);
    r->dir.dir = glm::vec3(glm::normalize(r->end.vertex - r->start.vertex));
    r->t = 100.f;

    return r;
}

Ray* Material::DiffuseReflection(Ray* arg)
{
    Ray* r = new Ray();
    Direction dir;
    float angle = 2 * M_PI * rand.GetRandomDouble(0.0, 0.1);
    float dist_cen = sqrt(rand.GetRandomDouble(0.0, 1.0));
    glm::vec3 u;

    if (fabs(arg->hitTri->Normal.dir.x) > 0.1)
    {
        u = glm::vec3(0, 1, 0);
    }
    else
    {
        u = glm::vec3(1, 0, 0);
    }
    u = glm::normalize(glm::cross(u, arg->hitTri->Normal.dir));
    glm::vec3 v = glm::cross(arg->hitTri->Normal.dir, u);
    //reflection dir
    glm::vec3 d = glm::normalize(u*cos(angle)*dist_cen + v * sin(angle) * dist_cen + arg->hitTri->Normal.dir * sqrt(1 - dist_cen * dist_cen));
    if (glm::dot(d, arg->dir.dir) > 0)
    {
        d *= -1;
    }
    r->start.vertex = arg->end.vertex;
    r->end.vertex = r->start.vertex + 100.0f * glm::vec4(d, 1.0f);
    return r;
}
