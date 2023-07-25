#include "OtherFunctions.h"

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string OtherFunctions::readLine() {

    //cin.ignore();
    string input = "";
    getline(cin, input);
    return input;
}

char OtherFunctions::readChar() {

    string input = "";
    char character = { 0 };

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
    } 
    return character;
}