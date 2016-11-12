/*
lab.cpp created by Cindy Le (lex@wustl.edu)
*/

#include "stdafx.h"
#include "lab.h"

using namespace std;

//To print usage message.
int usageMsg(const char* filename, int errorCode) {
	cout << "Program's name: " << filename << endl;
	cout << "Error " << errorCode <<": "<<errorMsg[errorCode]<< endl;
		//": " <<ProgramError[errorCode] << endl;
	return errorCode;
}

//Main
int main(int argc, char* argv[])
{
	const char* filename = argv[0];
	const char* inputname;
	const string SHUFFLE = "-shuffle";
	bool hasShuffle = false;

	try {
		//Validate commandline arguments
		if (argc < 2) {        //user has provided no arguments at all, always not acceptable
			throw(NO_CMD_ARG);
		}else if (argc == 2) { //user has provided one argument, which should not be "-shuffle"
			if (argv[1]==SHUFFLE) throw(NO_INPUT_FILENAME);
			inputname = argv[1];
		}else if (argc == 3) { //user has provided two arguments, one of which should be "-shuffle
			if (argv[1] == SHUFFLE) {
				if (argv[2] == SHUFFLE) throw(NO_INPUT_FILENAME); //{-shuffle, -shuffle}
				else inputname = argv[2]; //{-shuffle, X}
			}
			else if (argv[2] == SHUFFLE) inputname = argv[1]; //{X, -shuffle}
			else throw(NO_SHUFFLE_KEY);//{X, X}
			hasShuffle = true;
		}else if (argc > 3) {  //user has provided extra arguments, always not acceptable
			throw(EXTRA_ARG);
		}

		//Construct a deck object using the input file name that was given.
		Deck deck = Deck(inputname);

		//If the "-shuffle" command line argument was given, call the deck object's shuffle method.
		if (hasShuffle) deck.shuffle();

		//Push back nine empty hand objects into an STL container.
		vector<Hand> hands = vector<Hand>();
		for (int i = 0; i < 9; i++) {
			Hand hand = Hand();
			hands.push_back(hand);
		}

		//Deal one card at a time from the deck to each of the nine hands in the container in turn.
		for (int i = 0; i < 45; i++) {
			int index = i % 9;
			hands[index] << deck;
		}

		//Print out the contents of the deck object and the contents of each of the hand objects.
		cout << deck;
		cout << "Hands before sorting" << endl;
		for (int i = 0; i < 9; i++) {
			cout << hands[i];
		}

		//Use the STL sort algorithm to order the hands in the container (according to the hand class less than operator).
		sort(hands.begin(), hands.end(), less<Hand>());

		//Again print out the hand objects in the order they now appear in the container.
		cout << "Hands after sorting - card order" << endl;
		for (int i = 0; i < 9; i++) {
			cout << hands[i];
		}

		//Again use the STL sort algorithm to order the hands in the container, but according to the poker hand ranking function.
		sort(hands.begin(), hands.end(), pokerRank);

		//Again print out the hand objects in the order they now appear in the container.
		cout << "Hands after sorting - poker rank" << endl;
		for (int i = 0; i < 9; i++) {
			cout << hands[i];
		}
	}
	catch (ProgramError errorCode) {
		usageMsg(filename, errorCode);
	}

	return 0;
}

bool cmdOptionExists(char** begin, char** end, const string& option) {
	return find(begin, end, option) != end;
}



