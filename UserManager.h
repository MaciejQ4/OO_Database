#pragma once

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UserTextFile.h"

class UserManager
{
private:

	int loggedID = 0;

	vector <User> users;
	UsersTextFile usersTextFile;

	User gatherCredentialsOfNewUser();
	int assignIDtoNewUser();
	bool doesLoginExist(string login);

public:

	UserManager(string usersTextFileName) : usersTextFile (usersTextFileName) 
	{ 
		users = usersTextFile.uploadUsersFromTextFile();
	};

	int getLoggedID();
	void setLoggedID(int id);
	bool isUserLogged();
	
	void loginUser();
	void createUser();
	void showAllUsers();

	void changePassword();
	void logOut();
};

#endif
