#pragma once
//
// Created by Luke Gilsinger on 12/6/16.
//

#ifndef TREE_MORSETREE_H
#define TREE_MORSETREE_H


#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include <vector>
using namespace std;


struct node {
	char data;
	string code;
	node *left;
	node *right;
};
node* getNewNode(char letter, string code) {
	cout << "creating new node" << endl;
	node* newNode = new node();
	newNode->data = letter;
	newNode->code = code;
	newNode->left = newNode->right = NULL;
	return newNode;
}

class MorseTree {
public:
	//constructor
	BuildTree();

	//building the tree
	void BuildTree(char letter, string code);

	//decoding and encoding
	string decode(string code);  //to latin alphabet
	string encode(string word);  // to morse

private:
	//pointer
	node *root;
	//use map
	map<char, string> morsify;

};

#endif //TREE_M