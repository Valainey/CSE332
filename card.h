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

//struct(s)
struct Card {
	enum CardSuit { NO_SUCH_SUIT, CLUBS, DIAMONDS, HEARTS, SPADES };
	enum CardRank { NO_SUCH_RANK, A, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K };
	CardSuit suit;
	CardRank rank;
};

//functions
int usageMsg(char* filename);
int parseDeck(std::vector<Card> &card, char *filename);
int printVector(const std::vector<Card> &card);

Card::CardSuit convertSuit(const std::string& input);
Card::CardRank convertRank(const std::string& input);



#endif //CARDS_H_