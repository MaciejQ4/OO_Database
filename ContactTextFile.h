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

public:

	void appendContactToTextFile(Contact contact, int userID);
	vector<Contact> uploadContactsFromTextFile(int userID);
	int assignNewIDtoContact();
	
};

#endif
