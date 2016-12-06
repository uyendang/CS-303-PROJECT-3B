//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
//  morseTree.hpp
//

#ifndef morseTree_h
#define morseTree_h

#include <vector>
using namespace std;

struct letter  //node for tree
{
public:
	char key; //characters
	vector<char> code;  //morse code vector
	struct letter *left;  //pointers to continue tree
	struct letter *right;
};

class morse_code
{
public:
	morse_code();  //constructor
	

	//these functions are for easy use and access in the main function, they call a more complicated version
	void insert(char key, vector<char> code);  //function to add to tree
	letter* search(vector<char> code); //function to find code/character combo when given a code
	
	//these are the more complicated versions
	void insert(char key, vector<char> code, struct letter *leaf); //insert node starting at given node
	letter* search(vector<char> code, letter *leaf); //search starting at given node
	friend bool operator > (const vector<char>& other, const vector<char>& rhs); //overloaded > operator for search and insert
	friend bool operator < (const vector<char>& other, const vector<char>& rhs); //overloaded < operator for search and insert
	friend bool operator == (const vector<char>& other, const vector<char>& rhs); //overloaded == operator for search and insert

	letter *root;  //root of tree
};

#endif /* build_bTree_hpp */
