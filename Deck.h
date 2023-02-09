#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "Node.h"

#ifndef DECK_H
#define DECK_H
using namespace std;

// Deck object
class Deck {
    // Private deck operator private values
private:
    Node<Card> *head;
public:
    // Initializes Deck object
    Deck();

    //Initializes Deck object as empty linked list (for pile and hand)
    Deck(char e);

    // Destructor for Deck class
    ~Deck();

    // Deck override operator which prints whole deck aka 52 cards
    friend ostream& operator<<(ostream& ostr, Deck& d);
    void shuffle();

    //Deals the top card
    Node<Card> deal();

    void replace(Node<Card> *node);

};

#endif DECK_H


