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

/*#include "stdafx.h"
#include "card.h"
#include "hand.h"
#include <vector>
#include <iostream>
class hand;
using namespace std;



class Deck {
	friend void operator<<(Hand&, Deck&);
	friend const bool & operator<< (const ostream &, const Deck &);
	friend bool check_valid(string word);
	int deck_size;
	vector<Card> cards;
	void Deck::shuffle();
	void add_card(Card&);

public:
	Deck() = default;
	Deck(const char* &filename);

	//compile should be fine
	//vector can contain the memory
	int load(const char* filename);
	int size();
private:
	std::vector<Card> cards;
	Deck(const Deck& d) = delete;

};

//void start(Deck& h);
void operator<<(Hand& h, Deck& d);


//std::ostream& operator<<(std::ostream& out, const Deck& deck);*/

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
void add_card(Card&c);
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