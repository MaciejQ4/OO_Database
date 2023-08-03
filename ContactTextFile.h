#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Contact.h"

class ContactTextFile
{
	int IDofLastContact;
	const string contactsTextFileName;
	fstream contactsTextFile;

	bool isContactsTextFileEmpty();
	string createLineOfData(Contact contact);

public:
	ContactTextFile(string NAMEOFCONTACTSTEXTFILE) : contactsTextFileName(NAMEOFCONTACTSTEXTFILE) {
		IDofLastContact = 0;
	};
	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	int getIDofLastContact();
};

#endif
