#include "stdafx.h"
#include "FiveCardDraw.h"
#include "stdlib.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <memory>

using namespace std;

//forward declaration
//int validPlayer(vector<shared_ptr<Player>> &currentPlayers, string playername);

//A default constructor for fiveCardDraw that initializes dealer to be the first person and discard to be empty. 
FiveCardDraw::FiveCardDraw() :dealer(0), bet(0), ante(1), pot(0) {
	int i;
	int j;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 14; j++) {
			CardSuit suit = static_cast<CardSuit>(i);
			CardRank rank = static_cast<CardRank>(j);
			Card c = { suit, rank };
			deck.addCard(c);
		}
	}
	deck.shuffle();
}

//A public virtual before_turn method that asks the user cards to discard and then move them to discarDeck.
int FiveCardDraw::before_turn(Player& p) {

	cout << "Player " << p.name << " has turn " << p.hand << endl;
	cout << "Card to discard? Enter the indices separated by space in a line. " << endl;

	vector<bool> ifDelete;
	string toDiscard; //user response

					  //remove card correspondingly
	if (p.isAuto) {
		ifDelete = p.hand.discardIndex();
	}
	else { //wait for user input
		ifDelete = { false,false,false,false,false };
		while (toDiscard.length() == 0) getline(cin, toDiscard);
		toDiscard = " " + toDiscard + " ";
		for (int k = 1; k < 6; k++) {
			if (toDiscard.find(" " + to_string(k) + " ") != string::npos) {
				ifDelete[k - 1] = true;
			}
		}
	}

	// remove the card from the player to the discard desk
	cout << endl;
	for (int i = 4; i >= 0; i--) {
		if (ifDelete[i]) {
			discardDeck.addCard(p.hand[i]);
			p.hand.removeCard(i);
		}
	}

	return 0;
}

//A public virtual turn method that deals as many as that they have discarded.
int FiveCardDraw::turn(Player& p) {
	for (size_t i = p.hand.size(); i <5; i++) {
		if (deck.size() == 0) {
			if (discardDeck.size() == 0) throw NO_CARD_TO_DEAL; //when both decks are empty
			discardDeck.shuffle();
			p.hand << discardDeck; //deal from the discarded when no card in the main deck
		}
		else {
			p.hand << deck;
		}
	}
	return 0;
}

//A public virtual after_turn method that prints out the player's name and the contents of their hand.
int FiveCardDraw::after_turn(Player& p) {
	cout << "Player " << p.name << " has " << p.hand << endl;
	return 0;
}

int FiveCardDraw::betting_phase(Player& p) {
};

//A public virtual before_round method that shuffles and then deals one card at a time from the main deck.
int FiveCardDraw::before_round() {
	int pot = 0;
	int high_cum_bet = 0;
	deck.shuffle();

	//letting ante to be resetted
	std::shared_ptr<int> p;
	int fold = 0;// empty
	p.reset(new fold);
	const int chips = 20;
	*p = sizeof(chips); 
	//adding ante
	if (*p >= ante) {
		add_to_pot(*p, ante);
	}
	else {
		reset(*p);
	}
	}
	//std::cout << *p << '\n';
 // betting phases

     int len = players.size();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < len; j++) {
			int index = (dealer + j + 1) % len;
			if (players[index]->hand.size()<5) players[index]->hand << deck;
		}
	}
	
	for (int i = 0; i <len; i++) {
		before_turn(*players[i]);
	}
	return 0;

}
}


//A public virtual round method that iterates through the players calling their turn method and then their after_turn method.
int FiveCardDraw::round() {
	int len = players.size();
	for (int i = 0; i < len; i++) {
		turn(*players[i]);
	}
	for (int i = 0; i < len; i++) {
		after_turn(*players[i]);
	}
	return 0;
}

