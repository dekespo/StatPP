#ifndef DATA_GROUP_H
#define DATA_GROUP_H

#include "general.h"
#include "statistical_methods.h"
#include <cstdio>
#include <fstream>
#include "gnuplot-iostream.h" // can be downloaded from www.stahlke.org/dan/gnuplot-iostream

// Class for a dataset with inherietd statistical calculations
class DataGroup : protected StatisticalMethods
{
	private:
		void saveData();
		void deleteData();
	public:
		uint size; 
		dVec data, data1, data2;
		double sum;
		double mean;
		double median;
		double variance;
		double sd;
		DataGroup(uint, dVec); 
		DataGroup(uint, dVec, dVec); 
		~DataGroup(); 
		void showData();
		void plotData();
		void saveDataSQL();
		void sortData();
		void plot2D();
};

#endif
