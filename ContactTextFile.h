#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Contact.h"

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
