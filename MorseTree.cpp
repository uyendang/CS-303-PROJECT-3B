
// morse tree.cpp

#include "MorseTree.h"

//constructor
MorseTree::MorseTree()
{
	//create new tree and set everything to null
	root = new node;
	root->data = "";
	root->morseCode = "";
	root->left = NULL;
	root->right = NULL:
}

void MorseTree::BuildTree(char letter, string code) {
	
	morsify[letter] = code;
	node *ptr = root;
	cout << "Storing letter- " << letter;
	int count = 0;
	for (int i = 0; i <= code.length(); i++)
	{ 
		count++;
		if (code[i] = '.')
		{
			if (ptr->left == nullptr)
			{
				ptr->left = new node;
				ptr = ptr->left;
			}
			else
			{
				ptr = node->left;
			}
		}
		else if (code[i] = '-')
		{
			if (ptr->right == nullptr)
			{
				ptr->right = new node;
				ptr = ptr->right;
			}
			else
			{
				ptr = node->right)
			}
		
		}
	}
	cout << "- at depth " << count;
	//store the values in the tree after reaching the correct location
	ptr->morseCode = code;
	ptr->data = letter;
	

}