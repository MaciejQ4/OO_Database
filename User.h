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
private:

	int id;
	string login;
	string password;

public:	

	User(int id = 0, string login = "", string password = "")
	{
		this->id = id;
		this->login = login;
		this->password = password;
	}

	int getUserID();
	string getUserLogin();
	string getUserPassword();

	void setUserID(int newID);
	void setUserLogin(string newlogin);
	void setUserPassword(string newPassword);
};

#endif