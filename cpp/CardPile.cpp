#include <iostream>
#include "../headers/CardPile.h"
using namespace std;

CardPile::CardPile() {};

void CardPile::add(Card c) {
  pile.push_back(c);
};

Card CardPile::remove() {
  Card removed = pile.back();
  pile.pop_back();
  return removed;
};

int CardPile::size() {
  return pile.size();
};

void CardPile::display(){
  int i = 0;
  while (i < size()) {
    if(i != 0 && i % 13 == 0) {
      cout<<endl;
    }
    pile[i].showCard();
    i++;
  }
  cout<<endl;
}