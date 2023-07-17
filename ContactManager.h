#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactTextFile.h"

class ContactManager
{
	int loggedID;
	vector<Contact> contacts;

	Contact gatherCredentialsOfNewContact();

	ContactTextFile contactsTextFile;
	

public:
	 
	void setLoggedID(int id);
	int getLoggedID();
	void uploadContactsFromTextFile(int id);
	void createContact();
	int assignNewIDtoContact();
	void showAllContacts();

};

#endif

