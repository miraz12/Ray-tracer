#include "lightsource.h"


LightSource::LightSource()
{

}

void LightSource::SetLight(Vertex v1, Vertex v2, Vertex v3)
{

    Triangle t;
    t.SetTriangle(v1, v2, v3);
    triangles.push_back(t);
    color = ColorDbl(0.5, 0.5, 0.5);
}

void LightSource::SetLight(Vertex v1, Vertex v2, Vertex v3, ColorDbl c)
{
    Triangle t;
    Material m(c, 0, light);
    t.SetTriangle(v1, v2, v3, m);
    triangles.push_back(t);
    color = c;
}

bool LightSource::RayIntersection(Ray* arg)
{
    for (int i = 0; i < triangles.size(); ++i)
    {
        triangles[i].RayInstersection(arg);
    }
    return false;
}


