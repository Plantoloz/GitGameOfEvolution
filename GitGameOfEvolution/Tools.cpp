#include <math.h>
#include <stdlib.h>

#include <iostream>

class CCalculator {
public:
	float getPi(int versuche) {
		srand((unsigned)time(NULL)); // Makes rand() Random
		int red = 0;
		for (int i =  0; i < versuche; i++)
		{
			float x = (float)rand() / RAND_MAX;
			float y = (float)rand() / RAND_MAX;
			if (pow(pow(y, 2) + pow(x, 2),0.5) <= 1) {
				red++;
				
			}
		}
		return (float(red)/ float(versuche) * 4);
	}
};

	
