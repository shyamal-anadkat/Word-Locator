//  File: wl.h
//  Description: Header file
//  Student Name: Shyamal Anadkat 
//  UW Campus ID: 9071804893 
//  email: anadkat@wisc.edu

#ifndef WL_H
#define WL_H
using namespace std;

bool parseInput(vector<string> tokens);
void invalidCmd();

class BNode {

public:
	string word;
	int count; 
	BNode *left;
	BNode *right;

	BNode() {}
	BNode(string in) {
		word = in; 
		right = left = NULL;
		count = 0;
	}
};

class BTree{

	BNode *root;


};

//end of header guard
#endif