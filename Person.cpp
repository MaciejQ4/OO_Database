#include "Person.h"

void Person::setID(int newID) {

	if (newID >= 0)
		id = newID;
}

void Person::setUserID(int loggedID) {

	userid = loggedID;
}

void Person::setName(string newname) {

	name = newname;
}

void Person::setSurname(string newsurname) {

	surname = newsurname;
}

void Person::setPhone(string newphone) {

	phone = newphone;
}

void Person::setEmail(string newemail) {

	email = newemail;
}

void Person::setAddress(string newaddress) {

	address = newaddress;
}

//--------------------------------------------

int Person::getID() {

	return id;
}

int Person::getUserID() {

	return userid;
}

string Person::getName() {

	return name;
}

string Person::getSurname() {

	return surname;
}

string Person::getPhone() {

	return phone;
}

string Person::getEmail() {

	return email;
}

string Person::getAddress() {

	return address;
}
