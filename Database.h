#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "UserManager.h"
#include "PeopleManager.h"

class Database
{
private:

	UserManager userManager;
	PeopleManager* peopleManager;
	const string NAME_OF_PEOPLE_TEXTFILE;

public:

	Database(string usersTextFileName, string peopleTextFileName):
		userManager(usersTextFileName), NAME_OF_PEOPLE_TEXTFILE(peopleTextFileName)

	{	
		peopleManager = NULL;
	};

	~Database()
	{	
		delete peopleManager;
		peopleManager = NULL;
	}

	bool isUserLogged();
	void createUser();
	void loginUser();
	void showAllUsers();

	void addPerson();
	void searchAndShowByName();
	void searchAndShowBySurname();
	void showAllPeople();
	void deletePerson();
	void editPerson();

	void changePassword();
	void logOut();
};

#endif
