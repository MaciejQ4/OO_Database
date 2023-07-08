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
	string userFileName = "users.txt";
	fstream userFile;

	bool isUserFileEmpty();

public:

	void appendUserToFile(User user);
	vector<User> uploadUsersFromTextFile();

};

#endif