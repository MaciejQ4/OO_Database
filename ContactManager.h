#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactTextFile.h"
#include "OtherFunctions.h"

class ContactManager
{
private:

	const int LOGGED_ID;
	vector<Contact> contacts;
	ContactTextFile contactsTextFile;

	Contact gatherCredentialsOfNewContact();
	bool doesIDexist(int id);

public:

	ContactManager(string contactsTextFileName, int loggedID)
		: contactsTextFile(contactsTextFileName), LOGGED_ID(loggedID)

	{ contacts = contactsTextFile.uploadContactsFromTextFile(loggedID); };

	void createContact();
	void print(Contact contact);
	void searchAndShowByName();
	void searchAndShowBySurname();
	void showAllContacts();
	void deleteContact();
	void editContact();
};

#endif

