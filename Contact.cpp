#include "Contact.h"

void Contact::setContactID(int newID) {

	if (newID >= 0)
		id = newID;
}

void Contact::setUserIDofContact(int loggedID) {

	userid = loggedID;
}

void Contact::setContactName(string newname) {

	name = newname;
}

void Contact::setContactSurname(string newsurname) {

	surname = newsurname;
}

void Contact::setContactPhone(string newphone) {

	phone = newphone;
}

void Contact::setContactEmail(string newemail) {

	email = newemail;
}

void Contact::setContactAddress(string newaddress) {

	address = newaddress;
}

////////////////////////////////////////////////////////////////////

int Contact::getContactID() {

	return id;
}

int Contact::getUserIDofContact() {

	return userid;
}

string Contact::getContactName() {

	return name;
}

string Contact::getContactSurname() {

	return surname;
}

string Contact::getContactPhone() {

	return phone;
}

string Contact::getContactEmail() {

	return email;
}

string Contact::getContactAddress() {

	return address;
}
