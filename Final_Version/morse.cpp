//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
//	morse.cpp
// functions for morse code operations

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "morseTree.h"
#include "morse.h"
using namespace std;

//builds the tree
void build_tree(string file, morse_code& tree){  
	ifstream fin(file); //file for Morse Code key
	string whole_line;  //variable for line
	char key_hold;  // character corrosponding to code
	vector<char> code_hold;  // code that corresponds to character
	while (!fin.eof()){  //read file
		getline(fin, whole_line);  //read line
		key_hold = whole_line[0];  //parse line
		for (int i = 1; i < whole_line.size(); i++)
			code_hold.push_back(whole_line[i]);
		tree.insert(key_hold, code_hold);  //insert pair into tree
		code_hold.clear();
	}
}

//creates map using character as a key and corrosponding morse code as value
map <char, string> populateMap() {
	map <char, string> morseMap;

	//Lowercase
	morseMap.insert(make_pair('a', ".-"));
	morseMap.insert(make_pair('b', "-..."));
	morseMap.insert(make_pair('c', "-.-."));
	morseMap.insert(make_pair('d', "-.."));
	morseMap.insert(make_pair('e', "."));
	morseMap.insert(make_pair('f', "..-."));
	morseMap.insert(make_pair('g', "--."));
	morseMap.insert(make_pair('h', "...."));
	morseMap.insert(make_pair('i', ".."));
	morseMap.insert(make_pair('j', ".---"));
	morseMap.insert(make_pair('k', "-.-"));
	morseMap.insert(make_pair('l', ".-.."));
	morseMap.insert(make_pair('m', "--"));
	morseMap.insert(make_pair('n', "-."));
	morseMap.insert(make_pair('o', "---"));
	morseMap.insert(make_pair('p', ".--."));
	morseMap.insert(make_pair('q', "--.-"));
	morseMap.insert(make_pair('r', ".-."));
	morseMap.insert(make_pair('s', "..."));
	morseMap.insert(make_pair('t', "-"));
	morseMap.insert(make_pair('u', "..-"));
	morseMap.insert(make_pair('v', "...-"));
	morseMap.insert(make_pair('w', ".--"));
	morseMap.insert(make_pair('x', "-..-"));
	morseMap.insert(make_pair('y', "-.--"));
	morseMap.insert(make_pair('z', "--.."));

	//Uppercase
	morseMap.insert(make_pair('A', ".-"));
	morseMap.insert(make_pair('B', "-..."));
	morseMap.insert(make_pair('C', "-.-."));
	morseMap.insert(make_pair('D', "-.."));
	morseMap.insert(make_pair('E', "."));
	morseMap.insert(make_pair('F', "..-."));
	morseMap.insert(make_pair('G', "--."));
	morseMap.insert(make_pair('H', "...."));
	morseMap.insert(make_pair('I', ".."));
	morseMap.insert(make_pair('J', ".---"));
	morseMap.insert(make_pair('K', "-.-"));
	morseMap.insert(make_pair('L', ".-.."));
	morseMap.insert(make_pair('M', "--"));
	morseMap.insert(make_pair('N', "-."));
	morseMap.insert(make_pair('O', "---"));
	morseMap.insert(make_pair('P', ".--."));
	morseMap.insert(make_pair('Q', "--.-"));
	morseMap.insert(make_pair('R', ".-."));
	morseMap.insert(make_pair('S', "..."));
	morseMap.insert(make_pair('T', "-"));
	morseMap.insert(make_pair('U', "..-"));
	morseMap.insert(make_pair('V', "...-"));
	morseMap.insert(make_pair('W', ".--"));
	morseMap.insert(make_pair('X', "-..-"));
	morseMap.insert(make_pair('Y', "-.--"));
	morseMap.insert(make_pair('Z', "--.."));

	return morseMap;
}

//encode message
string encodeMessage(map <char, string> map, string message){
	string tempString; //morse code string
	char tempChar; //character to be encoded

	//loop through message
	for (unsigned i = 0; i<message.length(); ++i){
		tempChar = message.at(i); //Get character
		tempString += map.find(tempChar)->second + " "; //find corrosponding morse code and add to string
	}
	return tempString;
}


//decode message
string decodeMessage(morse_code tree, string encoded) {
	vector <char> decodeThis;	//morse code to decode
	string message; //return message
	char decoded;	//decoded letter

	for (int i = 0; i < encoded.size() + 1; i++) {		//loop through message
		if ((encoded[i] == ' ') || (i == encoded.size())) {	// if  character is space or last character
			decoded = tree.search(decodeThis)->key; //decode letter
			decodeThis.clear();		// clear the letter for further use
			message += decoded;//add decoded character to message
			if (encoded[i] == ' ') i++;		//skip character if is a space
		}
		decodeThis.push_back(encoded[i]);	//add to morse code letter
	}
	return message;
}
