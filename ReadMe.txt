CSE 332 Lab 1: Cards, Hands, and Scores
--------------------------------------
Name: Cindy Le 
Student ID: 443231
Email: lex@wustl.edu
======================================
Error Code (from Lab 0)
0: successful run.
1: fail to open the input file. The input file should be saved under the same directory.
2: wrong number of arguments. The program should read in exact one argument which is the input file name.
======================================
In this lab, I defined the following items:
	vector handRankName stores names of hand ranks.
	sortDeck sorts every five cards in asending order.
	hashHand finds rank for a hand, and returns a hash value for it.
	printRank judges and prints rank for every five cards.
	operator< compares two cards first by rank and suit.

I also modified the following items:
	main will rank and sort a deck after it finishes parsing.
	parceDeck now only allows five valid cards per line, and gives warning to invalid input.
	convertRank is slightly different than the previous version when dealing with "10".
	vector rankName and suitName are moved from .cpp to .h file.

For more information, please see comments in the .h and .cpp files.

The program is built and executed successfully, outputting as expected without any errors or warnings. 

Some trial results are appended at the end of this file. 
To illustrate more clearly, the program also prints out deck information after sorting the cards. 

=======================================
Extra Credit
In order to sort hands by their ranks, I wrote a hash function where
	1) the highest digit represents a hand's rank, and
	2) the other six digits is a base-13 number representing ranks of five cards.

Such arrangement ensures a hand that should be placed earlier has a larger hash value. 
Then all hands can be sorted all at once by their hash values.

To avoid more complex structs for hands to be involved, this sorting is naively implemented with bubble sort.
The main part still uses STL sorting algorithm using the operator defined for comparing cards.

The second trial below illustrates how the program responds to hands having same ranks.

=======================================
Trial Results

Input 1:
KD JD 6s 5s 3c // no rank (king high)
6H // not a hand (too few)
Qs QH	 JH Qc Jc // full house
6c 10s 9H  8s  7H // straight
AH Ks Js AD Ac // three of a kind
9D  6D 5D 8D 7D // straight flush
7s 8c 2s 5H 2c // one pair    
Kc 3s 3D 2D 7c 5c  // not a hand (too many)
4s 4H  4D As 4c  // four of a kind
KH   10H 3H 2H 8H // flush
9c QD 10c 10D 9s // two pairs

Output 1:
Invalid line detected: 6H // not a hand (too few)
Invalid line detected: Kc 3s 3D 2D 7c 5c  // not a hand (too many)
The current deck has 45 cards: 
5D  6D  7D  8D  9D  
4C  4D  4H  4S  aS  
jC  jH  qC  qH  qS  
2H  3H  8H  10H  kH  
6C  7H  8S  9H  10S  
jS  kS  aC  aD  aH  
9C  9S  10C  10D  qD  
2C  2S  5H  7S  8C  
3C  5S  6S  jD  kD  
Card 1 to 5: Straight Flush; 
Card 6 to 10: Four of a Kind; 
Card 11 to 15: Full House; 
Card 16 to 20: Flush; 
Card 21 to 25: Straight; 
Card 26 to 30: Three of a Kind; 
Card 31 to 35: Two Pairs; 
Card 36 to 40: One Pair; 
Card 41 to 45: No Rank; 

Input 2:
3c 3c 3c 4c 4d //full house
6c 6h 7c 10d 10c //one pair
2c 2d 2c 5c 7c //three of a kind
3c 5c 7c 8c 10c //flush
3c 5h 6c 7h jc //no rank
4c 5c 6c 7c 8c //straight flush
8c 8c 8c 8d 9c //four of a kind
5c 5d 7c 7c 7c //full house
2c 2d 5c 9h 9h //two pairs
3c 4c 7c 10d 10c //one pair
2c 4h 5c 7h 9c //no rank
4c 6c 6d 6c 8c //three of a kind
2h 3c 4h 5c 6h //straight
3c 6c 6c 6d 6c //four of a kind
2c 5d 5c 9h 9h //two pairs
3c 4c 5c 6c 7c //straight flush
2c 4c 5c 7c 9c //flush
2c 2d 5c 5h 9h //two pairs
4h 5c 6h 7c 8h //straight
3c 3c 7c 8d 10c //one pair
5c 6c 7d 7c 7c //three of a kind

Output 2:
The current deck has 105 cards: 
4C  5C  6C  7C  8C  
3C  4C  5C  6C  7C  
8C  8C  8C  8D  9C  
3C  6C  6C  6C  6D  
5C  5D  7C  7C  7C  
3C  3C  3C  4C  4D  
3C  5C  7C  8C  10C  
2C  4C  5C  7C  9C  
4H  5C  6H  7C  8H  
2H  3C  4H  5C  6H  
5C  6C  7C  7C  7D  
4C  6C  6C  6D  8C  
2C  2C  2D  5C  7C  
6C  6H  7C  10C  10D  
2C  5C  5D  9H  9H  
2C  2D  5C  9H  9H  
2C  2D  5C  5H  9H  
3C  4C  7C  10C  10D  
3C  3C  7C  8D  10C  
3C  5H  6C  7H  jC  
2C  4H  5C  7H  9C  
Card 1 to 5: Straight Flush; 
Card 6 to 10: Straight Flush; 
Card 11 to 15: Four of a Kind; 
Card 16 to 20: Four of a Kind; 
Card 21 to 25: Full House; 
Card 26 to 30: Full House; 
Card 31 to 35: Flush; 
Card 36 to 40: Flush; 
Card 41 to 45: Straight; 
Card 46 to 50: Straight; 
Card 51 to 55: Three of a Kind; 
Card 56 to 60: Three of a Kind; 
Card 61 to 65: Three of a Kind; 
Card 66 to 70: Two Pairs; 
Card 71 to 75: Two Pairs; 
Card 76 to 80: Two Pairs; 
Card 81 to 85: Two Pairs; 
Card 86 to 90: One Pair; 
Card 91 to 95: One Pair; 
Card 96 to 100: No Rank; 
Card 101 to 105: No Rank; 