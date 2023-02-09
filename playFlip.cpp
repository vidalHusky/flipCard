#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>


#include "Card.h"
#include "Deck.h"
#include "Node.h"
#include "playFlip.h"

using namespace std;

//playFlip cpp file

//updates the user score based on the chosen card
void getScore(Node<Card> node1, int &score) {
    int value = node1.nodeValue.getValue();
    string suit = node1.nodeValue.getSuit();

    switch (value) {
        case 1 :
            score += 10;
            break;
        case 11 ... 13 :
            score += 5;
            break;
        case 8 ... 10 :
            break;
        case 7 :
            score = score / 2;
            break;
        case 2 ... 6 :
            score = 0;
            break;
    }
    if (suit == "Heart") {
        score++;
    }
}

void playFlip() {
    bool isPlaying = true;

    //Initialize deck
    Deck *deck1 = new Deck();
    cout << *deck1 << endl;

    //Initialize hand: cards user flips
//    Deck *hand = new Deck('e');

    //Initialize pile: 24 dealt cards
    Deck *pile = new Deck('e');

    //Shuffle 3 times
    for (int i = 0; i < 3; i++) {
        cout << "Shuffling deck... \n" << endl;
        deck1->shuffle();
    }

    //Deal 24 cards and replace at bottom
    cout << "Dealing 24 cards: " << endl;
    Node<Card> *node1, *node2;
    for (int i = 0; i < 24; i++) {
        node1 = new Node<Card>(deck1->deal());
        cout << "Dealing " << i << ": " << node1->nodeValue << endl;
        pile->replace(node1);
    }
    cout << *pile;

    //Print the rest of the deck
    cout << "Remaining cards: " << endl;
    cout << *deck1 << endl;

    cout <<
         "The player draws 24 cards from the top of the deck, without looking at them, and places\n"
         "them face down on the table.\n"
         "The player can either select a card to turn over, or end the game. If a card is turned over,\n"
         "the player:\n"
         "(a) receives 10 points for an ace,\n"
         "(b) receives 5 points for a king, queen or jack,\n"
         "(c) receives 0 points for an 8, 9 or 10,\n"
         "(d) loses half their points (rounded down) for a 7,\n"
         "(e) loses all their points for a 2, 3, 4, 5 or 6, and\n"
         "(f) receives 1 point extra, in addition to the above, for a heart.\n"
         "The goal is to end the game with the most points." << endl;

    int playerChoice = 0;
    int score = 0;
    char kp;
    while (isPlaying) {
        playerChoice = 0;
        cout << "Pick a card 1 - 24 (enter your number):";
        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 24) {
            cout << "Invalid input, closing program." << endl;
            exit(0);
        }

        for (int i = 0; i < 24; i++) {
            node1 = new Node<Card>(pile->deal());
            if (i == playerChoice - 1) {
                cout << node1->nodeValue << endl;
                getScore(*node1, score);
            }
            //Extra credit: returning user-picked card to deck and replacing with one dealt from top of deck
            deck1->replace(node1);
            node2 = new Node<Card>(deck1->deal());
            pile->replace(node2);
        }
        cout << "Score: " << score << endl;
        cout << "Do you want to keep playing and draw another card? (Enter \"y/n\")" << endl;
        cin >> kp;
        if (kp == 'n') {
            isPlaying = false;
            cout << "Game over. Final score: " << score << endl;
        } else if (kp != 'y') {
            cout << "Invalid input, you will be forced to play again." << endl;
        }
    }
}