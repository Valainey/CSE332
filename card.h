/*
card.h created by Cindy Le (lex@wustl.edu)
Read from an input .txt file and parse them into a vector that represents a card deck.
*/

#pragma once
//To avoid multiple inclusion
#ifndef CARDS_H_
#define CARDS_H_

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const vector<string> handRankName{ "No Rank", "Straight Flush", "Four of a Kind","Full House", "Flush", "Straight",
"Three of a Kind","Two Pairs", "One Pair" };
const vector<string> rankName{ "2","3","4","5","6","7","8","9","10","j","q","k","a" };
const vector<string> suitName{ "C","D","H","S" };

//struct(s)
struct Card {
	enum CardSuit { NO_SUCH_SUIT, CLUBS, DIAMONDS, HEARTS, SPADES };
	enum CardRank { NO_SUCH_RANK, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, A};
	enum HandRank { NO_RANK, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIRS, ONE_PAIR};
	
	CardSuit suit;
	CardRank rank;
};

//functions
int usageMsg(char* filename);
int parseDeck(std::vector<Card> &card, char *filename);
int printVector(const std::vector<Card> &cards);
int sortDeck(std::vector<Card> &cards);
int printRank(std::vector<Card> &cards);
bool operator<(const Card&, const Card&);

Card::CardSuit convertSuit(const char& input);
Card::CardRank convertRank(const char& input);
Card::HandRank rankHand(const vector<Card> &cards);



#endif //CARDS_H_