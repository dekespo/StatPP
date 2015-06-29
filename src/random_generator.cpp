#include "main.h"

/* main.cpp */
dVec generateRandoms(uint N, double x1, double x2)
{
	dVec data;
	
	for(uint i = 0; i < N; i++)
		data.push_back( (double)rand() / RAND_MAX * (x2 - x1) + x1 );

	return data;
}
/* main.cpp */
