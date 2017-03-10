/***************************************************************
CSCI 689         Program 1     Fall 2015i

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Monday, August 31, 2015

Purpose: This program calculates and displays the value of pi.
         
***************************************************************/




#include<iostream>
#include<iomanip>
using namespace std;
double add_terms(unsigned n);
int main(){
int n;
double sum,pivalue;
cout<<"Enter the number of terms";
cin>>n;                          // take the number of terms from the user
sum= add_terms(n);           // call the add function which adds all the terms on rhs of the problem statement
pivalue=sum*4;    // get the final value of pi
cout<<"The value of pi is"<<pivalue<<"\n";
}
double add_terms(unsigned n){
double numerator=-1,denominator=-1,count=1;    
double intermediatesum=0,fraction;          //intermediatesum is the sum of all te fraction values after every iteration
while(count<n){
numerator=numerator*-1;
denominator=denominator+2;
fraction=numerator/denominator;                
intermediatesum=intermediatesum+fraction;
count++;
///cout<<"fraction" << fraction   <<"\n"<< "intermediatesum"<<intermediatesum<< "\n"<<" count" <<count;  // easier to debug the program
}
return intermediatesum;
}




