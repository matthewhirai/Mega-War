#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "CardPile.h"
#include <vector>
using namespace std;

class Player : public CardPile {
  private:
    int battlesPlayed;
    int battlesWon;

  public:
    Player();
    Card deal();
    void add(Card c);
    int numCards();
    double Fierceness();
    int getBattlesPlayed();
    int getBattlesWon();
    void won();
    void played();
    void display();
};
#endif