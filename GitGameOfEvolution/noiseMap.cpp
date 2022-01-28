#include "NoiseMap.h"

std::vector<std::vector<float>> NoiseMap::createNoiseMap(std::vector<std::vector<float>> world) {
	srand((unsigned int)time(NULL));
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));  

	
	for (size_t y = 0; y < world.size(); y++)
	{
		for (size_t x = 0; x < world[y].size(); x++)
		{
			std::cout << rand() / float(RAND_MAX) << std::endl;
			world[y][x] = rand() / float(RAND_MAX);
		}
	}
	return world;
}