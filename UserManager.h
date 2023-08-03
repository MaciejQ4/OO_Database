#pragma once

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UserTextFile.h"


class UserManager
{
	int loggedID = 0;

	vector <User> users;
	UsersTextFile usersTextFile;

	User gatherCredentialsOfNewUser();
	int assignIDtoNewUser();
	bool doesLoginExist(string login);
	

public:
	UserManager(string usersTextFileName) : usersTextFile (usersTextFileName) {
		users = usersTextFile.uploadUsersFromTextFile();
	};

	void setLoggedID(int id);
	int getLoggedID();

	bool isUserLogged();
	void loginUser();
	void logOut();
	
	void createUser();
	void showAllUsers();
	void changePassword();

};

#endif
