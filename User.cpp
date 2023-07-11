#include "User.h"

void User::setUserID(int newID) {
	
	if(newID >= 0)
	id = newID;
}

void User::setUserLogin(string newLogin ) {

	login = newLogin;
}

void User::setUserPassword(string newPassword) {

	password = newPassword;
}

int User::getUserID() {

	return id;
}

string User::getUserLogin() {

	return login;
}

string User::getUserPassword() {

	return password;
}