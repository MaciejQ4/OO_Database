//#pragma once
#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"

class UserTextFile
{
	const string userFileName = "users.txt"; // VISUAL MI NA TO POZWALA A NA KONSTRUKTOR TYPU ARTURA JUZ NIE
	fstream userFile;

	bool isUserFileEmpty();

public:

	vector<User> uploadUsersFromTextFile();
	string createLineOfData(User user);
	void appendUserToFile(User user);
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);

};

#endif