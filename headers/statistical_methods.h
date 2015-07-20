#ifndef STATISTICAL_METHODS_H
#define STATISTICAL_METHODS_H

#include "general.h"
#include <algorithm> //sort

// Class for statistical calculations; should be inherited
class StatisticalMethods
{
	protected:
		void sortData(dVec &);
		double calculateSum(dVec);
		double calculateMean(uint , double );
		double calculateMedian(uint , dVec);
		double calculateVariance(uint , dVec, double);
		double calculateSD(double);
};

#endif

