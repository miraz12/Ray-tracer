//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_TRIANGLE_H
#define RAY_TRACER_TRIANGLE_H

#include <vector>
#include "base.h"
#include "material.h"

class Triangle {
public:
    Triangle();
    Triangle(Vertex v1, Vertex v2, Vertex v3);
    ~Triangle();

    bool RayInstersection(Ray* arg);
    void SetTriangle(Vertex v1, Vertex v2, Vertex v3);
    void SetTriangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c);
    void SetTriangle(Vertex v1, Vertex v2, Vertex v3, Material m);
    void SetColor(float r, float g, float b);
    glm::vec3 GetNormal();
    Material material;

private:
    Vertex tri[3];
    ColorDbl color;
    Direction Normal;
};


#endif //RAY_TRACER_TRIANGLE_H
