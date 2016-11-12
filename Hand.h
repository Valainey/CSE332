/*
Hand.h created by Cindy Le (lex@wustl.edu)
*/

#pragma once
//To avoid multiple inclusion
#ifndef HAND_H_
#define HAND_H_

#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include <string>
#include <vector>
#include <algorithm>
/*
Hand.h created by Cindy Le (lex@wustl.edu)
*/

#include <iostream>
#include <sstream>

using namespace std;
class Deck;

//Declare and define a class to represent a card player's hand of cards.
class Hand
{
public:
	Hand() = default;
	Hand(const Hand& h);
	~Hand();

	int size() const;
	string toString() const;

	vector<Card> getCards() const;
	void pushCard(const Card& c);
	int hashHand() const;
	int rankHand() const;

	//operators
	Hand& operator=(const Hand& h);
	bool operator==(const Hand& h) const;
	bool operator<(const Hand& h) const;
	
private:
	vector<Card> cards;

};

Hand& operator<<(Hand& h, Deck& d);
ostream& operator<<(ostream& out, const Hand& h);
bool pokerRank(const Hand& h1, const Hand& h2);

#endif //HAND_H_
