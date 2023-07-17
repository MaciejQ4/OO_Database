#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class User
{
	int id;
	string login;
	string password;

public:	

	void setUserID(int newID);
	void setUserLogin(string newlogin);
	void setUserPassword(string newPassword);

	int getUserID();
	string getUserLogin();
	string getUserPassword();

};

#endif