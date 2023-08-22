#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Contact.h"
#include "Textfile.h"

class ContactTextFile : protected Textfile
{
public:
	ContactTextFile(string contactsTextFileName) : Textfile(contactsTextFileName) {
		IDofLastContact = 0;
	};

	int getIDofLastContact();
	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	void deleteContactFromTextfile(int deletionID);
	void editContactInTextFile(Contact contact);

private:

	int IDofLastContact;
	fstream contactsTextFile;

	string createLineOfData(Contact contact);
};

#endif
