//
// Created by shaggy on 9/17/18.
//

#include "scene.h"

Scene::Scene()
{
    //Floor
    //    0_____3
    //    /\   /\
    //  1/__\2/__\4
    //   \  / \  /
    //    \/___\/
    //    5     6
    vertexlist[0] = Vertex(0.0f, 6.0f, -5.0f);
    vertexlist[1] = Vertex(-3.0f, 0.0f, -5.0f);
    vertexlist[2] = Vertex(5.0f, 0.0f, -5.0f);
    vertexlist[3] = Vertex(10.0f, 6.0f, -5.0f);
    vertexlist[4] = Vertex(13.0f, 0.0f, -5.0f);
    vertexlist[5] = Vertex(0.0f, -6.0f, -5.0f);
    vertexlist[6] = Vertex(10.0f, -6.0f, -5.0f);

    //Roof
    //    7_____10
    //    /\   /\
    //  8/__\9/__\11
    //   \  / \  /
    //    \/___\/
    //    12    13
    vertexlist[7] = Vertex(0.0f, 6.0f, 5.0f);
    vertexlist[8] = Vertex(-3.0f, 0.0f, 5.0f);
    vertexlist[9] = Vertex(5.0f, 0.0f, 5.0f);
    vertexlist[10] = Vertex(10.0f, 6.0f, 5.0f);
    vertexlist[11] = Vertex(13.0f, 0.0f, 5.0f);
    vertexlist[12] = Vertex(0.0f, -6.0f, 5.0f);
    vertexlist[13] = Vertex(10.0f, -6.0f, 5.0f);



    //TODO: Init all triangles in scene
    //Floor---
    this->scene[0].SetTriangle(vertexlist[0], vertexlist[1], vertexlist[2]);
    this->scene[1].SetTriangle(vertexlist[0], vertexlist[2], vertexlist[3]);    
    this->scene[2].SetTriangle(vertexlist[2], vertexlist[3], vertexlist[4]);    
    this->scene[3].SetTriangle(vertexlist[1], vertexlist[2], vertexlist[5]);    
    this->scene[4].SetTriangle(vertexlist[3], vertexlist[5], vertexlist[6]);    
    this->scene[5].SetTriangle(vertexlist[2], vertexlist[4], vertexlist[6]);    
    //Roof---
    this->scene[6].SetTriangle(vertexlist[7], vertexlist[8], vertexlist[9]);
    this->scene[7].SetTriangle(vertexlist[7], vertexlist[9], vertexlist[10]);
    this->scene[8].SetTriangle(vertexlist[9], vertexlist[10], vertexlist[11]);
    this->scene[9].SetTriangle(vertexlist[8], vertexlist[9], vertexlist[12]);
    this->scene[10].SetTriangle(vertexlist[7], vertexlist[12], vertexlist[13]);
    this->scene[11].SetTriangle(vertexlist[9], vertexlist[11], vertexlist[13]);

    //Wall1
    //Wall2
    //Wall3
    //Wall4
    //Wall5
    //Wall6
}

Scene::~Scene() {}

void Scene::FindInstersections(Ray arg)
{
    for (int i = 0; i < 24; ++i)
    {
        scene[i].RayInstersection(arg);
    }
}