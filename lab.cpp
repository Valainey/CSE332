/*
lab.cpp created by Cindy Le (lex@wustl.edu)
Read from an input .txt file and parse them into a vector that represents a card deck.
*/

#include "stdafx.h"
#include "card.h"

using namespace std;

//To print usage message.
int usageMsg(char* filename, string msg) {
	cout << "Program's name: " << filename << endl;
	cout << "Error message: " << msg << endl;
	cout << "Please place the input file in the same folder." << endl;
	cout << "To parse a deck, run the .exe file with one argument." << endl;
	return 0; //have called usage message
}

//Main
int main(int argc, char* argv[])
{
	if (argc < 2) { //wrong number of arguments
		cout << "Too few arguments!" << endl;
		return 2;
	}

	vector<Card> cards(0);
	int p; //main's return value

	p=parseDeck(cards, argv[1]);
	if (p != 0) return p;
	p=sortDeck(cards);
	if (p != 0) return p;
	printVector(cards);
	printRank(cards);
	//The above part will be rewritten in the next lab on error catch.

	return 0;
}

