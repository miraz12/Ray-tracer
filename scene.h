//
// Created by shaggy on 9/17/18.
//

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#define GLM_ENABLE_EXPERIMENTAL
#include "triangle.h"
#include "tetrahedron.h"
#include "sphere.h"
#include "lightsource.h"
#include "spherelightsource.h"

class Scene {
public:
    Scene();
    ~Scene();

    ///Go through all the objects in the scene and find closest intersection
    void FindInstersections(Ray* arg);
    ///Creates and shoots shadow rays with help of incoming ray (AreaLight)
    ColorDbl LaunchShadowRays(Ray* arg);
    ///Creates and shoots shadow rays with help of incoming ray (VolumeLight)
    ColorDbl LaunchShadowRaysSphere(Ray* arg);

private:
    Triangle scene[24];
    Vertex vertexlist[14];
    Vertex tetralist[4];
    std::vector<Tetrahedron> tetras;
    std::vector<Sphere> spheres;
    std::vector<LightSource> lights;
    std::vector<SphereLightSource> lightsSphere;

};


#endif //RAY_TRACER_SCENE_H
