//
// Created by shaggy on 9/17/18.
//

#include "scene.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.inl>
#include <glm/ext/scalar_constants.inl>
#include <corecrt_math_defines.h>

Scene::Scene()
{
    /*
     *Order of vertices in triangles in meshes dont matter 
     *for normals as we do checks for that when needed
    */
    vertexlist[0] = Vertex(0.0f, 6.0f, -5.0f);
    vertexlist[1] = Vertex(-3.0f, 0.0f, -5.0f);
    vertexlist[2] = Vertex(5.0f, 0.0f, -5.0f);
    vertexlist[3] = Vertex(10.0f, 6.0f, -5.0f);
    vertexlist[4] = Vertex(13.0f, 0.0f, -5.0f);
    vertexlist[5] = Vertex(0.0f, -6.0f, -5.0f);
    vertexlist[6] = Vertex(10.0f, -6.0f, -5.0f);

    vertexlist[7] = Vertex(0.0f, 6.0f, 5.0f);
    vertexlist[8] = Vertex(-3.0f, 0.0f, 5.0f);
    vertexlist[9] = Vertex(5.0f, 0.0f, 5.0f);
    vertexlist[10] = Vertex(10.0f, 6.0f, 5.0f);
    vertexlist[11] = Vertex(13.0f, 0.0f, 5.0f);
    vertexlist[12] = Vertex(0.0f, -6.0f, 5.0f);
    vertexlist[13] = Vertex(10.0f, -6.0f, 5.0f);

    ColorDbl red(1.f, 0, 0);
    ColorDbl blue(0, 0, 1.f);
    ColorDbl white(1., 1.f, 1.f);
    ColorDbl yellow(1., 1., 0.);
    ColorDbl green(0, 1.0f, 0);

    //Floor
    //    0_____3
    //    /\   /\
    //  1/__\2/__\4
    //   \  / \  /
    //    \/___\/
    //    5     6
    this->scene[0].SetTriangle(vertexlist[0], vertexlist[1], vertexlist[2], red);
    this->scene[1].SetTriangle(vertexlist[0], vertexlist[2], vertexlist[3], red);
    this->scene[2].SetTriangle(vertexlist[3], vertexlist[2], vertexlist[4], red);
    this->scene[3].SetTriangle(vertexlist[1], vertexlist[5], vertexlist[2], red);
    this->scene[4].SetTriangle(vertexlist[2], vertexlist[5], vertexlist[6], red);
    this->scene[5].SetTriangle(vertexlist[2], vertexlist[6], vertexlist[4], red);

    //Roof
    //    7_____10
    //    /\   /\
    //  8/__\9/_.\11
    //   \  / \  /
    //    \/___\/
    //    12    13
    LightSource light;
    this->scene[6].SetTriangle(vertexlist[9], vertexlist[8], vertexlist[7], green);
    //Light--
    //light.SetLight(vertexlist[7], vertexlist[9], vertexlist[10], white); //Area light
    //lights.push_back(light);
    this->scene[7].SetTriangle(vertexlist[7], vertexlist[9], vertexlist[10], green); 
    //-------
    this->scene[8].SetTriangle(vertexlist[11], vertexlist[9], vertexlist[10], green);
    this->scene[9].SetTriangle(vertexlist[9], vertexlist[12], vertexlist[8], green);
    this->scene[10].SetTriangle(vertexlist[13], vertexlist[12], vertexlist[9], green);
    this->scene[11].SetTriangle(vertexlist[11], vertexlist[13], vertexlist[9], green);

    //Wall1
    // 8____7_______10___11
    // |\   |\      |\   |
    // | \  |  \    | \  |
    // |  \ |    \  |  \ |
    // |___\|______\|___\|
    // 1    0       3    4

    this->scene[12].SetTriangle(vertexlist[8], vertexlist[1], vertexlist[0], blue);
    this->scene[13].SetTriangle(vertexlist[8], vertexlist[0], vertexlist[7], blue);
    this->scene[14].SetTriangle(vertexlist[7], vertexlist[0], vertexlist[3], blue);
    this->scene[15].SetTriangle(vertexlist[7], vertexlist[3], vertexlist[10], blue);
    this->scene[16].SetTriangle(vertexlist[10], vertexlist[3], vertexlist[4], blue);
    this->scene[17].SetTriangle(vertexlist[10], vertexlist[4], vertexlist[11], blue);


    //Wall2
    // 8____12______13___11
    // |\   |\      |\   |
    // | \  |  \    | \  |
    // |  \ |    \  |  \ |
    // |___\|______\|___\|
    // 1    5       6    4
    this->scene[18].SetTriangle(vertexlist[5], vertexlist[1], vertexlist[8], white);
    this->scene[19].SetTriangle(vertexlist[12], vertexlist[5], vertexlist[8], white);
    this->scene[20].SetTriangle(vertexlist[6], vertexlist[5], vertexlist[12], white);
    this->scene[21].SetTriangle(vertexlist[13], vertexlist[6], vertexlist[12], white);
    this->scene[22].SetTriangle(vertexlist[4], vertexlist[6], vertexlist[13], white);
    this->scene[23].SetTriangle(vertexlist[11], vertexlist[4], vertexlist[13], white);


    //Tetra
    //        4
    //       /|\
    //      / | \
    //     /  |  \
    //    /   |   \
    //  1/____|2___\3

    tetralist[0] = Vertex(4, -1, 0);
    tetralist[1] = Vertex(4, 0, 0);
    tetralist[2] = Vertex(3, 1, 0);
    tetralist[3] = Vertex(5, 0, 1);

    ColorDbl pink(1, 0, 1);
    Tetrahedron t(tetralist[3], tetralist[2], tetralist[1], tetralist[0], pink);
    //tetras.push_back(t);

    Material matSphere1(ColorDbl(1, 1., 1.), 0.799, diffuse);
    Material matSphere2(ColorDbl(1, 1., 1.), 0.799, lambertian);
    //Material matSphere2(ColorDbl(1, 1., 1.), 0.799, specular);
    Triangle* infoTri1 = new Triangle();
    Triangle* infoTri2 = new Triangle();
    Vertex tv(0.0, 0.0, 0.0, 1);
    infoTri1->SetTriangle(tv, tv, tv, matSphere1);
    infoTri2->SetTriangle(tv, tv, tv, matSphere2);
    Sphere s(glm::vec4(6.f, 2.f, -2.5f, 1), 1, infoTri1);
    Sphere s2(glm::vec4(6.f, -2.f, -2.5f, 1), 1, infoTri2);
    spheres.push_back(s);
    spheres.push_back(s2);

    //Material matLight(ColorDbl(1., 1., 1.), 1.5, ReflectionType::light);
    //Triangle* infoTriLight = new Triangle();
    //infoTri->SetTriangle(tv, tv, tv, matLight);
    //Sphere ls(glm::vec4(5, 0, 3, 1), 0.5, infoTriLight);

    SphereLightSource ls(glm::vec4(2, 0, 1, 3), 0.2);
    lightsSphere.push_back(ls);
    //SphereLightSource ls2(glm::vec4(-1.f, 1.f, 1.f, 1), 0.51);
    //ls2.color = white;
    //lightsSphere.push_back(ls2);

}

