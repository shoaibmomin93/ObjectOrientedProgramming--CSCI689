
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Deck header file

****************************************************************/

#include "Hand.h"

const int SUITS=4;                    //declare constants first
const int RANKS= 13;
const int DECK_CARDS= SUITS*RANKS;
const int NUM_HANDS= 5;
const int  HANDS= 8;
const string ranks[] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
const string suits[] = {"clubs","diamonds","hearts", "spades"};       //declare helper functions to retrieve suit and rank values as enum returns number
class Deck
{
Card deck_cards[DECK_CARDS];         // declare class methods and members
static int top;
public:
Deck();
static int check[HANDS];
void shuffle();
void deal(Hand&);
void set(Hand& hand, bool f)             // set function is used to set if consitions are not met
{
//cout<<"enter in set function of Deck class- header file"<<endl;
if(!(f))
{
if(hand.isStraightFlush())
{
Deck::check[0]++;
return;
}
if(hand.isFourOfKind())
{
Deck::check[1]++;
return;
}
/*
bool isFullHouse(){
if(cards[0].getRank() == cards[1].getRank() && cards[3].getRank() == cards[4].getRank() && ((cards[1].getRank() == cards[2].getRank()) || (cards[2].getRank() == cards[3].getRank())))
{
return true;
}
else
return false;
}

*/
if(hand.isFullHouse())
{
Deck::check[2]++;
return;
}
if(hand.isFlush())
{
Deck::check[3]++;
return;
}
if(hand.isStraight())
{
Deck::check[4]++;
return;
}
/*
bool isThreeOfKind(){
for(int i = 0; i < HAND_SIZE - 2; i++)
{
if(cards[i].getRank() == cards[i+1].getRank() && cards[i+1].getRank() == cards[i+2].getRank())
return true;
}
return false;
}

*/
if(hand.isThreeOfKind())
{
Deck::check[5]++;
return;
}
if(hand.isTwoPairs())
{
Deck::check[6]++;
return;
}
if(hand.isPair())
{
Deck::check[7]++;
return;
}
}			
else
{
if(hand.isStraightFlush())
{
cout<<": Straight Flush"<<endl;         // if straight flush, display it and go to next
Deck::check[0]++;
return;
}
if(hand.isFourOfKind())            //similarly for other consitons
{
cout<<": Four Of Kind"<<endl;
Deck::check[1]++;
return;
}
if(hand.isFullHouse())
{
cout<<": Full House"<<endl;
Deck::check[2]++;
return;
}
if(hand.isFlush())
{
cout<<": flush"<<endl;
Deck::check[3]++;
return;
}
/*
bool isStraight(){
for(int i = 0; i < HAND_SIZE - 1; i++)
{
if(!(cards[i].getRank() == cards[i + 1].getRank() - 1))
{
return false;
}		
}	
return true;
}


*/
if(hand.isStraight())
{
 cout<<": Straight"<<endl;
 Deck::check[4]++;
 return;
}
if(hand.isThreeOfKind())
{
cout<<": Three of a Kind"<<endl;
Deck::check[5]++;
return;
}
if(hand.isTwoPairs())
{
cout<<": Two Pairs"<<endl;
Deck::check[6]++;
return;
}
if(hand.isPair())
{
cout<<": Pair"<<endl;
Deck::check[7]++;
return;
}
}	
}
};
