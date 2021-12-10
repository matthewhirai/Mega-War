#include <iostream>
#include "../headers/Card.h"
using namespace std;

Card::Card (){}

Card::Card (RANK r, SUIT s) {
  rank = r;
  suit = s;
}

int Card::getValue (){
  return rank;
}

void Card::setCard (RANK r, SUIT s) {
    rank = r;
    suit = s;
}

void Card::showCard () {
  string s;
  if(HEARTS == suit){
    s = "♥";
  }
  else if(DIAMONDS == suit){
    s = "♦";
  }
  else if(SPADES == suit){
    s = "♠";
  }
  else if(CLUBS == suit){
    s = "♣";
  }
  
  cout << getValue() << s << ", ";
}