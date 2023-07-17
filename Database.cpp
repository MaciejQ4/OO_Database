#include "Database.h"


Database::Database() {
	
	userManager.uploadUsersFromTextFile();
}

bool Database::isUserLogged() {

	return userManager.isUserLogged();
}


void Database::createUser(){

	userManager.createUser();
}


void Database::loginUser() {

	userManager.loginUser();
	int id = userManager.getLoggedID();
	contactManager.setLoggedID(id);
	contactManager.uploadContactsFromTextFile(id);
}


void Database::showAllUsers() {

	userManager.showAllUsers();
}

void Database::setLoggedID(int id) {

	userManager.setLoggedID(id);
}


void Database::createContact() {

	contactManager.createContact();
}


void Database::showAllContacts() {

	contactManager.showAllContacts();
}


void Database::changePassword() {

	userManager.changePassword();
}


void Database::logOut() {

	userManager.logOut();
}
