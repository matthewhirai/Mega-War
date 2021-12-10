#ifndef WarPile_H
#define WarPile_H
#include <iostream>
#include "CardPile.h"
using namespace std;

class WarPile : public CardPile {
  public:
    Card deal();
};
#endif