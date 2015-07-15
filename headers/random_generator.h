#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR

#include "general.h"
#include <random> //C++11

enum dist_names
{
	BINOMIAL,
	NORMAL,
	POISSON,
	STUDENT_T,
	WEIBULL,
	UNIFORM_INT,
	UNIFORM_REAL
};

dist_names randomGeneratorInstructions();

class RandomGenerator
{
	private:
		std::default_random_engine generator;
		uint N;
		dVec data;
		dist_names name;
		void chooseDistribution();
		void funiform_real();
		//dist_names stringToDistNames(dist_names);
		//dist_names stringToDistNames(str);
		//dVec Normal();
		//str name;
		//std::normal_distribution normal;
		//std::binomial_distribution binomial;
		//std::poisson_distribution poisson;
		//std::student_t_distribution student_t;
		//std::weibull_distribution weibull;
		//std::uniform_int_distribution uniform_int;
		//std::uniform_real_distribution uniform_real;
	public:
		RandomGenerator(dist_names);
		//RandomGenerator(str);
		~RandomGenerator();
		dVec getData();
};

#endif
