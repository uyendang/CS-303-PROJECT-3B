#pragma once
//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
//	morse.h
//

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "morseTree.h"
#include "morse.h"
using namespace std;

void build_tree(string file, morse_code& tree);
map <char, string> populateMap(); //Populate map for english char and morse code eqivilent
string encodeMessage(map <char, string> map, string message); //Encode message using morse code
string decodeMessage(morse_code tree, string message); //Decode message from morse code into plain text