#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "UserManager.h"
#include "ContactManager.h"

class Database
{
	UserManager userManager;
	ContactManager *contactManager;
	const string NAME_OF_CONTACT_TEXTFILE;

public:

	Database(string userFileName, string contactsFileName):
		userManager(userFileName), NAME_OF_CONTACT_TEXTFILE(contactsFileName)
	{
		contactManager = NULL;
	};

	~Database()
	{
		delete contactManager;
		contactManager = NULL;
	}

	bool isUserLogged();
	void createUser();
	void loginUser();
	void showAllUsers();

	void createContact();
	void showAllContacts();
	void changePassword();
	void logOut();
	

};

#endif
