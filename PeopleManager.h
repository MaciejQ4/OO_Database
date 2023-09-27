#pragma once

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "PeopleTextFile.h"
#include "OtherFunctions.h"

class PeopleManager
{
private:

	const int LOGGED_ID;
	vector<Person> people;
	PeopleTextFile peopleTextFile;

	Person gatherCredentialsOfNewPerson();
	bool doesIDexist(int id);

public:

	PeopleManager(string peopleTextFileName, int loggedID)
		: peopleTextFile(peopleTextFileName), LOGGED_ID(loggedID)

	{ 
		people = peopleTextFile.uploadPeopleFromTextFile(loggedID);
	};

	void addPerson();
	void print(Person person);
	void searchAndShowByName();
	void searchAndShowBySurname();
	void showAllPeople();
	void deletePerson();
	void editPerson();
};

#endif

