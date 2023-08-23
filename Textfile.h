#pragma once
#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
using namespace std;

class Textfile
{
private:

	const string NAME_OF_TEXTFILE;

protected:
	
	Textfile(string usersOrContactsTextFileName) : NAME_OF_TEXTFILE (usersOrContactsTextFileName) {}

	string getFileName();
	bool isFileEmpty();
};

#endif