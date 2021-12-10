#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "CardPile.h"
using namespace std;

class Deck : public CardPile{
  public:
    Deck();
    Card deal();
    void refreshDeck();
};
#endif