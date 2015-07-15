#include "random_generator.h"
//#include "general.h"

/* main.cpp */
dVec generateRandoms(uint N, double x1, double x2)
{
	dVec data;
	
	for(uint i = 0; i < N; i++)
		data.push_back( (double)rand() / RAND_MAX * (x2 - x1) + x1 );

	return data;
}
/* main.cpp */

RandomGenerator::RandomGenerator(dist_names _name)
{
	std::cout << "Enter the number of data:";
	std::cin >> N;
	name = _name;
	chooseDistribution();
	//name = stringToDistNames(sname); 
}

RandomGenerator::~RandomGenerator(){}

void RandomGenerator::chooseDistribution()
{
	switch(name)
	{
		case BINOMIAL:
		{
			break;
		}
		case NORMAL:
		{
			break;
		}
		case POISSON:
		{
			break;
		}
		case STUDENT_T:
		{
			break;
		}
		case WEIBULL:
		{
			break;
		}
		case UNIFORM_INT:
		{
			break;
		}
		case UNIFORM_REAL:
		{
			funiform_real();
			break;
		}
		default:
			std::cout << "Wrong" << std::endl;
	}
}

void RandomGenerator::funiform_real()
{
	double a,b;
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	//std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(a,b);
	
	for(uint i = 0; i < N; i++)
	{
		double number = distribution(generator);
		//std::cout << "number added = " << number << std::endl;
		data.push_back(number);
	}
}

//dist_names RandomGenerator::stringToDistNames(str sname)
//{
//	if(sname.compare("uniform_real") == 0)
//		return UNIFORM_REAL;
//}

dVec RandomGenerator::getData()
{
	return data;
}

dist_names randomGeneratorInstructions()
{
	std::cout << "Which distriubtion would you like to use?" << std::endl;
	std::cout << "Options are:" << std::endl;
	std::cout << "1) Uniform distribution with real numbers" << std::endl;
	//std::cout << "2) Create a number of data" << std::endl;
	//std::cout << "3) SQLite Demo" << std::endl;
	//std::cout << "4) Shut down the program" << std::endl;
	int value;
	std::cin >> value;
	//if (!std::cin)
	//{
	//	std::cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	//	return -1;
	//}
	//else
	if(value == 1)
		return UNIFORM_REAL;
	else
		return UNIFORM_REAL;
}
