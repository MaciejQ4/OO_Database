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
	ContactTextFile(string NAME_OF_CONTACTS_TEXTFILE) : contactsTextFileName(NAME_OF_CONTACTS_TEXTFILE) {
		IDofLastContact = 0;
	};
	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	int getIDofLastContact();
	void deleteContactFromTextfile(int deletionID);
};

#endif
