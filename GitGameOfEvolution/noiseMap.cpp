#include "NoiseMap.h"

std::vector<std::vector<float>> NoiseMap::createNoiseMap(std::vector<std::vector<float>> world) {
	srand((unsigned int)time(NULL));
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));  
	long seed = rand();
	OpenSimplex2S noise(seed);
	for (size_t x = 0; x < world.size(); x++)
	{
		for (size_t y = 0; y < world[x].size(); y++)
		{
			// world[y][x] = rand() / float(RAND_MAX);
			
			double frequency = 5;
			
			double nx = (double)x / (double)world.size() * frequency;
			double ny = (double)y / (double)world[x].size() * frequency;
			double value = noise.noise2(nx, ny);
			world[x][y] = (value + 1 ) / 2; // Convert to float between 1 and 0
			/*
			
			std::cout << nx <<": "<< world[x][y] << std::endl;
			std::cout << ny << ": " << world[x][y] << std::endl;
			std::cout  << std::endl;
			*/
		}
	}
	std::cout << "Done";
	return world;
}