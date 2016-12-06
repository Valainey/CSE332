#include "stdafx.h"
#include "PokerGame.h"
#include "SevenCardStud.h"
#include "stdlib.h"
using namespace std;

const unsigned int curCard = 0;
const unsigned int startCard = 2;
const unsigned int face_down_Card = 1;
const unsigned int dealerLoc = 0;

//A default constructor for SevenCardDraw that initializes dealer to be the first person and discard to be empty. 

SevenCardStud::SevenCardStud() :Game() {
	//initialize as in superclass
}


int SevenCardStud::first_turn(Player& p) {
	int i;
	int j;
	int numCards = 3;
	int numPlayers = players.size();
	int start = dealerLoc + 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < players.size(); j++) {
			if (start >= numPlayers) {
				return 0;
			}

			if (deck.size() > 0) {
				Hand hand{}; // call the hand function
				Card newcard = hand[0]; // using the temp card 
				p.hand << deck;
				if (i < 2) {
					return false;
				}
				else {
					return true;
				}
				players[start]->hand.getCards(newcard);
			}
			else {
				throw NO_CARD_TO_DEAL;
			}
			start++;
		}
		return 0;
	}
}


	int SevenCardStud::middle_turn(Player& p){
		int numCard = 1;
		int numPlayers = players.size();
		int start = dealerLoc + 1;
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < players.size(); j++) {
				if (start >= numPlayers) {
					return 0;
				}
				if (deck.size() > 0) {
					Hand hand{};
					Card newcard = hand[0];
					p.hand << deck;
					 bool newcard= true;
					players[start]->hand.getCards(newcard);
				}
				else {
					throw NO_CARD_TO_DEAL;
				}
				start++;
			}
		}
			return 0;
		}
	
	int SevenCardStud::last_turn(Player& p) {
		int numCard = 1;
		int numPlayers = players.size();
		int start = dealerLoc + 1;
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < players.size(); j++) {
				if (start > numPlayers) {
					return 0;
				}
				if (deck.size() > 0) {
					Hand hand{};
					Card newcard = hand[0];
					p.hand << deck;
					bool newcard = false;
					players[start]->hand.getCards(newcard);
				}
				else {
					throw NO_CARD_TO_DEAL;

				}
				start++;

			}

		}
		return 0;
}

	int SevenCardStud::round() {
		// for first_turn
		if (players.size() > 1) {
			int first_turn();
			int numPlayers = players.size();
			int start = dealerLoc + 1;
			if (start >= numPlayers) {
				return 0;
			}
			else {
				turn(*players.size[start]);
				start++;
			}
		 if(errorMsg) {
			throw NO_CARD_TO_DEAL;
		}
		}
		int bet_in_turn;
}
	}
	
	
//for middle_turn, which contains second,third, and fourth
	for (int i = 0; i < 3; i++) {
		if (players.size() > 1) {
			int middle_turn;
			int numPlayers = players.size();
			for (int i = 0; i < numPlayers; i++) {
				if (start > numPlayers) {
					start = 0;

				}
				else {
					turn(*players[start]);
					start++;
				}
				if (errorMsg) {
					throw NO_CARD_TO_DEAL;
				}
			}
			int bet_in_turn;

		}
	}
	//for last_turn
	if (players.size() > 1) {
		int last_turn;
		int numPlayers = players.size();
		for (int i = 0; i < numPlayers; i++) {
			if (start > numPlayers) {
				start = 0;
			}
			else {
				turn(*players[start]);
				start++;
			}
			if (errorMsg) {
				throw NO_CARD_TO_DEAL;
			}
		}
		int bet_in_turn;
	}
	return 0;
	}
				



					


			



	

	