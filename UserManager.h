#pragma once

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UserTextFile.h"

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

class UserManager
{
	int userID;

	vector <User> users;

	User gatherCredentialsOfNewUser();
	int assignIDtoNewUser();
	bool doesLoginExist(string login);

	UserTextFile userTextFile;

public:
	void createUser();
	void showAllUsers();
	void uploadUsersFromTextFile();
	int loginUser();
};

#endif
