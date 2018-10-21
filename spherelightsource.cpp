#include "spherelightsource.h"

SphereLightSource::SphereLightSource(const glm::vec4 center, float radius)
{
    Material matLight(ColorDbl(4., 4., 4.), 1, light);
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

ColorDbl SphereLightSource::GetColor()
{
    return sphere.GetColor();
}

float SphereLightSource::GetEmission() 
{
    return sphere.GetEmission();
}
