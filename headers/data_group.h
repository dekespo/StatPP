#ifndef DATA_GROUP_H
#define DATA_GROUP_H

#include "general.h"
#include "statistical_methods.h"
#include <cstdio>
#include <fstream>

// Class for a dataset with inherietd statistical calculations
class DataGroup : protected StatisticalMethods
{
	private:
		void saveData();
		void deleteData();
	public:
		uint size; 
		dVec data;
		double sum;
		double mean;
		double median;
		double variance;
		double sd;
		DataGroup(uint, dVec); 
		~DataGroup(); 
		void showData();
		void plotData();
		void saveDataSQL();
};

#endif
