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

	Contact(int id = 0, int userid = 0, string name = "", string surname = "", string phone = "", string email = "", string address = "")
	{
		this->id = id;
		this->userid = userid;
		this->name = name;
		this->surname = surname;
		this->phone = phone;
		this->email = email;
		this->address = address;

	}
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
