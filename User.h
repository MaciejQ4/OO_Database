#pragma once

#ifndef USER_H
#define USER_H

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

class User
{
	int id;
	string login;
	string password;

public:	

	void setUserID (int newID);
	void setUserLogin (string newlogin);
	void setUserPassword(string newPassword);

	int getUserID();
	string getUserLogin();
	string getUserPassword();

};

#endif