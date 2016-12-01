//
// Created by Luke Gilsinger, Uyen Dang, Jeremy Culbreath
// CS 303
// Project 3B
// 12/2/16.
//
#include <iostream>
#include "Decode.h"
#include "Encode.h"

using namespace std;
class Encode
{
private:
	struct Node
	{
		string letter;
		string code;
		Node *left;
		Node *right;
	};
	Node *root;

public:
	Encode()
	{
		root = NULL;
	}
	void Insert(Node *&r, string letter, string code)
	{
		if (r == NULL)
		{
			r = new Node;
			r->letter = letter;
			r->code = code;
			r->left = r->right = NULL;
		}
	}
	void Insert(string letter, string code)
	{
		Node *r = root;
		if (r != NULL)
		{
			for (int i = 0; i < code.length(); i++)
			{
				if (code[i] == '.')
				{
					if (r->left)
						r = r->left;
					else
					{
						// todo: code to bind a new node to r->left
						break;
					}
				}
				else // its always either '.' or '-' so there is no need to double check the symbol here
				{
					if (r->right)
						r = r->right;
					else
					{
						// todo: code to bind a new node to r->right
						break;
					}
				}
			}
		}
		else Insert(root, letter, code);
	}
};