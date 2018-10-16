//
// Created by shaggy on 9/17/18.
//

#include "triangle.h"

Triangle::Triangle() {}

Triangle::~Triangle() {}

bool Triangle::RayInstersection(Ray* arg)
{
    const float EPSILON = 0.001f;
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
        glm::vec4 intersection = arg->start.vertex + glm::vec4(rayDir.dir * (float)t, 1.0f);
        arg->hitTri = this;
        if (glm::dot(this->Normal.dir, rayDir.dir) > 0)
        {
            this->Normal.dir = this->Normal.dir * -1.f;
        }

        arg->end.vertex = intersection;
        arg->t = t;
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
    glm::vec3 e1 = glm::vec3(tri[1].vertex - tri[0].vertex);
    glm::vec3 e2 = glm::vec3(tri[2].vertex - tri[0].vertex);
    material = Material(ColorDbl(0, 0, 0), 1.0f, lambertian);
    Normal.dir = glm::normalize(glm::cross(e1, e2));
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
    material = Material(c, 1.0f, lambertian);
    glm::vec3 e1 = glm::vec3(tri[1].vertex - tri[0].vertex);
    glm::vec3 e2 = glm::vec3(tri[2].vertex - tri[0].vertex);
    Normal.dir = glm::normalize(glm::cross(e1, e2));
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3, Material m)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
    material = m;
    glm::vec3 e1 = glm::vec3(tri[1].vertex - tri[0].vertex);
    glm::vec3 e2 = glm::vec3(tri[2].vertex - tri[0].vertex);
    Normal.dir = glm::normalize(glm::cross(e1, e2));
}

glm::vec3 Triangle::GetNormal()
{
    return Normal.dir;
}

double Triangle::Area()
{
    glm::vec3 e1 = glm::vec3(tri[1].vertex - tri[0].vertex);
    glm::vec3 e2 = glm::vec3(tri[2].vertex - tri[0].vertex);
    return glm::length(glm::cross(e1, e2));
}

glm::vec3 Triangle::GetPointOnTri()
{
Random rand;
    float a = rand.GetRandomFloat(0.0, 1.0f);
    float b = rand.GetRandomFloat(0.0, 1.0f);
    if (a + b > 1.0)
    {
        a = 1 - a;
        b = 1 - b;
    }

    float c = 1 - a - b;

    glm::vec4 point = c * tri[2].vertex + a * tri[1].vertex + b * tri[0].vertex;
    return FromBarycentric(glm::vec3(point));

}

glm::vec3 Triangle::FromBarycentric(glm::vec3 point)
{
    return point + 0.001f*glm::vec3(0.0f, 0.0f, -1.0f);
}

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
}

