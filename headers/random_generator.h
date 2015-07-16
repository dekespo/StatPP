#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR

#include "general.h"
#include <random> //C++11

// Enumeration for distribution names (non-discrete)
enum dist_names
{
	CHI_SQUARED,
	EXPONENTIAL,
	GAMMA,
	NORMAL,
	STUDENT_T,
	UNIFORM_REAL,
	WEIBULL
};

// Function
dist_names randomGeneratorInstructions();
dist_names numberToNames(uint value);

// Class
class RandomGenerator
{
	private:
		std::default_random_engine generator;
		uint N;
		dVec data;
		dist_names name;
		void selectDistribution();
		void fchi_squared();
		void fexponential();
		void fgamma();
		void fnormal();
		void fstudent_t();
		void funiform_real();
		void fweibull();
	public:
		RandomGenerator(dist_names);
		//RandomGenerator(str);
		~RandomGenerator();
		dVec getData();
		uint getN();
};

#endif
