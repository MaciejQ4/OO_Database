#pragma once
#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
using namespace std;

class Textfile
{
	const string NAME_OF_TEXTFILE;

protected:
	Textfile(string nameOfTextFile) : NAME_OF_TEXTFILE (nameOfTextFile) {}

	string getFileName();
	bool isFileEmpty();
};

#endif