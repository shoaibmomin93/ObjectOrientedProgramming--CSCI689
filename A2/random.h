/*************************************************************
CSCI 689         Program 2     Fall 2015

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Tuesday, September 8, 2015

Purpose: This program calculates the value of pi using random number generation.
         Monte Carlo Simulation

// This header files has declarations of constant variables and prototypes of functions that are used in random.cc for the generation of random numbers.

***************************************************************/






#include"/home/cs689/common/689.h"
//using namespace std;
#ifndef _random_h           //   The purpose of the interface boilerplate is to prevent the compiler from reading thesame interface many times during a single compilation
#define _random_h

extern const int  SEED;               // This header files includes the declarations and prototypes of constant variables and functions.
void setRandSeed(int );   // this function is used to set the initial value in the process of random number generation
double randReal(double , double ); // This function calculates a random number and returns it to p2.cc
#endif
