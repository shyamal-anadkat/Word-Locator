//  File: wl.cpp
//  Description: Main
//  Student Name: Shyamal Anadkat
//  UW Campus ID: 9071804893
//  email: anadkat@wisc.edu

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctype.h>
#include <stdlib.h>
#include <iterator>
#include <vector>
#include "wl.h"

using namespace std;
BSTree* tree = new BSTree;

int main() {
    tree->root = NULL;
    bool end = false;

    string cmd;

    while (!end) {
        cout << ">";        // prompt
        cin.clear();
        getline(cin, cmd);  // get input into cmd
        cin.clear();

        // split by whitespace and copy to vector
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        istringstream iss(cmd);
        vector<string> tokens;
        copy(istream_iterator<string>(iss), istream_iterator<string>(),
             back_inserter(tokens));

        // print vector
        // for (vector<string>::iterator it = tokens.begin(); it != tokens.end();
        // ++it) {
        // cout << *it;
        parseInput(tokens);
    }
    return 0;
}

bool parseInput(vector<string> tokens) {
    if (tokens.size() < 2) {
        if (tokens.at(0) == "end") {
            tree->deleteTree(tree->root);
            exit(0);
        } else if (tokens.at(0) == "new") {
            tree->deleteTree(tree->root);
        }

        else {
            invalidCmd();
        }
    }

    else if (tokens.at(0) == "load" && tokens.size() > 1) {
        if(loadFileIntoBST(tokens.at(1)) == -1) {
            invalidCmd();
        }
        //print_tree(tree->root);
    }

    else if (tokens.at(0) == "locate" && tokens.size() == 3) {

        string word = tokens.at(1);
        string num = tokens.at(2);


        // check for invalid inputs
        for (unsigned int i = 0; i < word.size(); i++) {
            char tmp = word[i];
            if (!(isalnum(tmp) or tmp == 39)) {
                invalidCmd();
                return false;
            }
        }

        bool isValidNum = (num.find_first_not_of( "0123456789" ) == string::npos);
        if(!isValidNum) {
            invalidCmd();
            return false;
        }

        //locate now
        int n = atoi(num.c_str());
        int retVal = locate(tree->root, word, n, 1);

        if( retVal == -1) {
            cout << "No matching entry\n";
        } else {
            cout << retVal << "\n";
        }
    }

    else {
        invalidCmd();
    }

    return true;
}

// prints invalid command to output stream
void invalidCmd() {
    cout << "ERROR: Invalid command";
    cout << '\n';
}


// curr : current occurence, n: given occurrence
int locate(BST_Node* root, string key, int n, int curr) {

    // fail and return -1
    if (root == NULL) {
        //cout << "null";
        return -1;
    }

    if (key == root->word) {
        ///cout << "equals";

        if (n == curr) {
            //printf("n: %d", n);
            //printf("curr: %d", curr);
            return root->count;
        } else {
            curr++;
            return locate(root->right, key, n, curr);
        }
    }

    else if (key < root->word) {
        return locate(root->left, key, n, curr);
    }

    else if (key > root->word) {
        return locate(root->right, key, n, curr);
    }
}


void insert(BST_Node* root, BST_Node* newnode) {

    if (root->word > newnode->word) {
        if (root->left != NULL) {
            insert(root->left, newnode);
        } else {
            root->left = newnode;
            return;
        }
    }

    else {
        if (root->right != NULL) {
            insert(root->right, newnode);
        } else {
            root->right = newnode;
            return;
        }
    }
}



int loadFileIntoBST(string fileName) {
    int wordCount = 1;
    // load file with relative or absolute path
    ifstream infile(fileName.c_str());
    string stream;
    string key = "";

    if (infile.is_open()) {
        while (getline(infile, stream)) {
            // cout << stream;
            for (unsigned int i = 0; i < stream.size(); i++) {
                char tmp = stream[i];
                // cout << tmp;
                if (isalnum(tmp) or tmp == 39) {
                    key += tmp;
                } else {
                    if (key.size() > 0) {
                        transform(key.begin(), key.end(), key.begin(), ::tolower);
                        BST_Node* newnode = new BST_Node(key, wordCount);

                        //cout << key;
                        //cout << wordCount;
                        //cout << '\n';
                        if (tree->root == NULL) {
                            tree->root = newnode;
                        } else {
                            insert(tree->root, newnode);
                        }
                        key = "";
                        wordCount++;
                    }
                }
            }

            if (key.size() > 0) {
                transform(key.begin(), key.end(), key.begin(), ::tolower);
                BST_Node* newnode = new BST_Node(key, wordCount);

                if (tree->root == NULL) {
                    tree->root = newnode;
                } else {
                    insert(tree->root, newnode);
                }
                key = "";
                wordCount++;
            }
        }
        infile.close();
    } else {
        return -1;
    }

    return wordCount;
}


void BSTree::deleteTree(BST_Node* root) {

    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void print_tree(BST_Node *n) {
    if (n) {
        print_tree(n->left);
        cout << n->word;
        cout << n->count;
        cout << "\n";
        print_tree(n->right);
    }
}
