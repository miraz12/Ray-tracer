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
    double Area();
    ///Get random point on triangle
    glm::vec3 GetPointOnTri();
    ///Return local coordinates to world coordinates
    glm::vec3 FromBarycentric(glm::vec3 point);
    Direction Normal;
    Material material;

private:
    Vertex tri[3];

};


#endif //RAY_TRACER_TRIANGLE_H
