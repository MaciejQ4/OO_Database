//#pragma once
#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"

class UsersTextFile
{
	const string USERS_TEXTFILE_NAME;
	fstream usersTextFile;

	bool isUserFileEmpty();

public:

	UsersTextFile(string NAMEOFTEXTFILE) : USERS_TEXTFILE_NAME(NAMEOFTEXTFILE) {};
	vector<User> uploadUsersFromTextFile();
	string createLineOfData(User user);
	void appendUserToFile(User user);
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);

};

#endif