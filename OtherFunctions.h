#pragma once

#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H

#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include "Person.h"
using namespace std;

class OtherFunctions
{
public:

	static string readLine();
	static char readChar();
	static string uppercase(string word); //makes first letter uppercase
};

#endif