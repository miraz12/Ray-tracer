//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_BASE_H
#define RAY_TRACER_BASE_H
#include <glm/glm.hpp> 

class Triangle;

struct Vertex
{
    Vertex(){};

    Vertex(float ix, float iy, float iz)
    {
        vertex = glm::vec4(ix, iy, iz, 1.0f);
    }
    Vertex(float ix, float iy, float iz, float iw)
    {
        vertex = glm::vec4(ix, iy, iz, iw);
    }
    glm::vec4 vertex = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
};

struct Direction
{
    Direction(){}
    glm::vec3 dir = glm::vec3(0.0f, 0.0f, 0.0f);
};

struct ColorDbl
{
    ColorDbl()
    {
        color = glm::vec3(1.f, 1.f, 1.f);
    }
    ColorDbl(int r, int g, int b)
    {
        color.x = r;
        color.y = g;
        color.z = b;
    }

    glm::vec3 color;
};

struct Ray
{
    Ray(){}
    Vertex start;
    Vertex end;
    Triangle* hitTri;
    ColorDbl color;
};

#endif //RAY_TRACER_BASE_H
