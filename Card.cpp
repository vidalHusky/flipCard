#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

//Include Card class header file
#include "Card.h"

using namespace std;

//This is a constructor for cards
Card::Card(int v, string s)
{
    value = v;
    suit = s;
}

//Copy Constructor
Card::Card(const Card& c)
{
    value = c.value;
    suit = c.suit;
}

//Overloaded assignment operator
//Card& Card::operator=(const Card& c)
//{
//    value = c.value;
//    suit = c.suit;
//}

//This function sets the value for cards
void Card::setValue(const int& cardValue)
{
    value = cardValue;
}


//This sets the suit for cards
void Card::setSuit(const string& cardSuit)
{
    suit = cardSuit;
}


//This returns the value ie the cards number
int Card::getValue()
{
    return this->value;
}

//This function returns the suit of the card
string Card::getSuit()
{
    return this->suit;
}

//This is an overloaded operator that prints the suit and value of the card
ostream& operator<<(ostream& ostr, Card& Resp)
{
    ostr << Resp.getSuit()<< ", " << Resp.getValue();
    return ostr;
}



