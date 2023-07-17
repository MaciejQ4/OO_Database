#pragma once

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UserTextFile.h"


class UserManager
{
	int loggedID;

	vector <User> users;
	UserTextFile userTextFile;

	User gatherCredentialsOfNewUser();
	int assignIDtoNewUser();
	bool doesLoginExist(string login);
	

public:
	UserManager(string userFileName) : userTextFile (userFileName) {};

	void setLoggedID(int id);
	int getLoggedID();
	void uploadUsersFromTextFile();
	bool isUserLogged();
	void loginUser();
	void logOut();
	
	void createUser();
	void showAllUsers();
	void changePassword();

};

#endif
