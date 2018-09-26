//
// Created by shaggy on 9/26/18.
//

#include "tetrahedron.h"

Tetrahedron::Tetrahedron()
{

}

bool Tetrahedron::RayIntersection(Ray *arg)
{
    int inters = 0;
    Ray original = *arg;
    Ray interRay = *arg;
    glm::vec4 end = arg->end.vertex;

    for (int i = 0; i < 4; ++i)
    {
        if(mesh[i].RayInstersection(arg))
        {
            inters++;
            if (arg->t <= interRay.t)
            {
                interRay = *arg;
            }
            arg->end.vertex = end;
        }
    }

    if (inters > 1)
    {
        arg->end = interRay.end;
        arg->color = interRay.color;
        arg->hitTri = interRay.hitTri;
        return true;
    }
    else
    {
        arg->end = original.end;
        arg->color = original.color;
        arg->hitTri = original.hitTri;
        return false;
    }
}

Tetrahedron::Tetrahedron(Vertex v1, Vertex v2, Vertex v3, Vertex v4, ColorDbl c)
{
    mesh[0].SetTriangle(v1, v2, v3, c);
    mesh[1].SetTriangle(v1, v3, v4, c);
    mesh[2].SetTriangle(v1, v2, v4, c);
    mesh[3].SetTriangle(v2, v3, v4, c);
}
