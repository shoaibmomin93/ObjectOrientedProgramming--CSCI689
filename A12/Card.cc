/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Card implemenation  file 
              
****************************************************************/

#include "Card.h"                                  // include header file that conatins class

/****************************************************************

   FUNCTION:   ostream& operator<<(ostream& os, const Card & c/0

   ARGUMENTS:  output stream and card c

   RETURNS:   returns output stream

****************************************************************/ 
ostream& operator<<(ostream& os, const Card& c) // overload << to display the suit and rank of the card
{
return os<<"RANK="<<c.rank<<" SUIT="<<c.suit<<endl;
}

/****************************************************************

   FUNCTION:   Card:: Card(RANK r, SUIT s)

   ARGUMENTS:  RANK r, SUIT s

   RETURNS:    nothing

****************************************************************/
Card:: Card(RANK r, SUIT s)         //this is the constructor
{
//cout<<"in card constructor"<<endl;
rank=r;
suit=s;          //assign values
}

/****************************************************************

   FUNCTION:   Card:: Card(const Card & c)

   ARGUMENTS: Card & c

   RETURNS:    nothing

****************************************************************/

Card::Card(const Card& c)
{
//cout<<"in card constructor"<<endl;
rank = c.rank;              //assign values
suit = c.suit;
}















