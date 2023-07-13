#include "User.h"
#include "Database.h"

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

bool Database::isUserLogged() {
	
	return userManager.isUserLogged();
}

//void Database::changePassword() {
//
//	userManager.changePassword();
//}

void Database::logOut() {

	userManager.logOut();
}

void Database::createContact(int loggedID) {

	contactManager.createContact(loggedID);
}

void Database::showAllContacts(int loggedID) {

	contactManager.showAllContacts(loggedID);

}
