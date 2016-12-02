#pragma once
#ifndef SevenCardStud_H_
#define SevenCardStud_H _
#include "Card.h"
#include "Game.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include "stdafx.h"


using namespace std;

class Game;
class SevenCardStud : public Game {


public:
	SevenCardStud();
	
	virtual int turn(Player& p);
	virtual int middle_turn(Player& p);
	virtual int last_turn(Player& p);
	virtual int after_turn(Player& p);
	virtual void betting_phase(Player& p);
	virtual int before_round();
	virtual int round();
	virtual int after_round();
	virtual void bet_phase(Player& p);
		






};




#endif SevenCardStud_H_

