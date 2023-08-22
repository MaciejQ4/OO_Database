#pragma once
#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
using namespace std;

class Textfile
{
protected:
	
	Textfile(string usersOrContactsTextFileName) : NAME_OF_TEXTFILE (usersOrContactsTextFileName) {}

	string getFileName();
	bool isFileEmpty();

private:

	const string NAME_OF_TEXTFILE;
};

#endif