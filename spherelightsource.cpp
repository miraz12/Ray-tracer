#include "spherelightsource.h"

SphereLightSource::SphereLightSource(const glm::vec4 center, float radius)
{
    Material matLight(ColorDbl(1., 1., 1.), 1, ReflectionType::light);
    Triangle* infoTri = new Triangle();
    Vertex tv(0.0, 0.0, 0.0, 1);
    infoTri->SetTriangle(tv, tv, tv, matLight);
    sphere = Sphere(center, radius, infoTri);
}


bool SphereLightSource::RayIntersection(Ray* arg)
{
    return sphere.RayIntersection(arg);
}

glm::vec3 SphereLightSource::GetPointOnSphere()
{
    return sphere.GetPointOnSphere();
}

glm::vec3 SphereLightSource::GetColor()
{
    return sphere.GetColor();
}

float SphereLightSource::GetEmission() 
{
    return sphere.GetEmission();
}
