

#include "User.h"
#include "Database.h"

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

Database::Database() {
	
	userManager.uploadUsersFromTextFile();
}

void Database::createUser(){

	userManager.createUser();
}

void Database::showAllUsers(){

	userManager.showAllUsers();

}

int Database::loginUser() {

	return userManager.loginUser();
	
}



