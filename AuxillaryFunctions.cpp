#include "AuxillaryFuntions.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string AuxillaryFuntions::readLine() {

    cin.ignore();
    string input;
    getline(cin, input);
    return input;
}