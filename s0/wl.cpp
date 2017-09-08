//  File: wl.cpp
//  Description: Add stuff here ...
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
        //	cout << *it;
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
        //load file with relative or absolute path
    }

    else if (tokens.at(0) == "locate" && tokens.size() > 2) {
        cout << "locate";
    }

    else {
        invalidCmd();
    }

    return true;
}

void invalidCmd()
{
    cout << "ERROR: Invalid command";
    cout << '\n';
}
