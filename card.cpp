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

	if (argc < 2) { //wrong number of arguments
		return usageMsg(argv[0]);
	}
	vector<Card> cards(0);
	parseDeck(cards, argv[1]);
	sortDeck(cards);
	printVector(cards);
	printRank(cards);

	return 0;
}


//Read from given input file and store cards in a vector.
int parseDeck(std::vector<Card> &cards, char *filename) {
	ifstream ifs(filename);
	if (ifs.is_open()) {
		string line(""); //to store content of each input line without '\n'.
		while (getline(ifs, line)) {
			int llen = line.length();

			int pos = 0; //state that takes value of 0, 1, 2, 3, 100. See explanations later in code.
			bool ifCardFinished = false; 
			bool ifCardValid = true; 
			bool ifLineFinished = false;
			bool ifLineValid = true;

			Card hand[5]; //temporary hand
			int cardCount = 0;
			Card::CardRank rank;
			Card::CardSuit suit;

			for (int i = 0; i < llen; i++) {
				char& currentChar = line[i];
				switch (pos) {
				case 0: //nothing read yet; expect either a space or a '/' or a rank.
					
					rank = convertRank(currentChar);
					if (rank == Card::NO_SUCH_RANK) {//is a space or a '/'
						if (currentChar=='/') pos = 100;
						//else do nothing, pos still be 0
					}
					else if (rank == Card::TEN) pos++;
					else pos = 2; 
					break;
				case 1: //have read a '1'; expect a '0'.
					if (currentChar != '0') ifCardValid = false;
					else pos++;
					break;
				case 2://have read rank; expect a suit.
					suit = convertSuit(currentChar);
					if (suit == Card::NO_SUCH_SUIT) ifCardValid = false;
					if (i == llen - 1) {
						ifCardFinished = true;
						ifLineFinished = true;
					}
					else pos++;
					break;
				case 3://have read rank and suit; expect a space or a '/'.
					if ((currentChar >= '0' && currentChar <= '9') || (currentChar>= 'a' && line[i] <= 'z') || (currentChar >= 'A' && currentChar <= 'Z')) 
						ifCardValid = false;
					else if (currentChar == '/') pos = 100;
					else {
						ifCardFinished = true;
						pos = 0;
					}
					break;
				case 100: //have read a '/'; expect another '/', or the line is invalid.
					if (currentChar == '/') ifLineFinished = true;
					else ifLineValid = false;
				}//end switch

				if (!ifCardValid) ifLineValid = false;
				else if(ifCardFinished){
					cardCount++;
					if (cardCount>5) ifLineValid = false; //too many cards
					else {//shuffle the card into temporary hand
						Card temp = { suit, rank };
						hand[cardCount-1]=temp;
					}
					ifCardFinished = false;
				}

				if (ifLineFinished||!ifLineValid) {
					if (cardCount != 5) ifLineValid = false;
					break;
				}

			}//end for

			if (!ifLineValid) cout << "Invalid line detected: "<<line<< endl;
			else {//push the five cards
				for (int i = 0; i < 5; i++) cards.push_back(hand[i]);
			}//end if

		}//end while getline

		ifs.close();
	}
	else { //ifs.is_open==False
		cout << "Fail to open the input file!" << endl;
		return 1; //means fail to open file
	}
	return 0;
}

//To sort every five cards in asending order.
int sortDeck(std::vector<Card> &cards) {
	int len = cards.size();
	for (int start = 0; start <len-4; start+=5) {
		for (int i = start; i < start + 4; i++) {
			for (int j = start; j < start + 4-(i-start); j++) {
				if (cards[j+1] < cards[j]) {
					Card temp = cards[j];
					cards[j] = cards[j + 1];
					cards[j + 1] = temp;
				}
			}
		}
	}

	return 0;
}

