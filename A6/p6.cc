/***************************************************************
CSCI 689         Program 6     Fall 2015

Programmer: SHOAIB MOMIN

Section: 2

Date Due: Tuesday, October 13, 2015

Purpose: To simulate ATOM
         
***************************************************************/





#include"p6.h"

//#include"/home/cs689/common/689.h"
extern const int GRID_SIZE=25;        // assign value to constant
extern const int SEED=(int)time(0);   // set seed value
extern const int LOW=0;               // set low value
extern const int HIGH=25;             //set high value
extern const int MIN_CYCLES=1;        //set min cycles as 1
extern const int MAX_CYCLES=4;          //set max cycles to 4
//std::clock_t start;
//int end=-1;
unsigned start;              // start is used to indicate start time of simulation
//int end=-1;

/****************************************************************

   FUNCTION:   int randomInteger(int low, int high);

   ARGUMENTS:  low, high

   RETURNS:    the function returns a random integer between the range of low and high

   ****************************************************************/
int randomInteger(int low, int high) { 
//initRandomSeed();
double d = rand() / (double(RAND_MAX) + 1);           // get a random number-double type
double s = d * (double(high) - low + 1);          // set into the required range of low and high
return int(floor(low + s));                   //convert it to integer type
}



/*
void init_sim ( vector<vector<bool>>& traps, vector<int>& ballCycles);

unsigned release_balls (vector<vector<bool>>& traps, vector<int>& ballCycles);

void print_grid ( const vector<vector<bool>>& traps, const unsigned& clock, const unsigned& noBallsInAir );


void print_stat ( const vector<vector<bool>>& traps, const unsigned& maxNoBallsInAir, const unsigned& clock );
*/


int main()
{

unsigned maxNoBallsInAir=0;                   // strores the value of max number of balls in air
vector <vector<bool>> traps(GRID_SIZE,vector <bool>(GRID_SIZE));   // a 2d vector to store the traps in the form of square
//vector<unsigned>ballCycles;
unsigned noBallsInAir=1;                        //stores the number of balls in air
int totalballs=GRID_SIZE*GRID_SIZE*2+1;         //the total balls in air is calculated
vector<int>ballCycles(totalballs);              // vector to store the ball cycles
//std::clock_t clock;
unsigned clock=0;                             // initialize clock to 0

init_sim(traps,ballCycles);                    //call the intialization function
print_grid(traps,clock,noBallsInAir);        // this function displays the grid
start =clock;                                 //initialize the start to clock
while(noBallsInAir>0)                         // the simulation runs as long as there are balls in the air
{
// start=clock;
//start = std::clock();
//clock=std::clock();
clock++;                                     //increment clock
noBallsInAir=release_balls(traps,ballCycles);  // get the number of balls in air at a particular instant
//cout<<"In main "<<noBallsInAir<<endl;

if(maxNoBallsInAir<noBallsInAir)               //check for the max number of balls in air condition
maxNoBallsInAir=noBallsInAir;  
print_grid(traps,clock,noBallsInAir);           // display the traps grid

//if(clock==30) break;

}
//cout<<endl<<"After while";
//end=clock;
print_grid(traps,clock,noBallsInAir);             // once the simulation ends, display the grid at the end of simulation
print_stat(traps,maxNoBallsInAir,clock);       // display the final statistics of the simulation
return 0;
}


/****************************************************************

   FUNCTION:   void init_sim(vector<vector<bool>>&traps, vector<int>&ballCycles);

   ARGUMENTS:  traps, ballCycles- both vectors

   RETURNS:    This function performs the initializations required for the simulation


   ****************************************************************/


void init_sim(vector<vector<bool>> & traps,vector <int>&ballCycles)
{
for(int i=0;i<GRID_SIZE;i++)
{
for(int j=0;j<GRID_SIZE;j++)                // initially, all the traps are assigned with balls- hence no trap is sprung
{
traps[i][j]=true;
}
}
srand(SEED);                             // srand is set with the value if seed 
for(unsigned i=0;i<ballCycles.size();i++)  //  the ballCycles vector is initialized with -1
ballCycles[i]=-1;
ballCycles[0]=1;                          // the number of cycles for the first ball is set to 1
}





/****************************************************************

   FUNCTION:  unsigned release_balls(vector<vector<bool>>& traps,vector <int>&ballCycles);

   ARGUMENTS: traps, ballCycles- both vectors

   RETURNS:    the function returns the number of balls in air at a particular instant

   ****************************************************************/

