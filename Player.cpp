/*
Player.cpp created by Cindy Le, Adrien Xie, and Yanni Yang
*/

#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
const int chips = 20;

//A constructor that tries to read its member variables from a file that has the same name as the player.
Player::Player(char *playername) :name(playername), won(0), lost(0) {
	//hand = Hand();
	string filenamePrefix = playername;
	if (filenamePrefix.back() == '*') {
		filenamePrefix = filenamePrefix.substr(0, filenamePrefix.size() - 1);
		isAuto = true;
	}
	else {
		isAuto = false;
	}
	string save;
	string filename = filenamePrefix + ".txt"; 
	ifstream ifs(filename);
	if (ifs.is_open()) {
		string line;
		std::stringstream str;
		str << ifs.rdbuf();
		save =str.str();
		vector<string> temp = vector<string>(); //to store readins 

												//readin strings
		if (getline(ifs, line)) {
			temp.push_back(line);
		}

		while (!ifs.eof()) {
			getline(ifs, line);
			temp.push_back(line);
		}

		//Probalmeatic
		if (temp.size() >= 3) { //valid
								//name = temp[0];
			won = stoi(temp[1]);
			lost = stoi(temp[2]);
		}
	}
}

//A non-member insertion operator that prints out the player's name, number of wins, and number of losses.
ostream& operator<<(ostream& out, const Player& p) {

	out << p.name << endl;
	out << p.won << endl;
	out << p.lost << endl;
	return out;
}

ofstream& operator<<(ofstream& out, const Player& p) {
	out << p.name << endl;
	out << p.won << endl;
	out << p.lost << endl;
	return out;
}

//
bool handRankCompare(const shared_ptr<Player>& p1, const shared_ptr<Player>& p2) {
	if (p1.get() == NULL) return false;
	if (p2.get() == NULL) return true;
	return pokerRank(p1->hand, p2->hand);
}

//store the player's information to start the game
void Player::save() {
	/*std::map<std::string, std::string>_obj;
	_obj["name"] = name;
	_obj["won"] =  won;
	_obj["lost"] = lost;*/
	FILE * ourfile;
	char fileName[] = { '\0' };
	ourfile = fopen("name.txt", "r");
	int i;
	printf("Enter a filename to save the records :");   //ask the user for the filename
	scanf("%s", fileName); // store the filename data and check
	if (ourfile == NULL) {
		printf("cant't open the file\n");
	}
	else {
		for (i = 0; i < 20; i++) {
			fprintf(ourfile, sizeof(won), sizeof(lost));

		}



	}
}

// reset the game;
void Player::reset() {
	chips = 20;

}

