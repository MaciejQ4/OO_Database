#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "AuxillaryFuntions.h"
#include "Contact.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


class ContactTextFile
{
	const string contactsTextFileName = "contacts.txt";
	fstream contactsTextFile;

	bool isContactsTextFileEmpty();
	string createLineOfData(Contact contact);

public:

	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	int assignNewIDtoContact();
	
};

#endif
