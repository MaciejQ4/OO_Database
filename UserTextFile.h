//#pragma once
#ifndef USERTEXTFILE_H
#define USERTEXTFILE_H

#include "User.h"
#include "AuxillaryFuntions.h"


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class UserTextFile
{
	const string userFileName = "users.txt"; // VISUAL MI NA TO POZWALA A NA KONSTRUKTOR TYPU ARTURA JUZ NIE
	fstream userFile;

	bool isUserFileEmpty();

public:

	string createLineOfData(User user);
	void appendUserToFile(User user);
	vector<User> uploadUsersFromTextFile();
	void replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user);

};

#endif