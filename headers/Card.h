#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card {
  public:
    enum RANK {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum SUIT {HEARTS, DIAMONDS, SPADES, CLUBS};
    Card();
    Card(RANK, SUIT);
    void setCard(RANK, SUIT);
    int getValue();
    void showCard();
    
  private:
    RANK rank;
    SUIT suit;
};
#endif