//To judge and print rank for every five cards.
int printRank(std::vector<Card> &cards) {
	int len = cards.size();
	for (int h = 0; h <len; h += 5) {
		vector<Card> hand;
		for (int i = 0; i <= 4; i++) hand.push_back(cards[h + i]);
		Card::HandRank rank = rankHand(hand);

		//print "Card X to X: RANK"
		cout << "Card " << h + 1 << " to " << h + 5 << ": " << handRankName[rank] << "; "<< endl;
	}
	return 0;
}

//To find rank for the given five cards.
Card::HandRank rankHand(const vector<Card> &cards) {

	//preq check
	if (cards.size()!=5) {
		cout << "Not exactly five cards!" << endl;
		return Card::NO_RANK;
	}

	//deal with same rank
	bool pair[4];
	bool three[3];
	bool four[2];
	
	for (int i = 0; i <= 3; i++) {
		if (cards[i].rank == cards[i + 1].rank) pair[i] = true;
		else pair[i] = false;
	}

	for (int i = 0; i <= 2; i++) three[i] = pair[i] && pair[i + 1];
	for (int i = 0; i <= 1; i++) four[i] = three[i] && three[i + 1];
	
	//deal with consecutive rank
	bool straight=true;
	for (int i = 0; i <= 3; i++) {
		if (cards[i + 1].rank - cards[i].rank != 1) straight = false;
	}

	//deal with same suit
	bool flush=true;
	for (int i = 0; i <= 3; i++) {
		if (cards[i + 1].suit != cards[i].suit) flush = false;
	}

	//rank and return
	if (straight && flush) return Card::STRAIGHT_FLUSH;
	if (four[0] || four[1]) return Card::FOUR_OF_A_KIND;
	if ((three[0] && pair[3]) ||(three[2] && pair[0])) return Card::FULL_HOUSE;
	if (flush) return Card::FLUSH;
	if (straight) return Card::STRAIGHT;
	if (three[0]||three[1]||three[2]) return Card::THREE_OF_A_KIND;	
	if ((pair[0] && pair[2]) || (pair[1] && pair[3])) return Card::TWO_PAIRS;
	if (pair[0] || pair[1] || pair[2] || pair[3]) return Card::ONE_PAIR;
	return Card::NO_RANK;
}

//To read a card's suit from a string.
Card::CardSuit convertSuit(const char& input) {
	switch (input) {
	case 'S': case 's': return Card::SPADES;
	case 'C': case 'c': return Card::CLUBS;
	case 'D': case 'd': return Card::DIAMONDS;
	case 'H': case 'h': return Card::HEARTS;
	default: return Card::NO_SUCH_SUIT;
	}
}

//To read a card's rank from a string.
Card::CardRank convertRank(const char& input) {
	switch (input) {
	case 'A': case 'a': return Card::A;
	case '2': return Card::TWO;
	case '3': return Card::THREE;
	case '4': return Card::FOUR;
	case '5': return Card::FIVE;
	case '6': return Card::SIX;
	case '7': return Card::SEVEN;
	case '8': return Card::EIGHT;
	case '9': return Card::NINE;
	case '1': return Card::TEN;
	case 'J': case 'j': return Card::J;
	case 'Q': case 'q': return Card::Q;
	case 'K': case 'k': return Card::K;
	default: return Card::NO_SUCH_RANK;
	}
}

//To print out deck's information, one card per line.
int printVector(const vector<Card> &card) {


	int len = card.size();
	cout << "The current deck has " << len << " cards: " << endl;
	for (int i = 0; i < len; i++) {
		Card::CardSuit suit = card[i].suit;
		Card::CardRank rank = card[i].rank;

		//print "Card x: rank, suit"
		cout << "Card " << i + 1 << ": " << rankName[rank - 1] << ", " << suitName[suit - 1] << ";   ";
		if ((i + 1) % 5 == 0) cout << endl;
	}

	return 0;
}

//To compare two cards first by rank and suit.
bool operator< (const Card& a, const Card& b) {
	if (a.rank == b.rank) return a.suit < b.suit;

	return a.rank < b.rank;
}
