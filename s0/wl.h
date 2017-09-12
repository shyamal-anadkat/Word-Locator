/** 
* @file wl.h
* @description header file
* @author Shyamal Anadkat
* @email anadkat@wisc.edu
* @StudentID 9071804893
*/

#ifndef WL_H
#define WL_H


#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctype.h>
#include <stdlib.h>
#include <iterator>
#include <vector>

using namespace std;

/** 
* @brief Represents a single binary search tree node
*
*/
class BST_Node {
public:

    string word;		/*!< key holding data */
    int count; 			/*!< word numbering   */
    BST_Node *left; 	/*!< ptr to left tree */
    BST_Node *right;	/*!< ptr to right tree*/

    BST_Node();			/*!< constructor */
    ~BST_Node() {};		/*!< destructor  */

    BST_Node(string in, int cnt) {
        word = in;
        right = left = NULL;
        count = cnt;
    }
};

/** 
* @brief  Represents a single binary search tree
*/
class BSTree {

public:
    BST_Node* root;

    BSTree() {
        root = NULL;
    }

    ~BSTree() {  }

/**
* Frees tree's memory
* @param root root of BST tree
*
*/
    void deleteTree(BST_Node* root);
};


/**
* helper function to transform string lowercase
* @param in an input string
* @return lower case output string
*
*/
string toLower(string in);

/**
* parses given tokens
* @param tokens vector of input tokens
* @return true if correctly parsed
*
*/
bool parseInput(vector<string> tokens);

/**
* prints out invalid command string
*/
void invalidCmd();

/**
* Loads the given file into the search tree
* @param fileName location of file
* @return total file wordcount
* Returns -1 if invalid
*
*/
int  loadFileIntoBST(string fileName);
/**
* Inserts a BST_Node into the tree
* @param root word-search tree root
* @param newnode the node to be added
*
*/
void insert(BST_Node* root, BST_Node* newnode);

/**
* Locates the word given input params
* @param root root of the tree
* @param key word to be searched
* @param n nth occurence of the word
* @param curr ref. to occurence of key so far
* @return location of the resulting word in file
*
*/
int  locate(BST_Node* root, string key, int n, int curr);


// end of header guard
#endif