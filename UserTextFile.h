//#pragma once
#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"
#include "Textfile.h"

class UsersTextFile : public Textfile
{
//	const string USERS_TEXTFILE_NAME;
	fstream usersTextFile;

	bool isUserFileEmpty();

public:

	UsersTextFile(string nameOfTextFile) : Textfile(nameOfTextFile) {};

	vector<User> uploadUsersFromTextFile();
	string createLineOfData(User user);
	void appendUserToFile(User user);
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);

};

#endif