//
// Created by shaggy on 9/17/18.
//

#include "triangle.h"

Triangle::Triangle() {}

Triangle::~Triangle() {}

bool Triangle::RayInstersection(Ray* arg)
{
    const float EPSILON = 0.0000001;
    Vertex vertex0 = tri[0];
    Vertex vertex1 = tri[1];
    Vertex vertex2 = tri[2];
    glm::vec3 edge1, edge2, h, s, q;
    float a, f, u, v;

    Direction rayDir;

    rayDir.dir = glm::normalize(glm::vec3(arg->end.vertex - arg->start.vertex));
    edge1 = glm::vec3(vertex1.vertex - vertex0.vertex);
    edge2 = glm::vec3(vertex2.vertex - vertex0.vertex);

    h = glm::cross(rayDir.dir, edge2); //Edge normal
    a = glm::dot(edge1, h); //Determinant

    if (a > -EPSILON && a < EPSILON)
        return false;

    f = 1 / a;
    s = glm::vec3(arg->start.vertex - vertex0.vertex);
    u = f * glm::dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;
    q = glm::cross(s, edge1);
    v = f * glm::dot(rayDir.dir, q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    float t = f * glm::dot(edge2, q);
    if (t > EPSILON) // ray intersection
    {
        glm::vec4 intersection = arg->start.vertex + glm::vec4(rayDir.dir * t, 1.0f);
        arg->hitTri = this;
        arg->end.vertex = intersection;
        arg->color = color;
        arg->t = t;
        arg->normal = this->GetNormal();
        return true;
    }
    else 
        return false;
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
    color = c;
    material = Material(c, 1.0f, diffuse);
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3, Material m)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
    material = m;
}

void Triangle::SetColor(float r, float g, float b)
{
    color.color.x = r;
    color.color.y = g;
    color.color.z = b;
}

glm::vec3 Triangle::GetNormal()
{
    glm::vec3 V1 = tri[1].vertex - tri[0].vertex;
    glm::vec3 V2 = tri[2].vertex - tri[0].vertex;
    glm::vec3 normal;
    normal.x = (V1.y*V2.z) - (V1.z - V2.y);
    normal.y = -((V2.z * V1.x) - (V2.x * V1.z));
    normal.z = (V1.x*V2.y) - (V1.y*V2.x);

    return glm::normalize(normal);
}

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
}

