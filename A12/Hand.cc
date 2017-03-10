 
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Hand implementation file

****************************************************************/
#include "Hand.h"

/****************************************************************

   FUNCTION:   bool isPair()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/
bool Hand::isPair()
{
for(int i=0;i<4;i++)
{
if(cardarr[i].getRank() == cardarr[i+1].getRank())	return true;  //return treu if condotion matches
}
return false;
}

/****************************************************************

   FUNCTION:   bool isTwoPair()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/


bool Hand::isTwoPairs()
{
if(((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[2].getRank() == cardarr[3].getRank()))|| ((cardarr[1].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank())) || ((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank())))
return true;          //returns true if consition is valid
return false;
}


/****************************************************************

   FUNCTION:   bool isThreeOfKind()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/

bool Hand::isThreeOfKind()
{
if(((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[2].getRank() == cardarr[1].getRank())) || ((cardarr[1].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[2].getRank()))|| ((cardarr[3].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank())))
return true;        //return true if condition is valid
return false;
}


/****************************************************************

   FUNCTION:   bool isStraight()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/

bool Hand::isStraight()
{

for(int i=0;i<4;i++)
{
if(((cardarr[i].getRank())+1) != cardarr[i+1].getRank())	return false; //returns false if it matches
}
return true;       //or return true
}


/****************************************************************

   FUNCTION:   bool isFlush()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/


bool Hand::isFlush()
{
for(int i=0;i<5;i++)
{
if((cardarr[0].getSuit() != cardarr[i].getSuit()))	return false; //returns flush as false if it matches
}
return true;   //or return true
}


/****************************************************************

   FUNCTION:   bool isFullHouse()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/

bool Hand::isFullHouse()
{
if(((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[1].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank()) )|| ((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[2].getRank() == cardarr[3].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank())))
return true;  // if conditon matches , return true
return false;
}

/****************************************************************

   FUNCTION:   bool isFourOfKind()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/


bool Hand::isFourOfKind()
{
if(((cardarr[0].getRank() == cardarr[1].getRank()) && (cardarr[2].getRank() == cardarr[1].getRank()) && (cardarr[2].getRank() == cardarr[3].getRank()) && (cardarr[3].getRank() != cardarr[4].getRank())))	return true; 
if ((((cardarr[1].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[2].getRank()) && (cardarr[3].getRank() == cardarr[4].getRank())&& (cardarr[0].getRank() != cardarr[1].getRank())))) return true;
return false;                            //return true if condition matches
}


/****************************************************************

   FUNCTION:   bool isStraightFlush()

   ARGUMENTS:  none

   RETURNS:    boolean result
****************************************************************/

bool Hand::isStraightFlush()
{
if(isStraight())    //first check if it is straight
{
if(isFlush())        //then check if its a flush
return true;         //return true
}
return false;
}


