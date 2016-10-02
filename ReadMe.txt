CSE332 lab0: Rank, Suits, Cards and Files
--------------------------------------
Name: Cindy Le 
Student ID: 443231
Email: lex@wustl.edu
======================================
Error Code
0: successful run.
1: fail to open the input file. The input file should be saved under the same directory.
2: wrong number of arguments. The program should read in exact one argument which is the input file name.
======================================
In this lab I defined the following struct(s) and functions:
	struct Card stores instance of each card.
	convertSuit and convertRank intends to convert strings to corresponding data types in Card.
	parseDeck reads from a txt file and parse the strings into a deck of cards.
	printVector prints out deck's information, one card per line.
	usageMsg is called when the number of arguments is incorrect.
For more information about function details, please see comments in the .h and .cpp files.

The program builds successfully. 
The .exe file is C:\Users\lex_000\Documents\Visual Studio 2015\Projects\ConsoleApplication2\Debug\ConsoleApplication2.exe

I typed the following commandlines:
cd C:\Users\lex_000\Documents\Visual Studio 2015\Projects\ConsoleApplication2\Debug
ConsoleApplication2.exe

It prints:
Program's name: ConsoleApplication2.exe
Please place the input file in the same folder.
To parse a deck, run the .exe file with one argument.

Then I had several trials with input file using:
ConsoleApplication2.exe card.txt

It prints out each card in the format "Card x: rank, suit". Some trials that I went through are included at the end of this file.

I typed the command once again, but with a non-existing file name:
ConsoleApplication2.exe not_exist.txt

And it prints:
Fail to open the input file!

All as expected.
=======================================
Extra Credit
I made the file following given instructions. 
After all was set up, it prints exactly the same results as if I were running it the original way.
=======================================
Trial Results

Input 1:
2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC
aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D
2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah
as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s

Output 1:
Card 1: 2, C
Card 2: 3, C
Card 3: 4, C
Card 4: 5, C
Card 5: 6, C
Card 6: 7, C
Card 7: 8, C
Card 8: 9, C
Card 9: 10, C
Card 10: j, C
Card 11: q, C
Card 12: k, C
Card 13: A, C
Card 14: A, D
Card 15: k, D
Card 16: q, D
Card 17: j, D
Card 18: 10, D
Card 19: 9, D
Card 20: 8, D
Card 21: 7, D
Card 22: 6, D
Card 23: 5, D
Card 24: 4, D
Card 25: 3, D
Card 26: 2, D
Card 27: 2, H
Card 28: 3, H
Card 29: 4, H
Card 30: 5, H
Card 31: 6, H
Card 32: 7, H
Card 33: 8, H
Card 34: 9, H
Card 35: 10, H
Card 36: j, H
Card 37: q, H
Card 38: k, H
Card 39: A, H
Card 40: A, S
Card 41: k, S
Card 42: q, S
Card 43: j, S
Card 44: 10, S
Card 45: 9, S
Card 46: 8, S
Card 47: 7, S
Card 48: 6, S
Card 49: 5, S
Card 50: 4, S
Card 51: 3, S
Card 52: 2, S

Input 2:
1234567890

Output 2 is empty.

Input 3:
1c 2c 3c 4c !@#$%^&*~()

Output 3:
Card 1: 2, C
Card 2: 3, C
Card 3: 4, C

Input 4 is empty.

Output 4 is empty.