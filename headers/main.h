// Libraries
#include <iostream>
#include <limits>
#include <algorithm> //sort
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

// Type Definitions
typedef unsigned int uint;
typedef std::vector<double> dVec;
typedef std::vector<double>::iterator dVecIt;
typedef std::string str;

// Function protoypes
// main.cpp
void starting();
void terminating();
int instructions();
// data_group.cpp
int GNUchoose();
// plotGNU.cpp
void plotGNU();
void manual();
void automatic();
// random_generator.cpp 
dVec generateRandoms( uint, double , double);

// Class for statistical calculations; should be inherited
class StatisticalMethods
{
	protected:
		void sortData(dVec *);
		double calculateSum(dVec);
		double calculateMean(uint , double );
		double calculateMedian(uint , dVec);
		double calculateVariance(uint , dVec, double);
		double calculateSD(double);
};

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
};
