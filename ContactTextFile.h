#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Contact.h"
#include "Textfile.h"

class ContactTextFile : public Textfile
{
	int IDofLastContact;
	const string contactsTextFileName;
	fstream contactsTextFile;
	
	bool isContactsTextFileEmpty();
	string createLineOfData(Contact contact);

public:
	ContactTextFile(string NAME_OF_TEXTFILE) : contactsTextFileName(NAME_OF_TEXTFILE) {
		IDofLastContact = 0;
	};

	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	int getIDofLastContact();
	void deleteContactFromTextfile(int deletionID);
	void editContactInTextFile(Contact contact);
};

#endif
