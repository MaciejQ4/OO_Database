#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactTextFile.h"
#include "OtherFunctions.h"

class ContactManager
{
	const int LOGGED_ID = 0;
	vector<Contact> contacts;

	Contact gatherCredentialsOfNewContact();

	ContactTextFile contactsTextFile;

public:

	ContactManager(string contactsTextFileName, int loggedID)
	 : contactsTextFile (contactsTextFileName), LOGGED_ID(loggedID) 
	{
		contacts = contactsTextFile.uploadContactsFromTextFile(loggedID);
	};
	
	void setLoggedID(int id);
	int getLoggedID();
	void uploadContactsFromTextFile();
	void createContact();
	void print(Contact contact);
	void searchAndShowByName();
	void searchAndShowBySurname();
	void showAllContacts();
	void deleteContact();
	void editContact();
	void clearVector();

};

#endif

