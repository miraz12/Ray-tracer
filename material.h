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

    ///Return color of specific material
    ColorDbl Hit(Ray* arg, Scene* s);
    ///Return reflected ray of specific material
    Ray* Reflect(Ray* arg, Scene* s);

    ReflectionType GetType() const { return type; }
    ColorDbl GetColor() const { return color; }
    float GetEmission() const { return emission; }

private:
    ///Generates reflected ray of lambertian material
    Ray* LambertianReflection(Ray* arg);
    ///Generates reflected ray of diffuse materail TODO: Not working as of. WIP
    Ray* DiffuseReflection(Ray* arg);

    ColorDbl color;

    double reflectionCoefficient = 0.799; //color reflected from surface
    ReflectionType type;
    float emission = 400; //Light emitted by lightsource


    Random rand;

};


#endif //RAY_TRACER_MATERIAL_H
