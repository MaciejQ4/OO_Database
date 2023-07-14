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

void Database::loginUser() {

	userManager.loginUser();
	int id = userManager.getLoggedID();
	contactManager.setLoggedID(id);
	contactManager.uploadContactsFromTextFile(id);
}

void Database::setLoggedID(int id) {

	userManager.setLoggedID(id);
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

void Database::createContact() {

	contactManager.createContact();
}

void Database::showAllContacts() {

	contactManager.showAllContacts();

}
