#pragma once
#ifndef SevenCardStud_H_
#define SevenCardStud_H _
#include "Card.h"
#include "Game.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include "stdafx.h"
#include "PokerGame.h"


using namespace std;

class Game;
class SevenCardStud : public Game {


public:
	SevenCardStud();
	int first_turn(Player& p);
	int middle_turn(Player& p);
	int last_turn(Player& p);
	int round();


	virtual int before_turn(Player& p);
	virtual int turn(Player& p);
	virtual int after_turn(Player& p);
	virtual int before_round();
	virtual int round();
	virtual int after_round();
	enum


};




#endif SevenCardStud_H_

