#pragma once

#ifndef CONTACTSTEXTFILE_H
#define CONTACTSTEXTFILE_H

#include "Person.h"
#include "Textfile.h"

class PeopleTextFile : protected Textfile
{
private:

	int IDofLastPerson;
	fstream peopleTextFile;

	string createLineOfData(Person person);

public:

	PeopleTextFile(string peopleTextFileName) : Textfile(peopleTextFileName) 

	{
		IDofLastPerson = 0;
	};

	int getIDofLastPerson();
	void appendPersonToTextFile(Person person);
	vector<Person> uploadPeopleFromTextFile(int loggedID);
	void deletePersonFromTextfile(int deletionID);
	void editPersonInTextFile(Person person);
};

#endif
