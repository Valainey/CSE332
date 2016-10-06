/*
card.h created by Cindy Le (lex@wustl.edu)
card includes all functions dealing with card and deck.
*/

#pragma once
//To avoid multiple inclusion
#ifndef CARDS_H_
#define CARDS_H_

#include "stdafx.h"
#include "lab.h"
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

const vector<string> handRankName{ "No Rank", "One Pair", "Two Pairs", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush"};
const vector<string> rankName{ "2","3","4","5","6","7","8","9","10","j","q","k","a" };
const vector<string> suitName{ "C","D","H","S" };

enum CardSuit { NO_SUCH_SUIT, CLUBS, DIAMONDS, HEARTS, SPADES };
enum CardRank { NO_SUCH_RANK, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, A};
enum HandRank { NO_RANK, ONE_PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH};
	

//struct(s)
struct Card {
	CardSuit suit;
	CardRank rank;

	bool operator<(const Card& c) const{
		//compares first by rank then suit
		return rank * 4 + suit < c.rank * 4 + c.suit; 
	}
};

//functions
int parseDeck(vector<Card> &card, char *filename);
int printVector(const vector<Card> &cards);
int sortDeck(vector<Card> &cards);
int printRank(const vector<Card> &cards);

CardSuit convertSuit(const char& input);
CardRank convertRank(const char& input);
int hashHand(const vector<Card> &cards);
int swap(Card& a, Card& b);


#endif //CARDS_H_