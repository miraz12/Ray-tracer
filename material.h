//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

class Scene;

enum ReflectionType
{
    lambertian,
    diffuse,
    specular,
    transparent,
    light
};

#include "base.h"
#include "random.h"

class Material {
public:
    Material();
    ~Material();
    Material(const ColorDbl& color, double reflection_coefficient, ReflectionType type);
    
    ColorDbl Hit(Ray* arg, Scene* s);
    Ray* Reflect(Ray* arg, Scene* s);

    Ray* LambertianReflection(Ray* arg);
    Ray* DiffuseReflection(Ray* arg);

    ColorDbl color;
    double reflectionCoefficient = 0.799;
    ReflectionType type;
    Random rand;
};


#endif //RAY_TRACER_MATERIAL_H
