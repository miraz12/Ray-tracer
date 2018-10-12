//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#include "triangle.h"
#include "tetrahedron.h"
#include "sphere.h"
#include "lightsource.h"

class Scene {
public:
    Scene();
    ~Scene();
    void FindInstersections(Ray* arg);
    ColorDbl LaunchShadowRays(Ray* arg);

private:
    Triangle scene[24];
    Vertex vertexlist[14];
    std::vector<Tetrahedron> tetras;
    std::vector<Sphere> spheres;
    std::vector<LightSource> lights;


    //Tetra test
    Vertex tetralist[4];

};


#endif //RAY_TRACER_SCENE_H
