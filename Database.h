#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "UserManager.h"
#include "ContactManager.h"

class Database
{
public:

	Database(string usersTextFileName, string contactsTextFileName):
		userManager(usersTextFileName), NAME_OF_CONTACT_TEXTFILE(contactsTextFileName)

	{	contactManager = NULL; };

	~Database()
	{	delete contactManager;
		contactManager = NULL; }

	bool isUserLogged();
	void createUser();
	void loginUser();
	void showAllUsers();
	void createContact();
	void searchAndShowByName();
	void searchAndShowBySurname();
	void showAllContacts();
	void deleteContact();
	void editContact();
	void changePassword();
	void logOut();

private:

	UserManager userManager;
	ContactManager* contactManager;
	const string NAME_OF_CONTACT_TEXTFILE;
		
};

#endif
