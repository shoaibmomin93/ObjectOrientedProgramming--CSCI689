/***************************************************************
CSCI 689         Program 2     Fall 2015

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Tuesday, September 8, 2015

Purpose: This program calculates the value of pi using random number generation.
         Monte Carlo Simulation

// This source file is used to generate the random numbers required in the calcu
lation of pi.

***************************************************************/






#include"random.h"             // include the header file that has the prototypes required.
//using namespace std;

extern const int SEED=(int) time(0);  // The constant is declared extern as it is declared in a different program. It is assigned the value time(0) as it gives the time in seconds since the Unix epoch, which is a pretty good unpredictable seed.  

//void setRandSeed(int seed)
/********************************************************************* 
  // This function calls srand(). srand gives the random function a new starting point. This is taken, calculatins are performed to generate the next seed.
***********************************************************************/
void setRandSeed(int seed)
{
srand(seed);
}
//double randReal(double low, double high) 
/*********************************************************************
// This function generates random numbers that are sent back to p2.cc
   where computations are performed.
*********************************************************************/
double randReal(double low, double high)
{
//int count=0;i
double limit=high-low;               // Since we need random numbers bewteen -1 and +1, we need to set the limit accordingly. 
double randno=low+((limit*rand())/(RAND_MAX + 1.0));    // this formula is used from one of the cpp forums: http://www.cplusplus.com/forum/general/14192/
return randno;
 
 
//count++;
}



