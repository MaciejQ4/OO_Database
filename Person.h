#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Person
{
	int id, userid;
	string name, surname, phone, email, address;

public:

	Person(int id = 0, int userid = 0, string name = "", string surname = "", string phone = "", string email = "", string address = "")
	{
		this->id = id;
		this->userid = userid;
		this->name = name;
		this->surname = surname;
		this->phone = phone;
		this->email = email;
		this->address = address;

	}	
	
	int getID();
	int getUserID();
	string getName();
	string getSurname();
	string getPhone();
	string getEmail();
	string getAddress();

	void setID(int newID);
	void setUserID(int loggedID);
	void setName(string newname);
	void setSurname(string newsurname);
	void setPhone(string newphone);
	void setEmail(string newemail);
	void setAddress(string newaddress);

};

#endif
