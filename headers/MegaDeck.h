#ifndef MDECK_H
#define MDECK_H
#include <iostream>
#include "Deck.h"
#include "CardPile.h"
using namespace std;

class MegaDeck : public CardPile {
  public:
    MegaDeck(int);
    Card deal();
    void shuffle();
};
#endif