//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

enum ReflectionType
{
    diffuse,
    specular,
    transparent
};

#include "base.h"

class Material {
public:
    Material();
    ~Material();
    Material(const ColorDbl& color, double reflection_coefficient);
    ColorDbl Hit(Ray* arg);

    ColorDbl color;
    double reflectionCoefficient;
    ReflectionType type;
};


#endif //RAY_TRACER_MATERIAL_H
