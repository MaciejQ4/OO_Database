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
		peopleManager = new PeopleManager(NAME_OF_PEOPLE_TEXTFILE, userManager.getLoggedID());
	}
}

void Database::showAllUsers() {

	userManager.showAllUsers();
}

void Database::addPerson() {

	peopleManager->addPerson();
}

void Database::searchAndShowByName() {

	peopleManager->searchAndShowByName();
}

void Database::searchAndShowBySurname() {

	peopleManager->searchAndShowBySurname();
}

void Database::showAllPeople() {

	peopleManager->showAllPeople();
}

void Database::deletePerson() {

	peopleManager->deletePerson();
}

void Database::editPerson() {

	peopleManager->editPerson();
}

void Database::changePassword() {

	userManager.changePassword();
}

void Database::logOut() {

	userManager.logOut();
	delete peopleManager;
	peopleManager = NULL;
}
