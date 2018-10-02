//
// Created by shaggy on 9/17/18.
//

#include "material.h"
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include "triangle.h"

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

ColorDbl Material::Hit(Ray* arg)
{
    if (type == diffuse)
    {
        return color;
    }
    if (type == specular)
    {
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::reflect(dir.dir, arg->normal);
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        return color;
    }
    else //Transparent, Snell's law
    {
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::refract(dir.dir, arg->normal, float(1.f/ reflectionCoefficient));
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        return color;
    }



}
