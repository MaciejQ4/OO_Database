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

	Contact gatherCredentialsOfNewContact(int loggedID);

	ContactTextFile contactsTextFile;

public:
	 
	void createContact(int loggedID);
	void showAllContacts(int loggedID);
	void uploadContactsFromTextFile(int loggedID);
	int assignNewIDtoContact();
	//int assignUserIDtoContact();

};

#endif

