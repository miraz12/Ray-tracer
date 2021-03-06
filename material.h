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

    ///Return BRDF of specific material
    ColorDbl Hit(Ray* arg, Scene* s, int it);
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

    Ray* SpeccularReflection(Ray* arg);

    ColorDbl color;
    double reflectionCoefficient = 0.799;// 0.799; //color reflected from surface
    double refractionIndex = 1.51; //glass [1 (air) , 2.4 (diamond)]
    ReflectionType type;
    float emission = 200; //Light emitted by lightsource
    float roughness = 0; //Lambertian  reflector [0 , inf)

    Random rand;

};


#endif //RAY_TRACER_MATERIAL_H
