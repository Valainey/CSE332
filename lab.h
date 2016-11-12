/*
lab.h created by Cindy Le (lex@wustl.edu)
*/

#pragma once
//To avoid multiple inclusion
#ifndef LAB_H_
#define LAB_H_

#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum ProgramError {
	SUCCESS, 
	FAIL_OPENING_FILE, TOO_FEW_CARDS, //input file
	NO_INPUT_FILENAME, NO_SHUFFLE_KEY, NO_CMD_ARG, EXTRA_ARG, //cmd args
	HAND_OVERFLOW, EMPTY_HAND //hand
};

const vector<string> errorMsg {
	"Successful run. ",
	//input file
	"Fail to open the input file. ",
	"There are less than 45 cards in the input file. ",
	//cmd args
	"Command line contains no input file name. ",
	"Two command line arguments are given but neither one contains shuffle keyword. ",
	"No command line arguments are given. ",
	"More than two command line arguments are given. ",
	//hand
	"More than five cards are in the hand. "
	"The deck has nothing to pop up. "
};



//main
int usageMsg(char* filename, int errorCode);

#endif //LAB_H_