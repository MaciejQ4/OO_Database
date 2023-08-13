#include "OtherFunctions.h"

string OtherFunctions::readLine() {

    //cin.ignore(); //sometimes usefull sometimes not
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

string OtherFunctions::uppercase(string word) {

    if (!word.empty())
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word[0] = toupper(word[0]);
    }
    return word;
}