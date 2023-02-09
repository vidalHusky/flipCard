#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <time.h>

//Include Card class header file
#include "Deck.h"
#include "Card.h"
#include "Node.h"

using namespace std;

Deck::Deck() {
    // Creates new node for card object and initializes start of linked list by setting said node to head which is the beginning
    Node<Card> *newNode;
    head = newNode;

    // Four Suits which are then put into a nested for-loop
    const string suits[4] = {"Club", "Diamond", "Heart", "Spade"};
    for (int i = 3; i >= 0; i--) {
        for (int j = 13; j >= 1; j--) {
            // Nested for-loop creates new card with index from suits array
            // value for card ranges from 1-13 for Ace to King and assigns card class to node class to form a linked list
            Card *currentCard = new Card(j, suits[i]);
            newNode = new Node<Card>(*currentCard, head);
            newNode->nodeValue = *currentCard;
            newNode->next = head;
            head = newNode;
        }
    }
}

//Empty deck constructor used to create pile
Deck::Deck(char e) {
    head = NULL;
}

//Deck destructor
Deck::~Deck() {
    Node<Card> *front, *p;
    while (front != NULL) {
        p = front;
        front = NULL;
        delete p;
    }

}

// Overloaded function operator for << which prints out the whole deck containing 52 card from beginning to end of the linked list
ostream &operator<<(ostream &ostr, Deck &d) {
    Node<Card> *point = d.head;
    while (point != NULL) {
        ostr << point->nodeValue << endl; // ", " << &point->next << "\n";
        point = point->next;
    }
    return ostr;
}

// Deck of 52 cards is shuffled
void Deck::shuffle() {
    srand(time(0));
    // SRAND used as random time from current time

    Node<Card> *curr = NULL;
    Node<Card> *prev = NULL;

    for (int r = 0; r < 10000; r++) {
        // for loop spans 10,000 which swaps random index with initial value
        int index = rand() % 50 + 2;
        curr = head;
        prev = NULL;

        // the random value index found
        if (index > 1) {
            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }

            Node<Card> *dummy = NULL;
            dummy = curr->next;
            curr->next = head->next;
            head->next = dummy;
            prev->next = head;
            head = curr;
//            delete dummy;

        } else {
            // For case where second index is switched
            *head->next = *curr->next;
            head = curr;
        }
    }
}

// Returns the top card node of the deck and removes it from the linked list
Node<Card> Deck::deal() {
    Node<Card> *temp;
    temp = head;
    head = head->next;
    return *temp;
}

// Takes a node and places it at the end of the deck linked list
void Deck::replace(Node<Card> *node) {
    Node<Card> *curr = head;
    //Case for the empty deck
    if (head == NULL) {
        head = node;
        node->next = NULL;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = node;
        node->next = NULL;
    }
}