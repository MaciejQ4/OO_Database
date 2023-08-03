#include "Database.h"

bool Database::isUserLogged() {

	return userManager.isUserLogged();
}

void Database::createUser(){

	userManager.createUser();
}

void Database::loginUser() {

	userManager.loginUser();
	//contactManager.setLoggedID(userManager.getLoggedID());
	//contactManager.uploadContactsFromTextFile();
	if (userManager.isUserLogged()) {
		contactManager = new ContactManager(NAME_OF_CONTACT_TEXTFILE, userManager.getLoggedID());
	}

}

void Database::showAllUsers() {

	userManager.showAllUsers();
}


void Database::createContact() {

	contactManager->createContact();
}

void Database::showAllContacts() {

	contactManager->showAllContacts();
}

void Database::changePassword() {

	userManager.changePassword();
}

void Database::logOut() {

	userManager.logOut();
	//contactManager->clearVector(); // tak u artura w 2sem
	delete contactManager;
	contactManager = NULL;


}
