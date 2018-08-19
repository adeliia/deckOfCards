#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H


class DeckOfCards{
public:
    DeckOfCards();
    void shuffle();
    void deal();
private:
    int deck[4][13];
};

#endif // DECKOFCARDS_H
