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

	Database(string userFileName) : userManager(userFileName) {
		userManager.uploadUsersFromTextFile();
	};

	bool isUserLogged();
	void createUser();
	void loginUser();
	void showAllUsers();
	void setLoggedID(int id);


	void createContact();
	void showAllContacts();
	void changePassword();
	void logOut();

};

#endif
