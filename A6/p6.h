
/***************************************************************
CSCI 689         Program 6     Fall 2015

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Tuesday, October 13, 2015

Purpose: This function simulates ATOM
        
***************************************************************/


#include"/home/cs689/common/689.h"
extern const int GRID_SIZE;        // assign value to constant
extern const int SEED;   // set seed value
extern const int LOW;               // set low value
extern const int HIGH;             //set high value
extern const int MIN_CYCLES;        //set min cycles as 1
extern const int MAX_CYCLES;  


void init_sim ( vector<vector<bool>>& traps, vector<int>& ballCycles);            //function is used to initialize values for simulation

unsigned release_balls (vector<vector<bool>>& traps, vector<int>& ballCycles);      //this function computes the number of balls in air at given instant

void print_grid ( const vector<vector<bool>>& traps, const unsigned& clock, const unsigned& noBallsInAir ); //this function displays the grid 


void print_stat ( const vector<vector<bool>>& traps, const unsigned& maxNoBallsInAir, const unsigned& clock );      // this function displays the final statistics of the simulation