Scene::~Scene() {}

void Scene::FindInstersections(Ray* arg)
{
    for (int i = 0; i < 24; ++i)
    {
        scene[i].RayInstersection(arg);
    }
    for (int i = 0; i < lights.size(); ++i)
    {
        lights[i].RayIntersection(arg);
    }
    for (int i = 0; i < tetras.size(); ++i)
    {
        tetras[i].RayIntersection(arg);
    }
    for (int i = 0; i < lightsSphere.size(); ++i)
    {
        lightsSphere[i].RayIntersection(arg);
    }
    for (int i = 0; i < spheres.size(); ++i)
    {
        spheres[i].RayIntersection(arg);
    }

}

ColorDbl Scene::LaunchShadowRays(Ray* arg)
{
    ColorDbl lightContri;
    float area = 0.0f;
    Ray* shadowRay = new Ray();
    for (int i = 0; i < lights.size(); ++i)
    {
        //Lecture 3
            area += lights[i].triangles[0].Area();
            shadowRay->start.vertex = arg->end.vertex;
            shadowRay->dir.dir = glm::normalize(glm::vec4(lights[i].triangles[0].GetPointOnTri(), 1) - shadowRay->start.vertex);
            shadowRay->end.vertex = shadowRay->start.vertex + 100.f * glm::vec4(shadowRay->dir.dir, 0);

            FindInstersections(shadowRay);
            if (shadowRay->hitTri->material.GetType() != light) //Check if point is blocked by any objects
            {
                continue;
            }
            //Geometric term
            float alpha = glm::dot(arg->hitTri->Normal.dir, shadowRay->dir.dir);
            float b = glm::dot(lights[i].triangles[0].Normal.dir, -shadowRay->dir.dir);
            float beta = glm::clamp(b, 0.0f, 1.0f);

            float dist = glm::distance2(shadowRay->start.vertex, shadowRay->end.vertex);
            float geometric = alpha * beta / dist;

            float wi = glm::dot(shadowRay->dir.dir, shadowRay->hitTri->Normal.dir);

            lightContri.color += lights[i].GetEmission() * geometric;

    }

    delete(shadowRay);
    lightContri.color *= area;
    return lightContri;
}

ColorDbl Scene::LaunchShadowRaysSphere(Ray* arg)
{
    ColorDbl color; 
    for (int i = 0; i < lightsSphere.size(); ++i)
    {
        Ray* shadowRay = new Ray();
        glm::vec3 lightPos = lightsSphere[i].GetPointOnSphere();
        glm::vec3 lightDirection = glm::normalize(lightPos - glm::vec3(arg->end.vertex));
        arg->shadowRay.dir = lightDirection;
        shadowRay->start.vertex = arg->end.vertex;
        shadowRay->dir.dir = lightDirection;
        shadowRay->end.vertex = shadowRay->start.vertex + 100.f * glm::vec4(lightDirection, 0);
        FindInstersections(shadowRay);
        if (shadowRay->hitTri->material.GetType() == light)
        {
            double wi = glm::dot(lightDirection, arg->hitTri->Normal.dir);

            if (wi > 0)
            {
                double srad = lightsSphere[i].sphere.radius;
                double cos_a_max = sqrt(1 - srad * srad / glm::dot((arg->end.vertex - glm::vec4(lightPos, 1)), arg->end.vertex - glm::vec4(lightPos, 1)));
                double omega = 2 * M_PI * (1-cos_a_max);
                color.color += lightsSphere[i].GetColor().color * lightsSphere[i].GetEmission() * float(wi * omega * M_1_PI);
            }
        }
        delete shadowRay;
    }
    return color;
}