unsigned release_balls(vector<vector<bool>>& traps,vector <int>&ballCycles)
{
//int index=1;
unsigned bia=0;                                           // number of balls in air is initialized to 0
/*for(unsigned l=0;l<ballCycles.size();l++)
{
if(ballCycles[l]>0)
bia++;
}
*/
for(unsigned k=0;k<ballCycles.size();k++) {             // ballCycles vector is traversed   
if(ballCycles[k]>1 )                                     // if the ballCycles value is greater than 1, 
{ bia++;                                           //balls in air is incremented
 ballCycles[k]--;                                 //the cycle value is reduced
}
 else if(ballCycles[k]==1)                        // if the ballcycle value is 1
{
ballCycles[k]--;                                  // the cycle is reduced by 1
//bia--;
int i=randomInteger(LOW,HIGH-1);               // generate a random trap position by calculating i and j values
int j=randomInteger(LOW,HIGH-1);
//cout<<endl<<"i value is"<<i;
//cout<<endl<<"j value is"<<j;
int mousetrap=25*i+j+1;                         // the position of the mouse trap is determined
//cout<<mousetrap<<endl;
if(traps[i][j]==true)                        // if the trap has not yet sprung
{
//cout<<"in this";
ballCycles[mousetrap*2]=rand()%(MAX_CYCLES-MIN_CYCLES+1)+MIN_CYCLES;     // spring two balls and assign random cycles to them

ballCycles[mousetrap*2-1]=rand()%(MAX_CYCLES-MIN_CYCLES +1)+MIN_CYCLES;
//index+=2;
//cout<<ballCycles[mousetrap*2]<<endl;
//ballCycles.pushback();


traps[i][j]=false;                  // indicate that the trap has sprung
}

}
//if(ballCycles[k]<0)
//cout<<"negative number"<<endl;
}
return bia;                           // return balls in air
}


/****************************************************************

   FUNCTION: void print_grid(const vector<vector<bool>>& traps,const unsigned& clock,const unsigned& noBallsInAir);

   ARGUMENTS: traps, ballCycles- both vectors, clock value and number of balls in air

   RETURNS:   Nothing

   ****************************************************************/


void print_grid(const vector<vector<bool>>& traps,const unsigned& clock,const unsigned& noBallsInAir)
{
int i,j;
cout<<"Clock"<<clock<<endl;                       //Display the clock value
cout<<"Balls in Air"<<noBallsInAir<<endl;         // display balls in air
if(clock%10==0 || noBallsInAir==0)               //print the grid when clock value is a multiple of 10 or at the end of simulation
{
for( i=0;i<GRID_SIZE;i++)
{
cout<<endl;
for( j=0;j<GRID_SIZE;j++)
{
if(traps[i][j]==true) cout<<"x";                    // if the trap has not sprung, inidicate using 'x'
else cout<<".";                                     // or indicate with a '.'
}
}
}
}

/****************************************************************

   FUNCTION:void print_stat(const vector<vector<bool>>& traps, const unsigned &maxNoBallsInAir, const unsigned&clock);

   ARGUMENTS: traps, ballCycles- both vectors, clock value and maxium number of balls in air

   RETURNS:   Nothing

   ****************************************************************/




void print_stat(const vector<vector<bool>>& traps, const unsigned &maxNoBallsInAir, const unsigned&clock)
{
int i,j;
double count=0;                                               //count determines the number of traps sprung
//double duration=( std::clock() - start ) / (double) CLOCKS_PER_SEC;
int duration=clock-start;                                                    //duration of simulation is determined
cout<<endl<<"The total simulation time is "<<duration<<endl;  //check for duration
cout<<"Max no of balls in air "<<maxNoBallsInAir<<endl;            // Display max number of balls in air during the simulation
for(i=0;i<GRID_SIZE;i++)          
{
for(j=0;j<GRID_SIZE;j++)
{                                                     // count the number of traps sprung 
if(traps[i][j]==false)
count++;
}
}
cout<<endl<<"the number of traps sprun"<<count<<endl;            // display the number of traps sprung
double per=count/(GRID_SIZE*GRID_SIZE)*100;                // calculate the percentage of traps sprung
cout<<"Percentage of traps sprung "<<per;               // display the percentage of traps sprung
}

