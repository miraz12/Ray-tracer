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
    if (type == diffuse) //Oren-Nayar
    {
        glm::vec3 normal = arg->hitTri->Normal.dir;
        glm::vec3 dir = glm::normalize(arg->end.vertex - arg->start.vertex);
        glm::vec3 shadowRayDir = arg->shadowRay.dir;
        float sigma2 = powf(roughness, 2);
        float A = 1.f - 0.5f * (sigma2 / (sigma2 + 0.33f));
        float B = 0.45f * (sigma2 / (sigma2 + 0.09f));
        float cos_theta_d1 = glm::dot(dir, normal);
        float cos_theta_d2 = glm::dot(shadowRayDir, normal);
        float theta_d1 = glm::acos(cos_theta_d1);
        float theta_d2 = glm::acos(cos_theta_d2);
        float alpha = glm::max(theta_d1, theta_d2);
        float beta = glm::min(theta_d1, theta_d2);
        float cos_d1_d2 = glm::dot(dir, shadowRayDir);

        ColorDbl c;
        c.color = color.color / glm::pi<float>() * (A + (B * glm::max(0.f, cos_d1_d2)) * glm::sin(alpha) * glm::tan(beta));
        return c;
    }
    if (type == specular)
    {
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::reflect(dir.dir, arg->hitTri->Normal.dir);
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s);
    }
    if(type == transparent)//Transparent, Snell's law
    {
        Direction dir;
        dir.dir = arg->end.vertex - arg->start.vertex;
        glm::vec3 newDir = glm::refract(dir.dir, arg->hitTri->Normal.dir, float(1.f/ refractionIndex)); //From air(1.f) to glass (1.51f)
        arg->start.vertex = arg->end.vertex;
        arg->end.vertex = arg->start.vertex + 2.0f * glm::vec4(newDir, 1.0f) - arg->start.vertex;
        s->FindInstersections(arg);
        return arg->hitTri->material.Hit(arg, s);
    }
    if(type == light)
    {
        ColorDbl c;
        c.color = color.color / glm::pi<float>();
        return c;
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
        return LambertianReflection(arg);
    }
    if (type == specular)
    {
        return LambertianReflection(arg);
    }
    if (type == transparent)//Transparent, Snell's law
    {
        return LambertianReflection(arg);
    }
    if (type == light)
    {
        assert("Trying to reflect at lightsource");
    }


}

Ray* Material::LambertianReflection(Ray* arg)
{
    float xi = rand.GetRandomFloat(0.0, 1.0);
    float yj = rand.GetRandomFloat(0.0, 1.0);

    glm::vec3 v1 = glm::normalize(-arg->dir.dir - glm::dot(-arg->dir.dir, arg->hitTri->Normal.dir*arg->hitTri->Normal.dir));
    glm::vec3 v2 = -glm::cross(v1, arg->hitTri->Normal.dir);
    glm::vec3 v3 = arg->hitTri->Normal.dir;

    float altitude = 2.f * glm::pi<float>() * xi;
    float azimuth = asin(sqrtf(yj));

    //Create new random ray direction
    glm::vec3 newraydir = glm::normalize(glm::rotate(arg->hitTri->Normal.dir, azimuth, v2));
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
