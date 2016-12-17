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

//tree node
struct letter{ 
public:
	char key; //english character
	vector<char> code;  //vector of morse code

	//pointers to other tree nodes
	struct letter *left;  
	struct letter *right;
};

class morse_code{
public:
	morse_code();  	//constructor
	
	//simple versions for main function
	//	
	void insert(char key, vector<char> code);  //add node
	letter* search(vector<char> code); 	//find morse code
	
	//overloaded versions
	//
	//add node, start at node
	void insert(char key, vector<char> code, struct letter *leaf); 
	//find morse code, start at node
	letter* search(vector<char> code, letter *leaf); 


	//overloaded >, <, == operators for search and insert
	friend bool operator > (const vector<char>& other, const vector<char>& rhs); 
	friend bool operator < (const vector<char>& other, const vector<char>& rhs); 
	friend bool operator == (const vector<char>& other, const vector<char>& rhs); 

	//tree root
	letter *root;  
};

#endif
