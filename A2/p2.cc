/***************************************************************
CSCI 689         Program 2     Fall 2015

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Tuesday, September 8, 2015

Purpose: This program calculates the value of pi using random number generation.
         Monte Carlo Simulation
***************************************************************/




#include"p2.h"            //The header files created are included in this source file.
#include"random.h"        

//using namespace std;
bool onTarget(double , double );  // This is the prototype of ontarget function which checks if the dart in in the circle or not.
extern const int LOW=-1;     // The externally declared variables are assigned are values. Since the radius of the circle is taken as 1, low and high values are -1 and +1 respectively.
extern const int HIGH=1;
extern const long N=100000;           // N represents the total number of darts thrown.
int main(){

//long nvalue;
double x,y,pi;   // x and y store the location of the dart when its thrown.
int count=0;     //count is used to count the number of darts that are inside the circle.
bool target;    //target stores the boolean result of ontarger function.

setRandSeed(SEED);  // this is used to set the initial value used in random number generation.

for(int iterations=0;iterations<N;iterations++) //This loop runs for 'n' times where n is the number of darts thrown.
{
x=randReal(LOW,HIGH);        // using the random number generation function, x and y  values are obtained.
y=randReal(LOW,HIGH);
target=onTarget(x,y);   // once the values are obtained, they are sent to  ontarget function which specifies if the point lies within the circle of radius 1.
if(target) count++; // if the point lies within the circle,increment count

//cout<<"The value of pi is"<<pi;
}
pi=((double)(4*count)/N);   // The value of pi is got by the ratio of number of darts that lie within the circle and the number of darts that are in the square.
cout<<"The value of pi is "<< pi<<endl;
return 0;
}
//bool onTarget(double x, double y)  
/*************************************************************************  
  // This function takes the (x,y) values and checks if the point lies within the circle of radius 1 or not. If yes, the function returns true value.
***********************************************************************/
bool onTarget(double x, double y)
{                                      // x is the x coordinate of the dart thrown and y is the y coordinate of the dart thrown.
if((x*x+y*y)<=1)  // If the (x,y) value of the dart is within the circle or radius 1, then true is returned.
return true;
else
return false; // If the (x,y) value is not within the circle, false is returned.
}



