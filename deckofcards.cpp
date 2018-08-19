#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "deckofcards.h"

DeckOfCards::DeckOfCards(){
    for ( int row = 0; row <=3; row++ ){
        for ( int column = 0; column <= 12; column++ ){
            deck[row][column] = 0;
        }
    }
    srand( time(0) );
}

void DeckOfCards::shuffle(){
    int row;
    int column;

    for ( int card = 1; card <= 52; card++ ){
        do {
            row = rand() % 4; //random row choice
            column = rand() % 13; //random column choice
        } while ( deck[row][column] != 0 );
        deck[row][column] = card;
    }
}

void DeckOfCards::deal(){
    static const char *suit[4] =
        {"Hearts", "Diamonds", "Clubs", "Spades"};

    static const char *face[13] =
        {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    for ( int card = 1; card <= 52; card++) {
        for (int row = 0; row <= 3; row++) {
            for (int column = 0; column <= 12; column++) {
                if (deck[row][column] == card){
                    cout << setw(5) << right << face[column]
                            << " of " << setw(8) << left << suit[row]
                               << (card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
