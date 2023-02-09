#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{

    // Private variables created for Card object
private:

    int value;
    string suit;

public:

    // Initializes Card object
    Card(int value, string suit);

    Card(const Card& c);

//    Card& operator=(const Card& c);

    // Initializes functions
    void setValue(const int& cardValue);
    void setSuit(const string& cardSuit);

    int getValue();
    string getSuit();

    // Initializes friend override operator function
    friend ostream& operator<<(ostream& ostr, Card& Resp); // NEED TO PUT PARAMETER VALUES

};
#endif CARD_H