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

Material::Material(const ColorDbl& color, double reflection_coefficient)
{
    this->color = color;
    this->reflectionCoefficient = reflection_coefficient;
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
        glm::vec3 newDir = dir.dir - 2.0f * (glm::dot(dir.dir, arg->hitTri->GetNormal()) * arg->hitTri->GetNormal());
    }
    else //Transparent
    {
        
    }



}
