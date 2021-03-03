

#include <cstdlib>
#include <time.h>



class Random
{
public:
	static void randInit()
	{
		srand((unsigned)time(NULL));
	}
	static float random()
	{
		return (float)rand() / RAND_MAX;
	}

	static float random_in(float min, float max)
	{
		
		return random() * (max - min) + min;
	}
};


