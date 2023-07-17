//#pragma once
#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"

class UsersTextFile
{
	const string usersTextFileName = "users.txt";
	fstream usersTextFile;

	bool isUserFileEmpty();

public:

	UsersTextFile(string NAMEOFTEXTFILE) : usersTextFileName(NAMEOFTEXTFILE) {};
	vector<User> uploadUsersFromTextFile();
	string createLineOfData(User user);
	void appendUserToFile(User user);
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);

};

#endif