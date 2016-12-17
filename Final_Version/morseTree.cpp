//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
//  morseTree.cpp
// functions to create morse code tree

#include "morseTree.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

//node for morse code 
morse_code::morse_code(){
	root = new letter;
	root->key = ' ';
	root->code.push_back(0);
	root->left = NULL;
	root->right = NULL;
}

void morse_code::insert(char key, vector<char> code){
	insert(key, code, root); //inserts node
}

letter* morse_code::search(vector<char> code){
	return search(code, root);  //finds letter given Morse Code
}

void morse_code::insert(char key, vector<char> code, struct letter *leaf){
	letter* t = new letter;  //build a new node 
	t->key = key;
	t->code = code;
	t->left = t->right = NULL;

	if (leaf->left == NULL && leaf->right == NULL){ //if first node
		leaf->left = t;
		return;
	}

	while (leaf){ //have not inserted
		if (code < leaf->code){ //left
			if (leaf->left == NULL){ //if you can insert
				leaf->left = t; //insert
				break;
			}
			else leaf = leaf->left; //if cannot insert, go down
		}

		else{ //right
			if (leaf->right == NULL){ //if you can insert
				leaf->right = t; //do insert!
				break;
			}
			else leaf = leaf->right; //if cannot insert, go down
		}
	}
}



letter* morse_code::search(vector<char> code, letter *leaf){
	if (leaf){  //if tree remains to traverse
		if (code == leaf->code) return leaf; //found node
		else if (code < leaf->code)	return search(code, leaf->left); //go down left tree until finding node
		else return search(code, leaf->right); //go down right tree until finding node
	}
	else return NULL;  //node  not found
}

bool operator >(const vector<char>& other, const vector<char>& rhs){
	int k; //only traverse the shorter code
	if (other.size() > rhs.size()) k = rhs.size();
	else k = other.size();

	// if dot less than dash
	for (int i = 0; i < k; i++){  //compare characters
		if (other[i] == '.' && rhs[i] == '-') return false; //dot < dash
		else if (other[i] == '-' && rhs[i] == '.') return true; //dash > dot
	}
	return false;  //equal or rhs is shorter
}

bool operator < (const vector<char>& other, const vector<char>& rhs){
	//dot less than dash
	int k;  //only traverse the shorter code
	if (other.size() > rhs.size()) k = rhs.size();
	else k = other.size();

	for (int i = 0; i < k; i++){ //compare characters 
		if (other[i] == '-' && rhs[i] == '.') return false; //dash > dot
		else if (other[i] == '.' && rhs[i] == '-') return true; //dot < dash
	}
	return false; //equal or rhs is shorter 
}

bool operator == (const vector<char>& other, const vector<char>& rhs){
	if (other.size() != rhs.size()) return false;	//size cannot be equal
		
	for (int i = 0; i < other.size(); i++){  //compare each character
		if (other[i] > rhs[i] || other[i] < rhs[i]) return false; //unequal
	}
	return true;  //equal
}

