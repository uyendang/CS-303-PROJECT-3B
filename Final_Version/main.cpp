//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
//  main.cpp
// main function for morse code program

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "morseTree.h"
#include "morse.h"
using namespace std;

int main()
{
	cout << "Encode/Decode Program.\nTry it out using Morse Code.\n\n"; 
	// can use other replacement codes, not just Morse Code

	morse_code tree;
	string encodedMessage; //for morse code message
	string originalMessage; //for text message

	//creates map using character as a key and morse code as value
	//store in variable morseMap
	map <char, string> morseMap = populateMap();

	string file_name = "morsecodekey.txt";
	cout << "Which file holds the key?\n(morsecodekey.txt is default)\n>";
	cin >> file_name;
	cout << endl;
	build_tree(file_name, tree);
	
	//get message to be encoded
	cout << "What word would you like to encode?\n>";
	cin >> originalMessage;	//get word
	cout << endl;

	//encode message
	encodedMessage = encodeMessage(morseMap, originalMessage);

	//output encoded message
	cout << "\t\"" + originalMessage + "\" encoded is: " + encodedMessage << endl << endl;
	
	//get morse code message to decode
	cout << "What word would you like to decode?\n. (and - only, spaces between letters)\n>";
	string temp; getline(cin, temp);	//clear cin buffer
	getline(cin, encodedMessage);	//get morse code
	cout << endl;
	
	//decode message
	originalMessage = decodeMessage(tree, encodedMessage);

	//output decoded message
	cout << "\t\"" + encodedMessage + "\" decoded is: " + originalMessage << endl << endl;

	system("pause");
	return 0;
}