//A public virtual after_round method that sorts players by hand rank, recycles all cards, and asks whether to leave or join.
int FiveCardDraw::after_round() {
	int len = players.size();
	for (int i = 0; i < len; i++)
	{
		cout << players[i] << endl;
	}
	//sort a temporary vector of pointers to players (a copy of the vector member variable)
	sort(players.begin(), players.end(), handRankCompare);

	for (int i = 0; i < len; i++)
	{
		cout << (*players[i]).hand << endl;
	}

	//find winner's rank
	auto temp = players[len - 1]->hand.rankHand();
	HandRank maxRank = static_cast<HandRank>(temp);

	for (int i = len - 1; i >= 0; i--) {
		//calculate wins and losses
		if (players[i]->hand.rankHand() == maxRank) {
			++players[i]->won;
		}
		else {
			++players[i]->lost;
		}

		//move cards from players to the main deck
		for (int j = players[i]->hand.size() - 1; j >= 0; j--) {
			deck.addCard(players[i]->hand[j]);
			players[i]->hand.removeCard(j);
		}
	}

	//move all cards from discardDeck to the main deck
	while (discardDeck.size() > 0) {
		deck.addCard(discardDeck.popCard());
	}


	autoPlayerLeave();

	//ask whether to leave the game
	string checktemp;
	string quitName;
	ofstream output;
	int quitIndex = -1;
	bool findNo;
	do {

		cout << endl;
		cout << "Any player leaving? Enter 'No' for nobody. " << endl;
		//assume that no player named 'no'
		cout << "Player's name: " << endl;
		cin >> quitName;
		checktemp = quitName;
		transform(quitName.begin(), quitName.end(), checktemp.begin(), ::tolower); //accept 'NO' 'no' 'No' 'nO'
		if (checktemp.find("no") != string::npos && checktemp.length() == 2) {
			findNo = true;
		}
		else if (checktemp.find("no*") != string::npos && checktemp.length() == 3) {
			findNo = true;
		}
		else {
			findNo = false;
		}
		if (!findNo) {
			int len = players.size();
			for (int i = 0; i < len; i++) {
				if (quitName == (*players[i]).name) {
					quitIndex = i;
				}
			}

			if (quitIndex != -1) {
				//output.open(players[quitIndex]->name + ".txt");
				//output << players[quitIndex];
				players.erase(players.begin() + quitIndex);
			}
			else {
				cout << "The player " << quitName << " is not currently playing!" << endl;
			}
		}

	} while (!findNo);

	//ask whether to join the game
	string joinName;

	//bool findNo;
	do {
		cout << endl;
		cout << "Any player joining? Enter 'No' for nobody. " << endl;
		cout << "Player's name: " << endl;
		cin >> joinName;
		checktemp = joinName;
		transform(joinName.begin(), joinName.end(), checktemp.begin(), ::tolower); //accept 'NO' 'no' 'No' 'nO'
		if (checktemp.find("no") != string::npos && joinName.length() == 2) {
			findNo = true;
		}
		else if (checktemp.find("no*") != string::npos && checktemp.length() == 3) {
			findNo = true;
		}
		else {
			findNo = false;
		}
		if (!findNo) addPlayer(joinName); //it checks for duplicates
	} while (!findNo);

	cout << endl;

	dealer = (dealer + 1) % players.size();
	return 0;
}

/*
int validPlayer(vector<shared_ptr<Player>> &currentPlayers, string playername) {
for (unsigned int i = 0; i < currentPlayers.size(); i++) {
if (playername == (*currentPlayers[i]).name) {
return i;
}
}

return -1;
}*/

void FiveCardDraw::autoPlayerLeave() {
	vector<int> autoPlayers = findAuto();
	int numAuto = autoPlayers.size();
	int numPlayers = players.size();
	unsigned int leaveNum = rand() * 100;
	string name;


	//immediate update associated files
	ofstream output;
	for (int i = 0; i < numPlayers; i++) {
		name = (*players[i]).name;
		if (find(autoPlayers.begin(), autoPlayers.end(), i) != autoPlayers.end()) {
			name = name.substr(0, name.size() - 1);
		}
		output.close();
		output.open(name + ".txt");
		output << *players[i];
	}


	//auto players leave with probablity
	for (int i = numAuto - 1; i >= 0; i--) {
		if (autoPlayers[i] == 0) {
			if (leaveNum < 10) {
				players.erase(players.begin() + autoPlayers[i]);
			}
		}
		else if (autoPlayers[i] == numPlayers) {
			if (leaveNum < 50) {
				players.erase(players.begin() + autoPlayers[i]);
			}
		}
		else {
			if (leaveNum < 90) {
				players.erase(players.begin() + autoPlayers[i]);
			}
		}

	}

	return;
}

vector<int> FiveCardDraw::findAuto() {
	int currentPlayerNum = players.size();
	vector<int> autoPlayers;
	for (int i = 0; i < currentPlayerNum; i++) {
		char last = (*players[i]).name.back();
		if (last == '*') {
			autoPlayers.push_back(i);
		}
	}
	return autoPlayers;
}

/*
void FiveCardDraw::autoDiscard() {
vector<int> autoPlayersIndex;
findAuto(autoPlayersIndex);

int len = autoPlayersIndex.size();
for (int i = 0; i <= len; i++ ) {
int index = autoPlayersIndex[i];
vector<int> indexes = players[index]->hand.discardIndex();

}
}

void FiveCardDraw::discard(int handRank) {

}*/


