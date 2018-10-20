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
        color = glm::vec3(0.f, 0.f, 0.f);
    }
    ColorDbl(float r, float g, float b)
    {
        color.x = r;
        color.y = g;
        color.z = b;
    }

    ColorDbl& clamp()
    {
        auto clampDouble = [](double x) {
            if (x < 0) return 0.0;
            if (x > 1) return 1.0;
            return x;
        };
        this->color.x = clampDouble(this->color.x); this->color.y = clampDouble(this->color.y); this->color.z = clampDouble(this->color.z);
        return *this;
    }



    glm::vec3 color;
};

struct Ray
{
    Ray(){}
    Vertex start;
    Vertex end;
    Triangle* hitTri = nullptr;
    Direction dir;
    float t = INT32_MAX;
};

#endif //RAY_TRACER_BASE_H
