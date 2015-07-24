#include <data_group.h>

DataGroup::DataGroup(uint n, dVec d)
{
	size = n;
	data = d;
	sum = calculateSum(data);
	mean = calculateMean(size, sum);
	median = calculateMedian(size, data);
	variance = calculateVariance(size, data, mean);
	sd = calculateSD(variance);
}

DataGroup::DataGroup(uint n, dVec d1, dVec d2)
{
	size = n;
	data1 = d1;
	data2 = d2;
}

DataGroup::~DataGroup()
{}

void DataGroup::showData()
{
	if( size <= 10)
	{
		std::cout << "The data are: [";
		for(uint i = 0; i < size - 1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size - 1] << "]" << std::endl;
	}
	else
	{
		std::cout << "The data are: [";
		for(uint i = 0; i < 5; i++)
			std::cout << data[i] << ", ";
		std::cout << " ... , "; 
		for(uint i = size - 5; i < size -1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size - 1] << "]" << std::endl;
	}
	std::cout << "The sum of data = " << sum << std::endl;
	std::cout << "The mean of data = " << mean << std::endl;
	std::cout << "The median of data = " << median << std::endl;
	std::cout << "The variance of data = " << variance << std::endl;
	std::cout << "The standard deviation of data = " << sd << std::endl;
}

void DataGroup::saveData()
{
	std::fstream dataFile("data.dat",std::fstream::in | std::fstream::out | std::fstream::trunc); 
	for(uint i = 0; i < size; i++)
	{
		dataFile << i << " " << data[i] << std::endl;
	}
	dataFile.close();
}

void DataGroup::deleteData()
{
	if( remove("data.dat") != 0)
		perror("Error deleting file");
}

void DataGroup::plotData()
{
	saveData();

	plotGNU();

	deleteData();
}

void DataGroup::plot2D()
{
	Gnuplot gp;
	//gp << "set terminal dumb" << std::endl; // If there is no GUI
	gp << "plot" << gp.file1d(std::make_pair(data1, data2)) << std::endl;
	//gp << "plot \"data.dat\" u 1:2" << std::endl;
	gp << "set title \"data.dat\"" << std::endl;
	gp << "set xlabel \"x\"" << std::endl;
	gp << "set ylabel \"y\"" << std::endl;
	gp << "set grid" << std::endl;
	gp << "replot" << std::endl;
	gp << "exit" << std::endl;
}

void DataGroup::saveDataSQL() {	SQLite();}

void DataGroup::sortData() { StatisticalMethods::sortData(data);}
