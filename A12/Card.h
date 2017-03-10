 
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Card header file

****************************************************************/


#include "/home/cs689/common/689.h"


const int HAND_SIZE= 5;
class Card
{
private:
enum RANK{Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace}rank;
enum SUIT{Clubs, Diamonds, Hearts, Spades}suit;
friend class Deck;
friend class Hand;
friend ostream& operator<<(ostream& os, const Card& c);
Card()
{
rank=Two;
suit=Clubs;
}	
public:
RANK getRank()
{
return rank;
}
SUIT getSuit()
{
return suit;
}
Card(RANK r , SUIT s);
Card(const Card &c);
};

