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

int main()
{

    bool end = false;
    string cmd;

    while (!end) {

        cout << ">";
        cin.clear();
        getline(cin, cmd); //get input into cmd
        cin.clear();

        //split by whitespace and copy to vector
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        istringstream iss(cmd);
        vector<string> tokens;
        copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter(tokens));

        //print vector
        //for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        //cout << *it;
        parseInput(tokens);
    }
    return 0;
}

bool parseInput(vector<string> tokens)
{
    if (tokens.size() < 2) {
        if (tokens.at(0) == "end") {
            exit(0);
        }
        else if (tokens.at(0) == "new") {
            cout << "new";
        }

        else {
            invalidCmd();
        }
    }

    else if (tokens.at(0) == "load" && tokens.size() > 1) {
        cout << "load";

        loadFileIntoBST(tokens.at(1));
    }

    else if (tokens.at(0) == "locate" && tokens.size() > 2) {
        cout << "locate";
    }

    else {
        invalidCmd();
    }

    return true;
}


// prints invalid command to output stream
void invalidCmd()
{
    cout << "ERROR: Invalid command";
    cout << '\n';
}


// curr : current occurence, n: given occurrence
int BSTree::locate(BST_Node* root, string key, int n, int curr){

    //empty tree. fail and return -1
    if(root == NULL) {
        return -1;
    }

    if(key == root->word) {
        if(n == curr) {
            return root->count;
        } else {
            curr++;
            return locate(root->right, key, n, curr);
        }
    }

    else if(key < root->word) {
        return locate(root->left, key, n, curr);
    }

    else if(key > root->word) {
        return locate(root->right, key, n, curr);
    }
}


void BSTree::insert(BST_Node* root, BST_Node* newnode) {

    if (root->word > newnode->word) {
        if (root->left != NULL) {
            insert(root->left, newnode);
        } else {
            root->left = newnode;
            return;
        }
    }

    else{
        if (root->right != NULL) {
            insert(root->right, newnode);
        } else {
            root->right = newnode;
            return;
        }
    }
}

void loadFileIntoBST(string fileName) {
       
        //load file with relative or absolute path
        ifstream infile (fileName.c_str());
        
        if(infile.is_open()) {
            cout << "Opened"; 
        } else {
            cout << "Unable to open file"; 
        }

        infile.close();
}