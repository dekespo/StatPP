#include "general.h" 
#include "statistical_methods.h"
#include "data_group.h"
#include "random_generator.h"

// Case 1
void manualDataAdd()
{
	std::cout << "Enter a non-numeric value to finish" << std::endl;

	bool dataCheck = true;
	uint i = 0;
	dVec data;
	while(dataCheck)
	{
		std::cout << "Please enter the data " << i+1 << " = ";
		double x;
		std::cin >> x;
		if (!std::cin)
		{
		//std::cout << "You entered a non-numeric value, are you sure you want to finish data?(y or n)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			dataCheck = false;
			continue;
		}
		data.push_back(x);
		i++;
	}

	uint n = data.size();
	DataGroup obj(n, data);

	obj.showData();
}

// Case 2
void randomGeneratorAdd()
{
	dist_names name = randomGeneratorInstructions();
	if(name != CANCEL)
	{
		RandomGenerator obj(name);
		dVec data = obj.getData();
		uint n = obj.getN();

		DataGroup obj2(n, data);

		obj2.plotData(); // Plot with gnuplot
	}
}

// Case 3
void SQLiteAdd()
{
	// It has useless line, need to revise
	uint n = 5; // Default
	dVec data;
	for(uint i = 0; i < n; i++)
		data.push_back(i);
	DataGroup obj(n, data);

	obj.saveDataSQL(); // Fixation is needed
}

// Case 4 is defined as exit

// Case 9 (NOT REAL, TESTING CASE)
void testingAdd()
{
	dist_names name = randomGeneratorInstructions();
	RandomGenerator obj(name);
	dVec data1 = obj.getData();
	uint n1 = obj.getN();

	//DataGroup x(n1, data1);

	dist_names name2 = randomGeneratorInstructions();
	RandomGenerator obj2(name2);
	dVec data2 = obj2.getData();
	uint n2 = obj2.getN();

	if(n1 == n2)
	{
		dVec2D data2D = pairUp(data1, data2);
		pairPlot(n1, data2D);
	}
	else
		std::cout << "n1 is not equal to n2!";
}
