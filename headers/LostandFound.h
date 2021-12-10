#ifndef LandF_H
#define LandF_H
#include <iostream>
#include "CardPile.h"
using namespace std;

class LostandFound : public CardPile {
  public:
    Card deal();
};
#endif