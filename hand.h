#pragma once
#ifndef Hand_H
#include<vector>
#include "stdafx.h"
#include <string>
#include<iostream>
#include"deck.h"
class Deck;
using namespace std;

/*class Hand {
	friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
	friend void operator<< (const ostream &, const Hand &);
	friend void operator<< (Hand &, Deck &);
	//const bool & Hand::operator== (const Hand &) const;
	friend const bool poker_rank(const Hand &, const Hand &);
	vector<Card> handK;
	int size_;
	int const Hand::size();
	Card operator[] (const size_t);


public:
	//Hand::Hand();
	Hand::Hand(const Hand& h);
	Hand & Hand::operator= (const Hand &);
	bool operator==(const Hand& h);
	bool operator <= (const Hand& h);
	std::string Hand::asString() const;

private:
	std::vector<Card> cards;


};

void operator<< (const ostream &, const Hand &);
void operator<< (Hand &h, Deck &d);
void remove_card(const size_t);
void printHands(vector<Hand> &h);

std::ostream& operator<<(std::ostream& out, const Hand& h);*/
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
	Card operator[] (const size_t index);
	void remove_card(const size_t im);

private:
	vector<Card> cards;

};

Hand& operator<<(Hand& h, Deck& d);
ostream& operator<<(ostream& out, const Hand& h);
bool pokerRank(const Hand& h1, const Hand& h2);
//void remove_card(const size_t);

# endif



