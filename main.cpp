#include <iostream>
#include "headers/Card.h"
#include "headers/CardPile.h"
#include "headers/MegaDeck.h"
#include "headers/WarPile.h"
#include "headers/LostandFound.h"
#include "headers/Deck.h"
#include "headers/Player.h"
#include <vector>
#include <map>
using namespace std;

void war(vector<Player*>& warPlayers, LostandFound& lost, WarPile& warPile) {
  for (int i = 0; i < warPlayers.size(); i++) {
		if ((*warPlayers[i]).numCards() < 4) {
      for (int j = 0; j < (*warPlayers[i]).numCards(); j++) {
        warPile.add((*warPlayers[i]).deal());
      }
      warPlayers.erase(warPlayers.begin() + i);
    }
	}

  // each player deals 4 cards, 4th card being the battle card
  Card battleCard;
  map<Player *, Card> cardsInPlay;
  for (int i = 0; i < warPlayers.size(); i++) {
    for (int j = 0; j < 4; j++) {
      Card card = (*warPlayers[i]).deal();
      warPile.add(card);
      battleCard = card;
    }
    cardsInPlay.insert({warPlayers[i], battleCard});
  }

  int highestBCard = 0;
  for (map<Player *, Card>::iterator it = cardsInPlay.begin(); it != cardsInPlay.end(); it++) {
    if (it->second.getValue() > highestBCard) {
      highestBCard = it->second.getValue();
    }
  }

  vector<Player*> warWinners;
  for (map<Player *, Card>::iterator it = cardsInPlay.begin(); it != cardsInPlay.end(); it++) {
    if (it->second.getValue() == highestBCard) {
      warWinners.push_back(it->first);
    }
  }

  if (warWinners.size() == 1) {
    int i = warPile.size();
    while (i != 0) {
      (*warWinners[0]).add(warPile.deal());
      i = warPile.size();
    }
    i = lost.size();
    while (i != 0) {
      (*warWinners[0]).add(warPile.deal());
      i = lost.size();
    }
    (*warWinners[0]).won();
  }
  
  else {
    war(warPlayers, lost, warPile);
  }
}

int main(){
  int numOfDecks, numOfPlayers = 0;
  bool canContinue = true;
  vector<Player *> Players;
  vector<Player *> validPlayers;

  cout << "Enter number of players: " << endl;
  cin >> numOfPlayers;
  cout << "Enter number of decks: " << endl;
  cin >> numOfDecks;
  
  MegaDeck megaDeck(numOfDecks);
  megaDeck.shuffle();

  for(int i = 0; i < numOfPlayers; i++){
    Player* player = new Player();
    Players.push_back(player);
    validPlayers.push_back(player);
  }

  int cardsPerPlayer = megaDeck.size() / numOfPlayers;

	for (int i = 0; i < numOfPlayers; i++) {
    int j = 0;
		while (j < cardsPerPlayer) {
      (*Players[i]).add(megaDeck.deal());
      j++;
    }
	}

  int battles = 1;
  LostandFound lostAndFound;
  WarPile warPile;

  while (megaDeck.size() != 0) {
    warPile.add(megaDeck.deal());
  }

  while (true) {
    vector<Player *> winners;
    map<Player *, Card> cardsInPlay;
    int highestCard = 0;

    // only allow players that have at least 1 card
		for (int i = 0; i < numOfPlayers; i++) {
		  if ((*Players[i]).numCards() > 0) {
        validPlayers.push_back(Players[i]);
        (*Players[i]).played();

        Card card = (*Players[i]).deal();
        warPile.add(card);
        cardsInPlay.insert({Players[i], card});
      }
		}

    for (map<Player *, Card>::iterator it = cardsInPlay.begin(); it != cardsInPlay.end(); it++) {
      if (it->second.getValue() > highestCard) {
        highestCard = it->second.getValue();
      }
    }

    // add all players whose card is the same as the highest value
    for (map<Player *, Card>::iterator it = cardsInPlay.begin(); it != cardsInPlay.end(); it++) {
      if (it->second.getValue() == highestCard) {
        winners.push_back(it->first);
      }
    }
    if (winners.size() == 1) {
      (*winners[0]).won();
      int i = warPile.size();
      while (i != 0) {
        (*winners[0]).add(warPile.deal());
        i = warPile.size();
      }
    }

    // if there are more than 1 winner, war starts
    else if (winners.size() > 1){
      war(winners, lostAndFound, warPile);
    }

    cout << "Battle " << battles << " stats: " << endl;
		for (int i = 0; i < Players.size(); i++) {
			cout << " Player " << i + 1 << " ";
			(*Players[i]).display();
		}
    battles++;

    int playersLeft = 0;
		for (int i = 0; i < Players.size(); i++) {
			if ((*Players[i]).numCards() > 0)
			  playersLeft++;
		}
		if (playersLeft <= 1) {
      break;
    }	
  }
}