#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactTextFile.h"
#include "OtherFunctions.h"

class ContactManager
{
	int loggedID = 0;
	vector<Contact> contacts;

	Contact gatherCredentialsOfNewContact();

	ContactTextFile contactsTextFile;

public:

	ContactManager(string contactsTextFileName) : contactsTextFile (contactsTextFileName) {};
	void setLoggedID(int id);
	int getLoggedID();
	void uploadContactsFromTextFile();
	void createContact();
	void print(Contact contact);
	void showAllContacts();
	void clearVector();

};

#endif

