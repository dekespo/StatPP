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
	selectDistribution();
	//name = stringToDistNames(sname); 
}

RandomGenerator::~RandomGenerator(){}

void RandomGenerator::selectDistribution()
{
	switch(name)
	{
		case CHI_SQUARED:
		{
			fchi_squared();
			break;
		}
		case EXPONENTIAL:
		{
			fexponential();
			break;
		}
		case GAMMA:
		{
			fgamma();
			break;
		}
		case NORMAL:
		{
			fnormal();
			break;
		}
		case STUDENT_T:
		{
			fstudent_t();
			break;
		}
		case WEIBULL:
		{
			fweibull();
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

void RandomGenerator::fchi_squared()
{
	uint x;
	std::cout << "Enter x >= 0:";
	std::cin >> x; // Needs error check
	// Parameter Control will be added
	std::chi_squared_distribution<double> distribution(x);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));
}

void RandomGenerator::fexponential()
{
	uint x;
	std::cout << "Enter x > 0:";
	std::cin >> x; // Needs error check
	// Parameter Control will be added
	std::exponential_distribution<double> distribution(x);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));
}

void RandomGenerator::fgamma()
{
	double alfa,beta;
	std::cout << "Enter alfa:";
	std::cin >> alfa;
	std::cout << "Enter beta:";
	std::cin >> beta;
	std::gamma_distribution<double> distribution(alfa,beta);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));
}

void RandomGenerator::fnormal()
{
	double mean, std;
	std::cout << "Enter mean:";
	std::cin >> mean;
	std::cout << "Enter standard deviation:";
	std::cin >> std;
	std::normal_distribution<double> distribution(mean,std);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));

}

void RandomGenerator::fstudent_t()
{
	int x;
	std::cout << "Enter x > 0:";
	std::cin >> x; // Needs error check?
	// Parameter Control will be added
	std::student_t_distribution<double> distribution(x);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));
}

void RandomGenerator::funiform_real()
{
	double a,b;
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	std::uniform_real_distribution<double> distribution(a,b);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));
}

void RandomGenerator::fweibull()
{
	double a,b;
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	std::weibull_distribution<double> distribution(a,b);
	
	for(uint i = 0; i < N; i++)
		data.push_back(distribution(generator));

}

//dist_names RandomGenerator::stringToDistNames(str sname)
//{
//	if(sname.compare("uniform_real") == 0)
//		return UNIFORM_REAL;
//}

dVec RandomGenerator::getData(){ return data; }

uint RandomGenerator::getN(){ return N; }

dist_names randomGeneratorInstructions()
{

	while(true)
	{
		std::cout << "Which distriubtion would you like to use?" << std::endl;
		std::cout << "Options are:" << std::endl;
		std::cout << "1) Chi-squared distribution" << std::endl;
		std::cout << "2) Exponential distribution" << std::endl;
		std::cout << "3) Gamma distribution" << std::endl;
		std::cout << "4) Normal distribution" << std::endl;
		std::cout << "5) Student's t distribution" << std::endl;
		std::cout << "6) Uniform distribution" << std::endl;
		std::cout << "7) Weibull distribution" << std::endl;
		std::cout << "8) Cancel" << std::endl;

		uint value;
		std::cin >> value;
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		else
		{
			if(value > 0 && value < 8)
				return numberToNames(value);
			else if(value == 8)
				break;
			else
				std::cout << "Wrong number is entered, please try again." << std::endl;
		}

	}
}

dist_names numberToNames(uint value)
{
	dist_names chosen;
	switch(value)
	{
		case 1: { chosen = CHI_SQUARED; break;}
		case 2: { chosen = EXPONENTIAL; break;}
		case 3: { chosen = GAMMA; break;}
		case 4: { chosen = NORMAL; break;}
		case 5: { chosen = STUDENT_T; break;}
		case 6: { chosen = UNIFORM_REAL; break;}
		case 7: { chosen = WEIBULL; break;}
		//default:
	}
	return chosen;
}
