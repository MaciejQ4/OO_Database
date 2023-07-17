#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Contact
{
	int id, userid;
	string name, surname, phone, email, address;

public:

	void setContactID(int newID);
	void setUserIDofContact(int loggedID);
	void setContactName(string newname);
	void setContactSurname(string newsurname);
	void setContactPhone(string newphone);
	void setContactEmail(string newemail);
	void setContactAddress(string newaddress);

	int getContactID();
	int getUserIDofContact();
	string getContactName();
	string getContactSurname();
	string getContactPhone();
	string getContactEmail();
	string getContactAddress();
};

#endif
