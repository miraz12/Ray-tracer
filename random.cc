//
// Created by Anton on 2018-10-12.
//

#include "random.h"

Random::Random()
{
}

double Random::GetRandomDouble(double min, double max)
{
    std::uniform_real_distribution<double> dist(min, max);
    return dist(generator);
}

float Random::GetRandomFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(generator);
}

int Random::GetRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}
