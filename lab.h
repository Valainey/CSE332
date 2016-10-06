/*
lab.h created by Cindy Le (lex@wustl.edu)
Read from an input .txt file and parse them into a vector that represents a card deck.
*/

#pragma once
//To avoid multiple inclusion
#ifndef LAB_H_
#define LAB_H_

#include "stdafx.h"
#include "card.h"
#include <vector>
#include <string>

using namespace std;

//main
int usageMsg(char* filename, string msg);

#endif //LAB_H_