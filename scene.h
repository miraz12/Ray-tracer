//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#include "triangle.h"

class Scene {
public:
    Scene();
    virtual ~Scene();
    void FindInstersections(Ray arg);

private:
    Triangle scene[24];
    Vertex vertexlist[7];
};


#endif //RAY_TRACER_SCENE_H
