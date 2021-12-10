#include <iostream>
#include "../headers/MegaDeck.h"
using namespace std;

MegaDeck::MegaDeck(int numOfDecks) {
  Deck d;
  int i = 0;
  while (i < numOfDecks) {
    for (int j = 0; j < 52; j++) {
      Card c = d.deal();
      add(c);
    }
    i++;
    
    d.refreshDeck();
  }
};

Card MegaDeck::deal() {
  return remove();
};

void MegaDeck::shuffle() {
  srand(time(NULL));
  Card temp;
  int randIndex = 0;

  for (int i = 0; i < size(); i++) {
    randIndex = rand() % size();
    temp = pile[i];
    pile[i] = pile[randIndex];
    pile[randIndex] = temp;
  }
};