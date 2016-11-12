/*
Deck.h created by Cindy Le (lex@wustl.edu)
*/

#pragma once
//To avoid multiple inclusion
#ifndef DECK_H_
#define DECK_H_

#include "stdafx.h"
#include "Card.h"
#include "Hand.h"
#include "lab.h"

#include <vector>
#include <string>
#include <fstream>

//for randomization
#include <ctime>
#include <cstdlib>
#include <random>

//for std::copy
#include <iterator> 

using namespace std;
class Hand;

class Deck
{
public:
	Deck(const char* &filename);
	~Deck();

	vector<Card> getCards() const;
	Card popCard();
	void shuffle();
	int size() const;
	string toString() const;

private:
	int load(const char* &filename);
	vector<Card> cards;
	CardSuit convertSuit(const char& input);
	CardRank convertRank(const char& input);

};

ostream& operator<<(ostream& out, const Deck& d);

#endif //Deck_H_
