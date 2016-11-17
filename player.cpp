#include "player.h"
#include <string>
#include "stdafx.h"
using namespace std;

player::player(string filename) {
	this->playerName = filename; // pointer  makes the names to be same
	ifstream infile(filename);
	cout << "filename  " << filename << endl;
	ifstream ifs;
	ifs.open(filename);
	if (ifs.good()) {
		string word_line;
		int num = 0;//we  read 2 values from, won and lost
		while (getline(ifs, word_line) && num < 2)
		{
			if (num == 0) {
				int temp;
				istringstream buffer(word_line);
				buffer >> temp;
				this->numHands_won = temp;
				num++;
			}
			else if (num == 1) {
				int temp;
				istringstream buffer(word_line);
				buffer >> temp;
				this->numHands_lost = temp;
				num++;
			}
			else {
				this->numHands_lost = 0;
				this->numHands_won = 0;
				break;
			}






		}
		if (ifs.fail()) {
			this->numHands_lost = 0;
			this->numHands_won = 0;
		}

	}
}
//A non-member insertion operator (operator<<) that prints out valid card definition strings on separate lines.
	
std::ostream& operator<<(ostream& out, const player& p) {

			out << p.playerName << " games won: " << p.numHands_won << " games_lost " << p.numHands_lost;
			return out;
	}

