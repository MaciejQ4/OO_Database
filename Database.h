#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "UserManager.h"
#include "ContactManager.h"

class Database
{
	UserManager userManager;
	ContactManager contactManager;

public:

	Database(string userFileName, string contactsFileName):
		userManager(userFileName), contactManager(contactsFileName)	
	{};

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
