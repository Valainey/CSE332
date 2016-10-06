/*
card.cpp created by Cindy Le (lex@wustl.edu)
Read from an input .txt file and parse them into a vector that represents a card deck.
*/

#include "stdafx.h"
#include "card.h"
#include <fstream>



using namespace std;

//To read from given input file and store cards in a vector.
int parseDeck(vector<Card> &cards, char *filename) {
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
			CardRank rank;
			CardSuit suit;

			for (int i = 0; i < llen; i++) {
				char& currentChar = line[i];
				switch (pos) {
				case 0: //nothing read yet; expect either a space or a '/' or a rank.
					
					rank = convertRank(currentChar);
					if (rank == NO_SUCH_RANK) {//is a space or a '/'
						if (currentChar=='/') pos = 100;
						//else do nothing, pos still be 0
					}
					else if (rank == TEN) pos++;
					else pos = 2; 
					break;
				case 1: //have read a '1'; expect a '0'.
					if (currentChar != '0') ifCardValid = false;
					else pos++;
					break;
				case 2://have read rank; expect a suit.
					suit = convertSuit(currentChar);
					if (suit == NO_SUCH_SUIT) ifCardValid = false;
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
						Card temp = { suit, rank};
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
		cout<< "Fail to open the input file!" << endl;
		return 1; //means fail to open file
	}
	return 0;
}

//To sort every five cards in asending order. Then, sort them all by hands' rank.
int sortDeck(vector<Card> &cards) {
	int numOfCards = cards.size();
	vector<int> hashValues;
	
	for (int i = 0; i < numOfCards - 4; i += 5) {

		//sort cards within each hand
		sort(cards.begin() + i, cards.begin() + i + 5, less<Card>());

		//calculate hash value for each hand
		vector<Card> hand;
		for (int j = 0; j <= 4; j++) hand.push_back(cards[i + j]);
		int hash = hashHand(hand);
		hashValues.push_back(hash);
		
	}

	//***lab 1 extra credit: sort all hands by hands' rank***

	//sort hands by hash value
	int numOfHands = numOfCards / 5;
	for (int i = 0; i < numOfHands - 1; i++) {
		for (int j = 0; j < numOfHands - i - 1; j++) {
			if (hashValues[j + 1] > hashValues[j]) {
				int temp = hashValues[j + 1];
				hashValues[j + 1] = hashValues[j];
				hashValues[j] = temp;
				for (int k = 0; k <= 4; k++) swap(cards[(j + 1) * 5 + k], cards[j * 5 + k]);
			}
		}
	}

	return 0;
}

//To find rank for a hand, and return a hash value for it.
int hashHand(const vector<Card> &cards) {
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
	bool straight = true;
	for (int i = 0; i <= 3; i++) {
		if (cards[i + 1].rank - cards[i].rank != 1) straight = false;
	}

	//deal with same suit
	bool flush = true;
	for (int i = 0; i <= 3; i++) {
		if (cards[i + 1].suit != cards[i].suit) flush = false;
	}

	//rank the hand
	HandRank rank;
	vector<int> index(5); //specify the rule to determine orders when two hands have same rank

	if (straight && flush) { //eg. 12345 all same suit
		rank = STRAIGHT_FLUSH;
		index = { 5, 9, 9, 9, 9 };
	}
	else if (four[0]) { //eg. 11112
		rank = FOUR_OF_A_KIND;
		index = { 3, 4, 9, 9, 9 };
	}
	else if (four[1]) { //eg. 12222
		rank = FOUR_OF_A_KIND;
		index = { 4, 0, 9, 9, 9 };
	}
	else if (three[0] && pair[3]) { //eg. 11122
		rank = FULL_HOUSE;
		index = { 2, 4, 9, 9, 9 };
	}
	else if (three[2] && pair[0]) { //eg. 11222
		rank = FULL_HOUSE;
		index = { 4, 1, 9, 9, 9 };
	}
	else if (flush) { //all same suit
		rank = FLUSH;
		index = { 4, 3, 2, 1, 0 };
	}
	else if (straight) { //eg. 12345
		rank = STRAIGHT;
		index = { 4, 3, 2, 1, 0 };
	}
	else if (three[0]) { //eg. 11123
		rank = THREE_OF_A_KIND;
		index = { 2, 4, 3, 9, 9 };
	}
	else if (three[1]) { //eg. 12223
		rank = THREE_OF_A_KIND;
		index = { 3, 4, 0, 9, 9 };
	}
	else if (three[2]) { //eg. 12333
		rank = THREE_OF_A_KIND;
		index = { 4, 1, 0, 9, 9 };
	}
	else if (pair[0] && pair[2]) { //eg. 11223
		rank = TWO_PAIRS;
		index = { 3, 1, 4, 9, 9 };
	}
	else if (pair[1] && pair[3]) { //eg. 12233
		rank = TWO_PAIRS;
		index = { 4, 2, 0, 9, 9 };
	}
	else if (pair[0] && pair[3]) { //eg. 11233
		rank = TWO_PAIRS;
		index = { 4, 1, 2, 9, 9 };
	}
	else if (pair[0]) { //eg. 11234
		rank = ONE_PAIR;
		index = { 1, 4, 3, 2, 9 };
	}
	else if (pair[1]) { //eg. 12234
		rank = ONE_PAIR;
		index = { 2, 4, 3, 0, 9 };
	}
	else if (pair[2]) { //eg. 12334
		rank = ONE_PAIR;
		index = { 3, 4, 1, 0, 9 };
	}
	else if (pair[3]) { //eg. 12344
		rank = ONE_PAIR;
		index = { 4, 2, 1, 0, 9 };
	}
	else {
		rank = NO_RANK;
		index = { 4, 3, 2, 1, 0 };
	}
	
	int ans = 0;
	for (int i = 0; i <= 4; i++) if(index[i]<=4) ans = ans * 13 + cards[index[i]].rank; 
	ans = rank * 1000000 + ans; //the highest digit represents rank
	return ans;
}

int printRank(const vector<Card> &cards) {
	int len = cards.size();
	for (int h = 0; h <len; h += 5) {
		vector<Card> hand;
		for (int i = 0; i <= 4; i++) hand.push_back(cards[h + i]);
		int hash = hashHand(hand);

		//print "Card X to X: RANK"
		cout << "Card " << h + 1 << " to " << h + 5 << ": " << handRankName[hash/1000000] << "; " << endl;
	}
	return 0;
}

//To read a card's suit from a string.
CardSuit convertSuit(const char& input) {
	switch (input) {
	case 'S': case 's': return SPADES;
	case 'C': case 'c': return CLUBS;
	case 'D': case 'd': return DIAMONDS;
	case 'H': case 'h': return HEARTS;
	default: return NO_SUCH_SUIT;
	}
}

//To read a card's rank from a string.
CardRank convertRank(const char& input) {
	switch (input) {
	case 'A': case 'a': return A;
	case '2': return TWO;
	case '3': return THREE;
	case '4': return FOUR;
	case '5': return FIVE;
	case '6': return SIX;
	case '7': return SEVEN;
	case '8': return EIGHT;
	case '9': return NINE;
	case '1': return TEN;
	case 'J': case 'j': return J;
	case 'Q': case 'q': return Q;
	case 'K': case 'k': return K;
	default: return NO_SUCH_RANK;
	}
}

//To print out deck's information, one card per line.
int printVector(const vector<Card> &card) {


	int len = card.size();
	cout << "The current deck has " << len << " cards: " << endl;
	for (int i = 0; i < len; i++) {
		CardSuit suit = card[i].suit;
		CardRank rank = card[i].rank;

		cout << rankName[rank - 1] << suitName[suit - 1]<<"  ";
		if ((i + 1) % 5 == 0) cout << endl;
	}

	return 0;
}


//To swap two cards. 
//Only used for sorting different hands. Sorting cards within each hand still depends on operator< defined in struct Card.
int swap (Card& a, Card& b) {
	Card temp = a;
	a = b;
	b = temp;
	return 0;
}
