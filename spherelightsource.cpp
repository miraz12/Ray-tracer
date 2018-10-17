#include "spherelightsource.h"

SphereLightSource::SphereLightSource(const glm::vec4 center, float radius)
{
    Material matLight(ColorDbl(1., 1., 1.), 1.5, ReflectionType::light);
    Triangle* infoTri = new Triangle();
    Vertex tv(0.0, 0.0, 0.0, 1);
    infoTri->SetTriangle(tv, tv, tv, matLight);
    sphere = Sphere(center, radius, infoTri);
}


bool SphereLightSource::RayIntersection(Ray* arg)
{
    return sphere.RayIntersection(arg);
}
