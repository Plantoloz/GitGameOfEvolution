#pragma once

#include <iostream>
#include <vector>
#include "OpenSimplexNoise.h"

class NoiseMap
{
public:
	static std::vector<std::vector<float>> createNoiseMap(std::vector<std::vector<float>>);
};

