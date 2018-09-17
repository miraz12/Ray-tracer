//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_BASE_H
#define RAY_TRACER_BASE_H


class Triangle;

struct Vertex
{
    float x{0}, y{0}, z{0}, w{1};
};

struct Direction
{
    float x{0}, y{0}, z{0};
};

struct ColorDbl
{
    double r{0}, g{0},b{0};
};

struct Ray
{
    Vertex start;
    Vertex end;
    Triangle* hitTri;
    ColorDbl color;
};

#endif //RAY_TRACER_BASE_H
