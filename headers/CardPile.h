#ifndef CARDPILE_H
#define CARDPILE_H
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;

class CardPile {
  protected:
    vector<Card> pile;
  
  public:
    CardPile();
    void add(Card);
    Card remove();
    int size();
    void display();
};
#endif