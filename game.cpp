#include "game.h" 
#include "player.h" 
#include "stdafx.h"
using namespace std;

shared_ptr<Game> Game::instance() {
	if (gamePtr == 0) { // which is singular, points to nothing
		throw "instance_not_available";
	}
	else {
		return gamePtr;
	}
}

void start_game(const string& sofgames) {
		if (&sofgames != NULL) {//TODO: weird? but compiler said so 
				throw "game already started";
		}
		else if (!sofgames.find("FiveCardDraw")) {
			throw "unknown game";
	}
		else {
			//shared_ptr<FiveCardDraw> =std::make_shared<FiveCardDraw> (); 
		
	}
}

void Game::stop_game() {
	if (gamePtr == NULL) {
		gamePtr.reset();
	}
	else {
		throw "no_game_in_process";
	}
	
}

void Game::add_player(const char* name) {
	auto same_player = find_player(name);
	if (same_player) {
		throw " already playing";
	}
	else {
		players.push.back(std::make_shared<player>(name));
	}
}

shared_ptr<player> Game::find_player(const char* name) {
	for (std::vector<shared_ptr<player>>::iterator p = players.begin(); p != players.end(); p++) {
		if (this->name == name) {
			return this;
		}
	}
	else if (shared_ptr<player> == failed) {
		return failed;
	}
	   
}




int Game::before_return(player&) {
		return 0;
}
int Game::turn(player&) {
		return 0;
}
int Game::after_turn(player&) {
		return 0;
}

int Game::before_round() {
		return 0;
}
int Game::round() {
		return 0;
}
int Game::after_round() {
	return 0;
}



