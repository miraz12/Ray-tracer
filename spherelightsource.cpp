#include "spherelightsource.h"

SphereLightSource::SphereLightSource(const glm::vec4 center, float radius)
{
    sphere = Sphere(center, radius);
}


bool SphereLightSource::RayIntersection(Ray* arg)
{
    return false;
}
