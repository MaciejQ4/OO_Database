#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"
#include "Textfile.h"

class UsersTextFile : protected Textfile
{
private:

	fstream usersTextFile;

	bool isUserFileEmpty();

public:

	UsersTextFile(string usersTextFileName) : Textfile(usersTextFileName) {};

	vector<User> uploadUsersFromTextFile();
	string createLineOfData(User user);
	void appendUserToFile(User user);
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);
};

#endif