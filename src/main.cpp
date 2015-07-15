#include "general.h" 
#include "statistical_methods.h"
#include "data_group.h"
#include "random_generator.h"

int main()
{
	// Write the initial text
	starting(); // text.cpp

	bool programRunCheck = true;

	srand(time(NULL));

	// Run the program until the user exits
	while(programRunCheck)
	{
		// Choose option
		int init = instructions(); //text.cpp
		uint n;
		dVec data;
		double x1, x2;

		switch(init)
		{
			case 1: // Manual Data adding
			{
				std::cout << "Enter a non-numeric value to finish" << std::endl;

				bool dataCheck = true;
				uint i = 0;
				while(dataCheck)
				{
					std::cout << "Please enter the data " << i+1 << " = ";
					std::cin >> x1;
					if (!std::cin)
					{
					//std::cout << "You entered a non-numeric value, are you sure you want to finish data?(y or n)" << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
						dataCheck = false;
						continue;
					}
					data.push_back(x1);
					i++;
				}

				n = data.size();
				DataGroup obj(n, data);

				obj.showData();
				break;
			}
			case 2: // Create data for a given range
			{
				std::cout << "It will need the number of data and range from x1 to x2:" << std::endl;
				std::cout << "Enter the number of data:";
				std::cin >> n;
				std::cout << "Enter x1:";
				std::cin >> x1;
				std::cout << "Enter x2:";
				std::cin >> x2;

				std::cout << "You entered: " << std::endl;
				std::cout << "data number: " << n << std::endl;
				std::cout << "x1: " << x1 << std::endl;
				std::cout << "x2: " << x2 << std::endl;
				std::cout << "Random numbers in range [" << x1 << "," << x2 << "] are being generating..." << std::endl;

				data = generateRandoms(n, x1, x2);

				DataGroup obj(n, data);

				obj.showData(); 

				obj.plotData(); // Plot with gnuplot
				break;
			}
			case 3: // SQLite Demo (will change in future)
			{
				n = 5; // Default
				for(uint i = 0; i < n; i++)
					data.push_back(i);
				DataGroup obj(n, data);

				obj.saveDataSQL(); // Fixation is needed
				break;
			}
			case 4: // Exit
			{
				programRunCheck = false;
				break;
			}
			case 5: // RandomGenerator
			{
				dist_names name = randomGeneratorInstructions();
				RandomGenerator obj(name);
				dVec data = obj.getData();

				std::cout << "TESTING RANDOM GENERATOR" << std::endl;
				for(dVecIt it = data.begin(); it != data.end(); it++)
					std::cout << *it << std::endl;

				break;
			}
			default: // False enter
				std::cout << "You entered an invalid option" << std::endl;
		}
	}	

	// Finisihing the program
	terminating(); //text.cpp 

	return 0; // Finish the program sucessfully
}
