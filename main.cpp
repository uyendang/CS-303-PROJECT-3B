// main.cpp

#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include "MorseTree.h"
using namespace std;


int main() {
	ifstream fin("morse.txt");
	MorseTree morseTree;
	string tempLine;
	string code;
	string tempCode;
	char letter;

	while (fin.good())
	{
		fin >> tempLine;

		for(int 1 = 0; i <= line.size(); i++)
		{
			if (isalnum(line[i]))
			{
				letter = line[i];
			}
			else
			{
				code += line[i];
			}
			morseTree.BuildTree(letter, code);
			code = ""; //clear the code
		}
	}
}
/*
struct node {
	char data;
	char code;
	node* left;
	node* right;
};
node* getNewNode(char letter, char code) {
	cout << "creating new node" << endl;
	node* newNode = new node();
	newNode->data = letter;
	newNode->code = code;
	newNode->left = newNode->right = NULL;
	return newNode;
}

class morseTree {
public:
	void insert(char letter, string code);
	string decode(string code);
	string encode(string letter);

private:
	node *root;
	map<char, string> lettertocode;

};

node* insert(node*& rootPtr, char data, char code[5], int c) {

	if (code[c] == '\0') {
		rootPtr = getNewNode(data, code[c]);
		cout << data << " was inserted at level " << c << endl;
		return rootPtr;
	}
	else if (code[c] == '.') {
		++c;
		//cout << c << ": going left" << endl;
		rootPtr->left = insert(rootPtr->left, data, code, c);

	}
	else if (code[c] == '-') {
		++c;
		//cout << c << ": going right" <<  endl;
		rootPtr->right = insert(rootPtr->right, data, code, c);
	}
	return rootPtr;
}
string search(node*& rootPtr, char data, char code[5], int c, string str) {
	int count = 0;
	if (rootPtr == NULL) {
		cout << "Not Found" << endl;
		return NULL;
	}
	else if (data == rootPtr->data) {
		cout << "Found it on level " << count << ":  ";
		cout << data << ":  ";
		cout << code << endl;
		return str;
	}
	else if (code[c] == '.') {
		count++;
		str.append(".");
		cout << "Going left" << endl;
		return search(rootPtr->left, data, code, c, str);
	}
	else if (code[c] == '-') {
		count++;
		str.append("-");
		cout << "Going right" << endl;
		return search(rootPtr->right, data, code, c, str);
	}
}
//wrapper
node* Insert(node*& rootPtr, char data, char code[5]) {
	int count = 0;
	return insert(rootPtr, data, code, count);
}
//wrapper
string Search(node*& rootPtr, char data, char code[5]) {
	int count = 0;
	string str = NULL;
	str = search(rootPtr, data, code, count, str);
	return str;

}
char LatinToMorse(node*& root, char letter) {
	if (root->data == letter)
	{

	}

}

int main() {
	std::cout << "Hello, World!" << std::endl;

	node* mtree;
	mtree = NULL;
	char start[5]{ '\0' };
	char e[5]{ '.', '\0' };
	char t[5]{ '-', '\0' };
	char a[5]{ '.', '-', '\0' };
	char i[5]{ '.', '.', '\0' };
	char n[5]{ '-', '.', '\0' };
	char m[5]{ '-', '-', '\0' };
	char s[5]{ '.', '.', '.', '\0' };
	char u[5]{ '.', '.', '-', '\0' };
	char r[5]{ '.', '-', '.', '\0' };
	char w[5]{ '.', '-', '-', '\0' };
	char d[5]{ '-', '.', '.', '\0' };
	char k[5]{ '-', '.', '-', '\0' };
	char g[5]{ '-', '-', '.', '\0' };
	char o[5]{ '-', '-', '-', '\0' };
	char h[5]{ '.', '.', '.', '.', '\0' };
	char v[5]{ '.', '.', '.', '-', '\0' };
	char f[5]{ '.', '.', '-', '.', '\0' };
	char l[5]{ '.', '-', '.', '.', '\0' };
	char p[5]{ '.', '-', '-', '.', '\0' };
	char j[5]{ '.', '-', '-', '-', '\0' };
	char b[5]{ '-', '.', '.', '.', '\0' };
	char x[5]{ '-', '.', '.', '-', '\0' };
	char c[5]{ '-', '.', '-', '.', '\0' };
	char y[5]{ '-', '.', '-', '-', '\0' };
	char z[5]{ '-', '-', '.', '.', '\0' };
	char q[5]{ '-', '-', '.', '-', '\0' };

	Insert(mtree, '\0', start);
	Insert(mtree, 'e', e);
	Insert(mtree, 't', t);
	Insert(mtree, 'i', i);
	Insert(mtree, 'a', a);
	Insert(mtree, 'n', n);
	Insert(mtree, 'm', m);
	Insert(mtree, 's', s);
	Insert(mtree, 'u', u);
	Insert(mtree, 'r', r);
	Insert(mtree, 'w', w);
	Insert(mtree, 'd', d);
	Insert(mtree, 'k', k);
	Insert(mtree, 'g', g);
	Insert(mtree, 'o', o);
	Insert(mtree, 'h', h);
	Insert(mtree, 'v', v);
	Insert(mtree, 'f', f);
	Insert(mtree, 'l', l);
	Insert(mtree, 'p', p);
	Insert(mtree, 'j', j);
	Insert(mtree, 'b', b);
	Insert(mtree, 'x', x);
	Insert(mtree, 'c', c);
	Insert(mtree, 'y', y);
	Insert(mtree, 'z', z);
	Insert(mtree, 'q', q);


	LatinToMorse(mtree, 'e');





	char  letter = 'e';
	//cout << "Searching for " << letter << endl;
	//Search(rootPtr, letter, '-');


	return 0;
}

*/



