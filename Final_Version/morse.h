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

//adds info to map for english characters and morse code
map <char, string> populateMap(); 

//encode message to morse code from english
string encodeMessage(map <char, string> map, string message); 

//decode message from morse code into english
string decodeMessage(morse_code tree, string message); 