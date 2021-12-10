#include "../headers/Deck.h"
#include <iostream>
using namespace std;

Deck::Deck(){
  refreshDeck();
};

void Deck::refreshDeck() {
  Card::SUIT suits[] = {Card::HEARTS, Card::DIAMONDS, Card::SPADES, Card::CLUBS};
  Card::RANK ranks[] = {Card::ACE, Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN, Card::JACK, Card::QUEEN, Card::KING};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      add(Card(ranks[j], suits[i]));
    }
  }
}

Card Deck::deal() {
  return remove();
}