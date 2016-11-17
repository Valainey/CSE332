#pragma once
#ifndef player_H
#include "deck.h"
#include "card.h"
#include "hand.h"
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <random>
#include <algorithm> 
#include <iterator> 
#include <vector> 
#include <set> 
#include <cstring> 
#include <exception> 

using namespace std;

struct player {

	string playerName;
	player(string filename);
	Hand hand;
	unsigned int numHands_won;
	unsigned int numHands_lost;
	


};
ostream& operator<<(ostream& out, const player& p);


#endif player_H