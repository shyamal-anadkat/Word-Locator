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
void loadFileIntoBST(string fileName);

class BST_Node {

public:
	string word;		// key holding data
	int count; 			// word numbering 
	BST_Node *left; 	// ptr to left 
	BST_Node *right;	// ptr to right 

	BST_Node();
	~BST_Node();

	BST_Node(string in) {
		word = in; 
		right = left = NULL;
		count = 0;
	}
};

class BSTree{

public:
	BST_Node *root;

	BSTree() {
		root = NULL;
	}

	~BSTree() {}

	void insert(BST_Node* root, BST_Node* newnode);

	int locate(BST_Node* root, string key, int n, int curr);

};

//end of header guard
#endif