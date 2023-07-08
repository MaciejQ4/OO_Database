#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include "UserManager.h"

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

//class User;

class Database
{
	UserManager userManager;

public:

	void createUser();
	void showAllUsers();


};

#endif
