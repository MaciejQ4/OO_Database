#include "Database.h"

bool Database::isUserLogged() {

	return userManager.isUserLogged();
}

void Database::createUser(){

	userManager.createUser();
}

void Database::loginUser() {

	userManager.loginUser();
	contactManager.setLoggedID(userManager.getLoggedID());
	contactManager.uploadContactsFromTextFile();
}

void Database::showAllUsers() {

	userManager.showAllUsers();
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
	contactManager.clearVector();
}
