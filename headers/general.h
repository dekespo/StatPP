#ifndef GENERAL_H
#define GENERAL_H

// "General" Libraries
#include <iostream>
#include <limits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility> //pair

// Type Definitions
typedef unsigned int uint;
//template<typename T>
//using dVec = std::vector<T>;
typedef std::vector<double> dVec;
typedef std::pair<dVec, dVec> dVec2D;
typedef std::string str;

// Function protoypes

// text.cpp
void starting();
void terminating();
int instructions();
int GNUchoose();

// plotGNU.cpp
void plotGNU();
void manual();
void automatic();

// SQLite.cpp 
void SQLite();
int callback(void *, int, char **, char **);

//pair_up.cpp
dVec2D pairUp(dVec, dVec);
void pairPlot(dVec2D);

//case_functions.cpp
void manualDataAdd();
void randomGeneratorAdd();
void SQLiteAdd();
void testingAdd();

#endif
