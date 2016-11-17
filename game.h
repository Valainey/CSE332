#pragma once
#ifndef game_H
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include "player.h"
using namespace std;

class Game {

protected:
	static shared_ptr<Game> gamePtr;
	Deck mainDeck;
	shared_ptr<vector<Game>> players;
public:
	static share_ptr<Game> instance();
	static start_game(const string& sofgames);
	void stop_game();
	void add_player(const char*name);
	shared_ptr<player> find_player(const char* name);
	int virtual before_turn(player&) = 0;
	int virtual turn(player&) = 0;
	int virtual after_turn(player&) = 0;
	int virtual before_round() = 0;
	int virtual round() = 0;
	int virtual after_round() = 0;


};
#endif  game_H// !"game_H"

