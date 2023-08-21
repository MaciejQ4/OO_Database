#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Contact.h"
#include "Textfile.h"

class ContactTextFile : public Textfile
{
	int IDofLastContact;

	fstream contactsTextFile;
	
	bool isContactsTextFileEmpty();
	string createLineOfData(Contact contact);

public:
	ContactTextFile(string nameOfTextFile) : Textfile(nameOfTextFile) {
		IDofLastContact = 0;
	};

	void appendContactToTextFile(Contact contact);
	vector<Contact> uploadContactsFromTextFile(int loggedID);
	int getIDofLastContact();
	void deleteContactFromTextfile(int deletionID);
	void editContactInTextFile(Contact contact);
};

#endif
