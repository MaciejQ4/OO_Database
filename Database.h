#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include "UserManager.h"
#include "ContactManager.h"

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


class Database
{
	UserManager userManager;
	ContactManager contactManager;


public:

	Database();

	bool isUserLogged();
	void createUser();
	void loginUser();
	void showAllUsers();
	void setLoggedID(int id);


	void createContact();
	void showAllContacts();
	void changePassword();
	void logOut();

};

#endif
