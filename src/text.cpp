#include "main.h"

/* main.cpp */
void starting()
{
	std::cout << "******************************" << std::endl;
	std::cout << "WELCOME TO STATISTICS BY DENIZ" << std::endl;
	std::cout << "******************************" << std::endl;
}

void terminating()
{
	std::cout << "The program is shutting down!" << std::endl;
	std::cout << "Thank you for using it!" << std::endl;
}

int instructions()
{
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "Options are:" << std::endl;
	std::cout << "1) Enter a number of data" << std::endl;
	std::cout << "2) Create a number of data" << std::endl;
	std::cout << "3) Shut down the program" << std::endl;
	int value;
	std::cin >> value;
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return -1;
	}
	else
		return value;
}
/* main.cpp */

/* data_group.cpp */
int GNUchoose()
{
	std::cout << "How would you like to use the plot?" << std::endl;
	std::cout << "Options are:" << std::endl;
	std::cout << "1) Manually" << std::endl;
	std::cout << "2) Automatically" << std::endl;
	std::cout << "3) Skip" << std::endl;
	int value;
	std::cin >> value;
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return -1;
	}
	else
		return value;
}
/* data_group.cpp */
