#include <iostream>
#include <iomanip>
#include "../headers/Player.h"
using namespace std;

Player::Player(){
  battlesPlayed = 0;
  battlesWon = 0;
};

Card Player::deal() {
  return remove();
};

void Player::add(Card c) {
	pile.insert(pile.begin(), c);
}

int Player::numCards(){
  return pile.size();
};

double Player::Fierceness(){
  double fierceness = 0;
  if (pile.size() == 0) {
    return 0.00;
  }
  for (int i = 0; i < pile.size(); i++) {
    fierceness += pile[i].getValue();
  }
  return fierceness/pile.size();
};

int Player::getBattlesPlayed(){
  return battlesPlayed;
};

int Player::getBattlesWon(){
  return battlesWon;
};

void Player::won() {
  battlesWon++;
};

void Player::played() {
  battlesPlayed++;
};

void Player::display() {
  cout << "Fierceness = " << Fierceness() << setprecision (2) << fixed<< " Cards = " << numCards() << " Battles = " << getBattlesPlayed() << " Won = " << getBattlesWon() << endl;
};