//
// Created by Anton on 2018-10-12.
//

#ifndef RAY_TRACER_RANDOM_H
#define RAY_TRACER_RANDOM_H

#include <random>

class Random
{
public:
    Random();
    double GetRandomDouble(double min, double max);
    float GetRandomFloat(float min, float max);
    int GetRandomInt(int min, int max);

private:
    std::default_random_engine generator;
};


#endif //RAY_TRACER_RANDOM_H
