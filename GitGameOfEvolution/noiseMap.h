#pragma once

#include <iostream>
#include <vector>
#include "OpenSimplex2S.hpp"

class NoiseMap
{
public:
	static std::vector<std::vector<float>> createNoiseMap(std::vector<std::vector<float>>);
};

