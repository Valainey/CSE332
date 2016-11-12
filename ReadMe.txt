CSE 332 Lab 2: Card Decks and Hands
-------------------------------------
Name: Cindy Le 
Student ID: 443231
Email: lex@wustl.edu
=====================================

In this lab I wrote two new classes, Hand and Deck.

The main function reads an input file and deal the cards to nine hands.

For more information, please see comments in the .h and .cpp files.

-------------------------------------

While building the file, I got the following errors:

C2065 'Card': undeclared identifier
C3646 'popCard': unknown override specifier
C2059 syntax error: '('
C2238 unexpected token(s) preceding
Caused by improper inclusion of head file 'card.h'
Fixed by renaming and including 'Card.h'

C2061 syntax error: identifier 'Deck'
C2805 binary 'operator<<' has too few parameters
C2678 no operator found which takes a left-hand operand of type 'Hand'
Caused by circular dependency of Deck.cpp and Hand.cpp
Fixed by adding class keywords in both files above according to
http://stackoverflow.com/questions/15715882/error-c2061-syntax-error-identifier

C4996 'std::copy_Unchecked_iterators::_Deprecate': Call to 'std::copy' with parameters that may be unsafe
C2794 'iterator_category': is nota member of any direct or indirect base class of 'std::iterator_traits<_OutIt>'
C2938 '_Iter_cat_t<std::vector<Card,std::allocator<_Ty>>>': Failed to specialize alias template
C2062 type 'unknown-type' unexpected
Caused by improper inclusion of STL library
Fixed by including <iterator> in Deck.h for std::copy() according to
https://github.com/erengy/anitomy/issues/2

C4244 'argument': conversion from 'time_t' to 'unsigned int', possible loss of data
Caused by "srand(time(0))" trying to cast 64-bit int to 32-bit int
Fixed by changing to "srand((unsigned int)time(0))" according to
http://stackoverflow.com/questions/9246536/warning-c4244-argument-conversion-from-time-t-to-unsigned-int-possible

--------------------------------------

Once built successfully, I got the following errors:

Failed to detect NO_CMD_ARG error.
Caused by wrong type of error code in definition.
Fixed by modifying the try-catch block, changing "catch(int errorCode)" to "catch(ProgramError errorCode)"

---------------------------------------

Then the program runs and outputs as expected without errors or warnings. 
Some trial results are appended at the end of this file. 

=======================================
Error Code

0 Successful run. 
1 Fail to open the input file. 
2 There are less than 45 cards in the input file. 
3 Command line contains no input file name. 
4 Two command line arguments are given but neither one contains shuffle keyword. 
5 No command line arguments are given. 
6 More than two command line arguments are given.
7 More than five cards are in the hand.
8 The deck has nothing to pop up. 

=======================================
Extra Credit

In this lab I closely followed the following programming guidelines:

A.8-A.9 (exceptions)
My program only throws expections when a problem is detected, while it returns zero for a succesful run.
In the main function I had a block that included every line where an expection may occur.
I corrected the error type so it would caught any exceptions during run time.

A.12-A.15 (pointers and arrays)
I used stringstream type to handle strings, which had internal string buffers that would improve running time.
I did not use a pointer or a fixed-length array while I adopted vector<Card> as my choice of container.
My program always checks a container's size before pointing to an index.
For example, my program checks whether a hand contains five cards before calculating its rank.

A.16 (debugging)
I debugged the program with careful observations and effective attempts to gether useful runtime information.
I tested my program with a wide range of inputs that differ in various aspects (see them at the end).

B.10-B.12 (constructors)
I wrote a separate head file for each .cpp file I had, with class initializations before data member ones.
I strictly followed the instructions of what to define and to declare, with suggested parameters.
My constructors are safe to use after careful pre-requisite checks.

B.18 (copy constructor and assignment operator)
Instances of Card, Hand and Deck are allowed to be copied, so I did not add further codes for them.

B.31 first part (inclusion guards)
I wrote the "inclusion guard" construct for every head file I created.


=======================================
Trial Results

Input 1:
Card.exe

Output 1:
Program's name: Card.exe
Error 5: No command line arguments are given. 

Input 2:
Card.exe -shuffle

Output 2:
Program's name: Card.exe
Error 3: Command line contains no input file name. 

Input 3:
Card.exe -shuffle -shuffle

Output 3:
Program's name: Card.exe
Error 3: Command line contains no input file name. 

Input 4:
Card.exe nonexist.txt

Output 4:
Program's name: Card.exe
Error 1: Fail to open the input file. 

Input 5:
Card.exe a b c

Output 5:
Program's name: Card.exe
Error 6: More than two command line arguments are given. 

Input 6:
Card.exe card.txt

KD Qs 6c AH 9D 7s 4s KH 9c
JD QH 10s Ks 6D 8c 4H 10H QD

Output 6:
Program's name: Card.exe
Error 2: There are less than 45 cards in the input file. 

Input 7:
Card.exe card.txt

KD Qs 6c AH 9D 7s 4s KH 9c
JD QH 10s Ks 6D 8c 4H 10H QD
6s JH 9H Js 5D 2s 4D 3H 10c
5s Qc 8s AD 8D 5H As 2H 10D
3c Js 7H Ac 7D 2c 4c 8H 9s

