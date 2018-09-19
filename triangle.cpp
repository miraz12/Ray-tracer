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
    rayDir.dir = glm::normalize(arg->start.vertex - arg->end.vertex);
    edge1 = vertex1.vertex - vertex0.vertex;
    edge2 = vertex2.vertex - vertex0.vertex;

    h = glm::cross(rayDir.dir, edge2); //Edge normal
    a = glm::dot(edge1, h); //Determinant

    if (a > -EPSILON && a < EPSILON)
        return false;

    f = 1 / a; //Inverted determinant
    s = arg->start.vertex - vertex0.vertex; 

    // test bounds
    u = f * glm::dot(s, h); 
    if (u < 0.0 || u > 1.0)
        return false;
    q = glm::cross(s, edge1);
    v = f * glm::dot(rayDir.dir, q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * glm::dot(edge2, q);
    if (t > EPSILON) // ray intersection
    {
        glm::vec4 intersection = arg->start.vertex + glm::vec4(rayDir.dir * t, 1.0f);
        arg->hitTri = this;
        arg->end.vertex = intersection;
        arg->color = color;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
}

void Triangle::SetColor(int r, int g, int b)
{
    color.color.x = r;
    color.color.y = g;
    color.color.z = b;
}

