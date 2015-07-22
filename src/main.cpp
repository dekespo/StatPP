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

				n = data.size();
				DataGroup obj(n, data);

				obj.showData();
				break;
			}
			case 2: // RandomGenerator
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
			// Exit
			case 4: { programRunCheck = false; break;}
			// False enter
			default: std::cout << "You entered an invalid option" << std::endl;
			case 5:
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
					//pairPlot(dVec2D);
					//data2D.plotData();
				}
				else
					std::cout << "n1 is not equal to n2!";
			}
		}
	}	

	// Finisihing the program
	terminating(); //text.cpp 

	return 0; // Finish the program sucessfully
}
