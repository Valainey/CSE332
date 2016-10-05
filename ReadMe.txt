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
	rankHand finds rank for the given five cards.
	printRank judges and prints rank for every five cards.
	operator< compares two cards first by rank and suit.

I also modified the following items:
	main will rank and sort a deck after it finishes parsing.
	parceDeck now only allows five valid cards per line, and gives warning to invalid input.
	convertRank is slightly different than the previous version when dealing with "10".
	vector rankName and suitName are moved from .cpp to .h file.

For more information, please see comments in the .h and .cpp files.

The program is built and executed successfully, outputting as expected. Some trial results are appended at the end of this file.

=======================================
Extra Credit
To be added within 24 hours.
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
Card 1: 3, C;   Card 2: 5, S;   Card 3: 6, S;   Card 4: j, D;   Card 5: k, D;   
Card 6: j, C;   Card 7: j, H;   Card 8: q, C;   Card 9: q, H;   Card 10: q, S;   
Card 11: 6, C;   Card 12: 7, H;   Card 13: 8, S;   Card 14: 9, H;   Card 15: 10, S;   
Card 16: j, S;   Card 17: k, S;   Card 18: a, C;   Card 19: a, D;   Card 20: a, H;   
Card 21: 5, D;   Card 22: 6, D;   Card 23: 7, D;   Card 24: 8, D;   Card 25: 9, D;   
Card 26: 2, C;   Card 27: 2, S;   Card 28: 5, H;   Card 29: 7, S;   Card 30: 8, C;   
Card 31: 4, C;   Card 32: 4, D;   Card 33: 4, H;   Card 34: 4, S;   Card 35: a, S;   
Card 36: 2, H;   Card 37: 3, H;   Card 38: 8, H;   Card 39: 10, H;   Card 40: k, H;   
Card 41: 9, C;   Card 42: 9, S;   Card 43: 10, C;   Card 44: 10, D;   Card 45: q, D;   
Card 1 to 5: No Rank
Card 6 to 10: Full House
Card 11 to 15: Straight
Card 16 to 20: Three of a Kind
Card 21 to 25: Straight Flush
Card 26 to 30: One Pair
Card 31 to 35: Four of a Kind
Card 36 to 40: Flush
Card 41 to 45: Two Pairs