Output 7:
The deck is empty. 
Hands before sorting
9C  9S  10C  10D  qD     (Two Pairs)
2H  3H  8H  10H  kH     (Flush)
4C  4D  4H  4S  aS     (Four of a Kind)
2C  2S  5H  7S  8C     (One Pair)
5D  6D  7D  8D  9D     (Straight Flush)
jS  kS  aC  aD  aH     (Three of a Kind)
6C  7H  8S  9H  10S     (Straight)
jH  jS  qC  qH  qS     (Full House)
3C  5S  6S  jD  kD     (No Rank)
Hands after sorting - card order
2C  2S  5H  7S  8C     (One Pair)
2H  3H  8H  10H  kH     (Flush)
3C  5S  6S  jD  kD     (No Rank)
4C  4D  4H  4S  aS     (Four of a Kind)
5D  6D  7D  8D  9D     (Straight Flush)
6C  7H  8S  9H  10S     (Straight)
9C  9S  10C  10D  qD     (Two Pairs)
jH  jS  qC  qH  qS     (Full House)
jS  kS  aC  aD  aH     (Three of a Kind)
Hands after sorting - poker rank
5D  6D  7D  8D  9D     (Straight Flush)
4C  4D  4H  4S  aS     (Four of a Kind)
jH  jS  qC  qH  qS     (Full House)
2H  3H  8H  10H  kH     (Flush)
6C  7H  8S  9H  10S     (Straight)
jS  kS  aC  aD  aH     (Three of a Kind)
9C  9S  10C  10D  qD     (Two Pairs)
2C  2S  5H  7S  8C     (One Pair)
3C  5S  6S  jD  kD     (No Rank)

Input 8:
Card.exe card.txt -shuffle
(same input file as Input 7)

The deck is empty. 
Hands before sorting
3H  4S  7H  qH  aS     (No Rank)
5S  7D  10S  qD  kS     (No Rank)
5D  8C  8H  8S  aD     (Three of a Kind)
3C  4D  5H  9D  10C     (No Rank)
6C  6D  6S  jD  jS     (Full House)
7S  9S  jH  qC  qS     (One Pair)
2S  4H  10H  kH  aH     (No Rank)
4C  8D  9H  jS  kD     (No Rank)
2C  2H  9C  10D  aC     (One Pair)
Hands after sorting - card order
2C  2H  9C  10D  aC     (One Pair)
2S  4H  10H  kH  aH     (No Rank)
3C  4D  5H  9D  10C     (No Rank)
3H  4S  7H  qH  aS     (No Rank)
4C  8D  9H  jS  kD     (No Rank)
5S  7D  10S  qD  kS     (No Rank)
5D  8C  8H  8S  aD     (Three of a Kind)
6C  6D  6S  jD  jS     (Full House)
7S  9S  jH  qC  qS     (One Pair)
Hands after sorting - poker rank
6C  6D  6S  jD  jS     (Full House)
5D  8C  8H  8S  aD     (Three of a Kind)
7S  9S  jH  qC  qS     (One Pair)
2C  2H  9C  10D  aC     (One Pair)
2S  4H  10H  kH  aH     (No Rank)
3H  4S  7H  qH  aS     (No Rank)
5S  7D  10S  qD  kS     (No Rank)
4C  8D  9H  jS  kD     (No Rank)
3C  4D  5H  9D  10C     (No Rank)

Input 9:
Card.exe card.txt -shuffle

as 2s 3s 4s 5s 6s 7s 8s 9s 10s js qs ks
ad 2d 3d 4d 5d 6d 7d 8d 9d 10d jd qd kd
ah 2h 3h 4h 5h 6h 7h 8h 9h 10h jh qh kh
ac 2c 3c 4c 5c 6c 7c 8c 9c 10c jc qc kc

Output 9:
The deck has 7 cards: 
3C  aS  4S  2S  aD  
aH  2D  
Hands before sorting
4H  5C  5H  9D  10D     (One Pair)
3D  5S  7H  jH  qD     (No Rank)
3S  8C  10S  qS  kC     (No Rank)
3H  6C  6H  6S  7D     (Three of a Kind)
4D  8H  8S  jD  qC     (One Pair)
4C  6D  8D  10C  qH     (No Rank)
9C  9H  9S  10H  aC     (Three of a Kind)
7C  7S  jS  kD  kH     (Two Pairs)
2C  2H  5D  jC  kS     (One Pair)
Hands after sorting - card order
2C  2H  5D  jC  kS     (One Pair)
3D  5S  7H  jH  qD     (No Rank)
3H  6C  6H  6S  7D     (Three of a Kind)
3S  8C  10S  qS  kC     (No Rank)
4H  5C  5H  9D  10D     (One Pair)
4C  6D  8D  10C  qH     (No Rank)
4D  8H  8S  jD  qC     (One Pair)
7C  7S  jS  kD  kH     (Two Pairs)
9C  9H  9S  10H  aC     (Three of a Kind)
Hands after sorting - poker rank
9C  9H  9S  10H  aC     (Three of a Kind)
3H  6C  6H  6S  7D     (Three of a Kind)
7C  7S  jS  kD  kH     (Two Pairs)
4D  8H  8S  jD  qC     (One Pair)
4H  5C  5H  9D  10D     (One Pair)
2C  2H  5D  jC  kS     (One Pair)
3S  8C  10S  qS  kC     (No Rank)
3D  5S  7H  jH  qD     (No Rank)
4C  6D  8D  10C  qH     (No Rank)