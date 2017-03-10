 
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Hand header file

****************************************************************/


#include "Card.h"
class Hand
{                                // declare class methods and variables
public:
friend class Deck;
Card cardarr[5];
bool isPair();
bool isTwoPairs();
bool isThreeOfKind();
bool isStraight();
bool isFlush();
bool isFullHouse();
bool isFourOfKind();
bool isStraightFlush();
private:
void sort()                      // write the sort function to sort the cards. 
{
unsigned i,j;
for( i=0;i<4;i++)
{
for( j=i+1;j<5;j++)
{                                                   // bubble sort algorithm
if(cardarr[i].getRank() > cardarr[j].getRank())
{
Card c1;
c1.rank = cardarr[i].getRank();
c1.suit = cardarr[i].getSuit();
cardarr[i].rank = cardarr[j].getRank();
cardarr[i].suit = cardarr[j].getSuit();
cardarr[j].rank = c1.getRank();
cardarr[j].suit = c1.getSuit();
}
}
}
}

};
