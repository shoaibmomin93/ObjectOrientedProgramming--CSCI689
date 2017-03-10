
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Main  header file

****************************************************************/

#include "prog12.h"
int Deck::check[HANDS] = {0};
int Deck::top = 0;
int main()
{
srand(time(NULL));                     // set seed value to time
int num_player,num_game,numOfHands;   // declare variables                      
int temp;
cout<<"Enter no. of players and number of games for each session and enter <ctrl>-D to terminate the simulation"<<endl;
bool f=false;
while((cin>>num_player))                      // accept number of players and games and run the loop till input is entered
{
//cout<<"in while";
cin>>num_game;

numOfHands = num_player*num_game;         // hands is players 8 games
for(int i=1;i<=num_game;i++)
{
//cout<<"in first for"<<endl;
if(num_game <= 10)
{
cout<<" Game "<<i<<" :"<<endl;           // as long as game continues
}
Deck deck;
deck.shuffle();      // create a deck and shuffle it
for(int j=1;j<=num_player;j++)	
{
//cout<<"in second for"<<endl;
Hand hand;
deck.deal(hand);
/*
if(hand.isStraightFlush())
{
straight_flush ++;
}
else if(hand.isFourOfKind())
{four_kind++		}
else if(hand.isFullHouse())
full_house ++;}
	
*/
if(num_game <= 10)	
{
for (int i=0;i<NUM_HANDS;i++)         // display the cards
{
//cout<<"in third for"<<endl;
cout<<i+1<<" : "<<ranks[hand.cardarr[i].getRank()];
cout<<" of "<<suits[hand.cardarr[i].getSuit()]<<endl;
}
f = true;
deck.set(hand, f);
cout<<endl;
}	
else	
{
//cout<<"in else part"<<endl;
f = false;
deck.set(hand, f);
}
//return 0;
}
}			

cout<<numOfHands<<" Hand"<<endl;          // display this using the helper array declared in header 
for(int i=0,j=7;i<8;i++,j--)
{
//cout<<"in for of display"<<endl;
if(Deck::check[i] > 0)		
cout<<Deck::check[i]<< " "<<Data[j]<<endl;
}	
}
return 0;
}
	

