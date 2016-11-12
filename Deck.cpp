/*
Deck.cpp created by Cindy Le (lex@wustl.edu)
*/

#include "stdafx.h"
#include "Deck.h"


using namespace std;

//A constructor that takes a file name and passes it into a call to the load method .
Deck::Deck(const char* &filename) {
	load(filename);
}

//A destructor: the compiler-supplied destructor is sufficient.
Deck::~Deck() {
	//No further action is needed as of now, therefore leaves the destructor for future implementation
}

//To return private cards variable even for outside of the class.
vector<Card> Deck::getCards() const {
	return cards;
}

//To pop and return the last card in the deck.
Card Deck::popCard() {
	if (cards.size()==0) throw(EMPTY_HAND);
	Card c = cards.back();
	cards.pop_back();
	return c;
}

//A "load" method that reads in valid card definition strings from the file.
int Deck::load(const char* &filename) {
	ifstream ifs(filename);
	if (ifs.is_open()) {
		string line(""); //to store content of each input line without '\n'.
		while (getline(ifs, line)) {
			vector<Card> temp = vector<Card>();
			int llen = line.length();

			int pos = 0; //state that takes value of 0, 1, 2, 3, 100. See explanations later in code.
			bool ifCardFinished = false;
			bool ifCardValid = true;
			bool ifLineFinished = false;
			bool ifLineValid = true;

			CardRank rank;
			CardSuit suit;

			for (int i = 0; i < llen; i++) {
				char& currentChar = line[i];
				switch (pos) {
				case 0: //nothing read yet; expect either a space or a '/' or a rank.

					rank = convertRank(currentChar);
					if (rank == NO_SUCH_RANK) {//is a space or a '/'
						if (currentChar == '/') pos = 100;
						//else do nothing, pos still be 0
					}
					else if (rank == TEN) pos++;
					else pos = 2;
					break;
				case 1: //have read a '1'; expect a '0'.
					if (currentChar != '0') ifCardValid = false;
					else pos++;
					break;
				case 2: //have read rank; expect a suit.
					suit = convertSuit(currentChar);
					if (suit == NO_SUCH_SUIT) ifCardValid = false;
					if (i == llen - 1) {
						ifCardFinished = true;
						ifLineFinished = true;
					}
					else pos++;
					break;
				case 3: //have read rank and suit; expect a space or a '/'.
					if ((currentChar >= '0' && currentChar <= '9') || (currentChar >= 'a' && line[i] <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
						ifCardValid = false;
					else if (currentChar == '/') pos = 100;
					else {
						ifCardFinished = true;
						pos = 0;
					}
					break;
				case 100: //have read a '/'; expect another '/', or the line is invalid.
					if (currentChar == '/') ifLineFinished = true;
					else pos=0;
				} //end switch

				if (!ifCardValid) ifLineValid = false;
				else if (ifCardFinished) {
					Card c = { suit, rank };
					temp.push_back(c);
					ifCardFinished = false;
				}

				if (ifLineFinished || !ifLineValid) break;

			}//end for

			if (!ifLineValid) cout << "Invalid line detected: " << line << endl;
			else {//push the teporarily stored cards
				int l = temp.size();
				for (int i = 0; i < l; i++) cards.push_back(temp[i]);
			}//end if

		}//end while getline

		ifs.close();
	}
	else { //ifs.is_open==False
		throw(FAIL_OPENING_FILE);
	}

	if (cards.size()<45) {
		throw(TOO_FEW_CARDS);
	}

	return 0;
}

//A "shuffle" method that randomizes the order of all the cards.
void Deck::shuffle() {
	srand((unsigned int)time(0));
	std::shuffle(cards.begin(), cards.end(), default_random_engine());
}

//A const "size" method that returns the number of elements in the container member variable.
int Deck::size() const {
	return cards.size();
}

//To print out deck's information, one card per line.
string Deck::toString() const {
	ostringstream out = ostringstream();
	int len = cards.size();
	
	if (len==0) {
		out << "The deck is empty. " << endl;
	}else {
		out << "The deck has " << len << " cards: " << endl;
		for (int i = 0; i < len; i++) {
			CardSuit suit = cards[i].suit;
			CardRank rank = cards[i].rank;
			out << rankName[rank - 1] << suitName[suit - 1] << "  ";
			if ((i + 1) % 5 == 0) out << endl;
		}
		if (len % 5 != 0) out << endl;
	}
	return out.str();
}

//To read a card's suit from a string.
CardSuit Deck::convertSuit(const char& input) {
	switch (input) {
	case 'S': case 's': return SPADES;
	case 'C': case 'c': return CLUBS;
	case 'D': case 'd': return DIAMONDS;
	case 'H': case 'h': return HEARTS;
	default: return NO_SUCH_SUIT;
	}
}

//To read a card's rank from a string.
CardRank Deck::convertRank(const char& input) {
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



//A non-member insertion operator (operator<<) that prints out valid card definition strings on separate lines.
ostream& operator<<(ostream& out, const Deck& d) {
	out << d.toString();
	return out;
}
