#pragma once
#ifndef DECK_H
#define DECK_H
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
	Deck() = default;
	Deck(const char* &filename);
	~Deck();

	vector<Card> getCards() const;
	Card popCard();
	void shuffle();
	void addCard(Card&c);
	int size() const;
	string toString() const;

	private:
	int load(const char* &filename);
	vector<Card> cards;
	CardSuit convertSuit(const char& input);
	CardRank convertRank(const char& input);

};

ostream& operator<<(ostream& out, const Deck& d);


























































#endif "DECK_H"
