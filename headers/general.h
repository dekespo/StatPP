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

// Type Definitions
typedef unsigned int uint;
//template<typename T>
//using dVec = std::vector<T>;
//using dVecIt = std::vector<T>::iterator;
typedef std::vector<double> dVec;
typedef std::vector<double>::iterator dVecIt;
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

#endif
