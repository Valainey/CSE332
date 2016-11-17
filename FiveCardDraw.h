#pragma once
#ifndef FiveCardDraw_H
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include "game.h"
using namespace std;

class Game;
class FiveCardDraw:public Game{
protected:
	size_t dealer;
	Deck discard_deck;

public:

	FiveCardDraw();
	int virtual before_turn(player&);
	int virtual turn(player&);
	int virtual after_turn(player&);
	int virtual before_round();
	int virtual round() ;
	int virtual after_round();

};











#endif FiveCardDraw_H
