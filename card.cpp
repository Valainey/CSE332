/*
card.cpp created by Cindy Le (lex@wustl.edu)
Read from an input .txt file and parse them into a vector that represents a card deck.
*/

#include "stdafx.h"
#include "card.h"
#include <fstream>
#include <vector>

using namespace std;

//Print usage message.
int usageMsg(char* filename) {
	cout << "Program's name: " << filename << endl;
	cout << "Please place the input file in the same folder." << endl;
	cout << "To parse a deck, run the .exe file with one argument." << endl;
	return 2; //means wrong number of arguments
}

//Main
int main(int argc, char* argv[])
{
	
	if (argc<2) { //wrong number of arguments
		return usageMsg(argv[0]);
	}
	vector<Card> cards(0);
	parseDeck(cards, argv[1]);
	printVector(cards);

	return 0;
}


//Read from given input file and store cards in a vector.
int parseDeck(std::vector<Card> &card, char *filename) {
		ifstream ifs(filename);
		if (ifs.is_open()) {
			string line(""); //to store content of each input line without '\n'.
			while (getline(ifs, line)) {
				string word; //to store each valid unit of card representation
				int llen = line.length();
				for (int i = 0; i < llen; i++) {
					bool finish = false; //whether to analyze word now
					if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
						word += line[i];
						if (i==llen-1) { //end of line
							finish = true;
						}
					}else { //a space
						finish = true;
					}

					if(finish){
					//finish reading a word, processing
						int wlen = word.length();
						//cout << wlen << endl;
						if (wlen == 2 || wlen == 3) {
							Card::CardSuit suit = convertSuit(word);
							Card::CardRank rank = convertRank(word);

							if (suit && rank) { //valid card representation
								Card temp = { suit, rank };
								card.push_back(temp);
							}
							//else it's invalid and we can simply ignore it.
						}
						word = "";
					}//end if finish
				}//end for
			}//end while

			ifs.close();
		}else { //ifs.is_open==False
			cout << "Fail to open the input file!" << endl;
			return 1; //means fail to open file
		}
		return 0;
}


//To read a card's suit from a string.
Card::CardSuit convertSuit(const string& input) {
		switch (input[input.length()-1]) { //the last char of string
			case 'S': case 's': return Card::SPADES;
			case 'C': case 'c': return Card::CLUBS;
			case 'D': case 'd': return Card::DIAMONDS;
			case 'H': case 'h': return Card::HEARTS;
			default: return Card::NO_SUCH_SUIT;
		}
}

//To read a card's rank from a string.
Card::CardRank convertRank(const string& input) {
		switch (input[0]) { //the first char of string
			case 'A': case 'a': return Card::A;
			case '2': return Card::TWO;
			case '3': return Card::THREE;
			case '4': return Card::FOUR;
			case '5': return Card::FIVE;
			case '6': return Card::SIX;
			case '7': return Card::SEVEN;
			case '8': return Card::EIGHT;
			case '9': return Card::NINE;
			case '1': //case "10"
				//Because it takes two chars, we need further verification.
				if (input.length() == 3 && input[1] == '0') {
					return Card::TEN;
				}
				else { //invalid card info
					return Card::NO_SUCH_RANK;
				}
			case 'J': case 'j': return Card::J;
			case 'Q': case 'q': return Card::Q;
			case 'K': case 'k': return Card::K;
			default: return Card::NO_SUCH_RANK;
		}
}

//To print out deck's information, one card per line.
int printVector(const vector<Card> &card) {
		vector<string> rankName{ "A","2","3","4","5","6","7","8","9","10","j","q","k" };
		vector<string> suitName{ "C","D","H","S" };

		int len = card.size();
		for (int i = 0; i < len; i++) {
			Card::CardSuit suit = card[i].suit;
			Card::CardRank rank = card[i].rank;
			
			//prints "Card x: rank, suit"
			cout <<"Card "<<i+1<<": "<<rankName[rank-1]<<", "<<suitName[suit-1]<< endl;
			
		}
		
		return 0;
}
