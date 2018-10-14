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
        c.color = color.color / glm::pi<float>();
        return c;
    }
    if (type == specular)
    {
       /* Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::reflect(dir.dir, arg->normal);
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s, ++iter);*/
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
    if (type == specular)
    {
        /* Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::reflect(dir.dir, arg->normal);
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s, ++iter);*/
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

    glm::vec3 helper = arg->hitTri->GetNormal() + glm::vec3(1, 1, 1);
    glm::vec3 tangent = glm::normalize(glm::cross(arg->hitTri->GetNormal(), helper));
    float inclination = acos(sqrt(xi));
    float azimuth = 2 * glm::pi<float>() * yj;

    glm::vec3 newDir = arg->hitTri->GetNormal();

    Ray* r = new Ray();

    newDir = glm::normalize(glm::rotate(newDir, inclination, tangent));
    newDir = glm::normalize(glm::rotate(newDir, azimuth, arg->hitTri->GetNormal()));
    r->start.vertex = arg->end.vertex;
    r->end.vertex = arg->start.vertex + glm::vec4(newDir * 15.f, 1.0f);
    r->dir.dir = glm::normalize(r->end.vertex - r->start.vertex);
    r->t = 15.f;

    return r; 


    /*glm::vec3 v1 = glm::normalize(-arg->dir.dir - glm::dot(-arg->dir.dir, arg->hitTri->GetNormal()*arg->hitTri->GetNormal()));
    glm::vec3 v2 = -glm::cross(v1, arg->hitTri->GetNormal());
    glm::vec3 v3 = arg->hitTri->GetNormal();

    float altitude = 2.f * glm::pi<float>() * xi;
    float azimuth = asin(sqrtf(yj));

    //Create new random ray direction
    glm::vec3 newraydir = glm::normalize(glm::rotate(arg->hitTri->GetNormal(), azimuth, v2));
    newraydir = glm::normalize(glm::rotate(newraydir, altitude, v3));


    Ray* r = new Ray();


    r->start.vertex = arg->end.vertex;
    r->end.vertex = arg->start.vertex + glm::vec4(newraydir * 2.f, 1.0f);
    r->dir.dir = glm::normalize(r->end.vertex - r->start.vertex);
    r->t = 2.f;

    return r;*/
}
