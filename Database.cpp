#include "Database.h"

bool Database::isUserLogged() {

	return userManager.isUserLogged();
}

void Database::createUser(){

	userManager.createUser();
}

void Database::loginUser() {

	userManager.loginUser();
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

void Database::searchAndShowByName() {

	contactManager->searchAndShowByName();
}

void Database::searchAndShowBySurname() {

	contactManager->searchAndShowBySurname();
}

void Database::showAllContacts() {

	contactManager->showAllContacts();
}

void Database::deleteContact() {

	contactManager->deleteContact();
}

void Database::editContact() {

	contactManager->editContact();
}

void Database::changePassword() {

	userManager.changePassword();
}

void Database::logOut() {

	userManager.logOut();
	delete contactManager;
	contactManager = NULL;
}
