#include "main.h"
#include <cstdio>
#include <fstream>

DataGroup::DataGroup(uint n, dVec d)
{
	size = n;
	data = d;
	sortData(&data);
	sum = calculateSum(data);
	mean = calculateMean(size, sum);
	median = calculateMedian(size, data);
	variance = calculateVariance(size, data, mean);
	sd = calculateSD(variance);
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
		dataFile << i << " " << data[i] << std::endl;
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
