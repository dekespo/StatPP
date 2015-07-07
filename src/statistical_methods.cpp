#include "statistical_methods.h"

// Sort data
void StatisticalMethods::sortData(dVec *data)
{
	std::sort(data->begin(), data->end());
}

// Sum of data
double StatisticalMethods::calculateSum(dVec data)
{
	double sum = 0;
	for(dVecIt it = data.begin(); it != data.end(); ++it)
		sum += *it;
	return sum;
}

// Mean of data
double StatisticalMethods::calculateMean(uint N, double sum)
{
	return sum / N;
}

// Median of data
double StatisticalMethods::calculateMedian(uint N, dVec data)
{
	uint n = N * 0.5;
	if(N % 2 == 0)
		return (data.at(n-1) + data.at(n) ) * 0.5;
	else
		return data.at(n);
}

// Variance of data
double StatisticalMethods::calculateVariance(uint N, dVec data, double mean)
{
	dVec varData;
	double temp;
	for(dVecIt it = data.begin(); it != data.end(); ++it)
	{
		temp = (*it - mean) * (*it - mean);
		varData.push_back(temp);
	}
	double varSum = calculateSum(varData);
	return calculateMean(N, varSum);
}

// Standard Deviation of data
double StatisticalMethods::calculateSD(double variance)
{
	return sqrt(variance);
}
