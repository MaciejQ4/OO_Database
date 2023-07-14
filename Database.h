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

	void createUser();
	void showAllUsers();
	void loginUser();
	void setLoggedID(int id);

	bool isUserLogged();
	void logOut();
	void createContact();
	//void changePassword();
	void showAllContacts();

};

#endif
