//  File: wl.h
//  Description: Header file
//  Student Name: Shyamal Anadkat
//  UW Campus ID: 9071804893
//  email: anadkat@wisc.edu

#ifndef WL_H
#define WL_H
using namespace std;


// Represents a single binary search tree node
class BST_Node {
public:

    string word;		// key holding data
    int count; 			// word numbering
    BST_Node *left; 	// ptr to left
    BST_Node *right;	// ptr to right

    BST_Node();			//constructor
    ~BST_Node() {};		//destructor

    BST_Node(string in, int cnt) {
        word = in;
        right = left = NULL;
        count = cnt;
    }
};

// Represents a single binary search tree
class BSTree {

public:
    BST_Node* root;

    BSTree() {
        root = NULL;
    }

    ~BSTree() {  }

    void deleteTree(BST_Node* root);
};

bool parseInput(vector<string> tokens);
void invalidCmd();
int  loadFileIntoBST(string fileName);
void insert(BST_Node* root, BST_Node* newnode);
int  locate(BST_Node* root, string key, int n, int curr);

void print_tree(BST_Node* n);
//end of header guard
#endif