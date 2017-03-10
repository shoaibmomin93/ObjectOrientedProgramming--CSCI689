
/****************************************************************
   PROGRAM:   A CARD GAME
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, December 3, 2015

   FUNCTION:  This is the Deck Implementation  file

****************************************************************/

#include "Deck.h"
/****************************************************************

   FUNCTION:  Deck();

   ARGUMENTS:  none

   RETURNS:    nothing
****************************************************************/
Deck::Deck()
{
/*
for(RANK i=two;i<=ace;i=RANK(i+1)){
for(SUIT j=clubs;j<=spades;j=SUIT(j+1)){ 
cards.push_back(Card(i,j));
}
}
*/
int i=0,j;
for(j=0;j<13;i++,j++)                      // Build the deck for each type of suits, set values
{
deck_cards[i].rank = (Card::RANK)j;
deck_cards[i].suit = Card::Clubs;
}
for(j=0;j<13;i++,j++)
{
deck_cards[i].rank = (Card::RANK)j;
deck_cards[i].suit = Card::Diamonds;
}
for(j=0;j<13;i++,j++)
{
deck_cards[i].rank = (Card::RANK)j;
deck_cards[i].suit = Card::Hearts;
}
for(j=0;j<13;i++,j++)
{
deck_cards[i].rank = (Card::RANK)j;
deck_cards[i].suit = Card::Spades;
}
}

/****************************************************************

   FUNCTION:   void shuffle()

   ARGUMENTS: none

   RETURNS:    nothing
****************************************************************/
void Deck::shuffle()
{
int i,j;
for (i=0; i<DECK_CARDS; i++)
{
j = rand()%(DECK_CARDS);        // set values based on the deck_cards
Card temp;
//int a = rand() % 52;
//int b = rand() % 52;
temp = deck_cards[j]; 
deck_cards[j] = deck_cards[i];
deck_cards[i] = temp;
}
}

/****************************************************************

   FUNCTION:   void deal()

   ARGUMENTS: none

   RETURNS:    nothing
****************************************************************/
/*


for(int i = top; i > top - 5; i--)
{
hand.cards.push_back(cards[i]);
}
top = top - 5;
return  hand;
 }



*/
void Deck::deal(Hand& hand)
{
int i=0;
while(i<NUM_HANDS)
{
/*

hand.cards.push_back(cards[i]);
}
top = top - 5;
return  hand
*/

hand.cardarr[i] = deck_cards[top];
i++;                                        // distribute the files
top++;
if(top >= DECK_CARDS)	top = 0;
}
hand.sort();
}
                
