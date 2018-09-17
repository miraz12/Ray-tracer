//
// Created by shaggy on 9/17/18.
//

#include "triangle.h"


Triangle::Triangle() {}

Triangle::~Triangle() {}

bool Triangle::RayInstersection(Ray arg)
{
    //TODO: M¨oller-Trumbore algorithm
    return false;
}

void Triangle::SetTriangle(Vertex v1, Vertex v2, Vertex v3)
{
    tri[0] = v1;
    tri[1] = v2;
    tri[2] = v3;
}

