#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H


#include "Contact.h"
#include "ContactTextFile.h"

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

class ContactManager
{

	vector<Contact> contacts;

	Contact gatherCredentialsOfNewContact();

	ContactTextFile contactsTextFile;

public:
	void Menu(int userID);
	void createContact(int userID);
	void showAllContacts(int userID);
	void uploadContactsFromTextFile(int userID);
	int assignNewIDtoContact();

};

#endif

