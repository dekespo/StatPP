#include "general.h"
#include "gnuplot-iostream.h" // can be downloaded from www.stahlke.org/dan/gnuplot-iostream

// Here, gnuplot is used, there are automatic and manual part, in the
// part, one can just use it as gnuplot on terminal

/* data_group.cpp */
void plotGNU()
{
	switch(GNUchoose())
	{
		case 1:
		{
			manual();
			break;
		}
		case 2:
		{
			automatic();
			break;
		}
		case 3:
		{
			// DO NOTHING
			break;
		}
		default:
			std::cout << "You entered an invalid option" << std::endl;
	}
}
/* data_group.cpp */

// local
void manual()
{
	Gnuplot gp;
	str input = "";
	while(getline(std::cin, input))
	{
		std::cout << "Do not forget to replot " << std::endl;
		std::cout << "Enter gnuplot input: " << std::endl;
		if(input.compare("exit") == 0 || input.compare("quit"))
			break;
		gp << input << std::endl;
	}
}

// local
void automatic()
{
	Gnuplot gp;
	gp << "plot \"data.dat\" u 1:2" << std::endl;
	gp << "set title \"data.dat\"" << std::endl;
	gp << "set xlabel \"x\"" << std::endl;
	gp << "set ylabel \"y\"" << std::endl;
	gp << "set grid" << std::endl;
	gp << "replot" << std::endl;
	gp << "exit" << std::endl;
}
