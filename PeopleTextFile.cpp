#include "PeopleTextFile.h"

int PeopleTextFile::getIDofLastPerson() {

    return IDofLastPerson;
}

void PeopleTextFile::appendPersonToTextFile(Person person) {

    peopleTextFile.open(getFileName().c_str(), ios::in | ios::app);

    if (peopleTextFile.good() == true) {

        string line = "";
        line = createLineOfData(person);
        
        if (isFileEmpty()) peopleTextFile << line;
        else               peopleTextFile << endl << line;

        peopleTextFile.close();
        IDofLastPerson++;
    }
    else cout << "Failed to append person to textfile";
}

vector<Person> PeopleTextFile::uploadPeopleFromTextFile(int loggedID) {
                            
    vector<Person> people;
    peopleTextFile.open(getFileName(), ios::in | ios::app);

    if (!peopleTextFile.good()) {
        cout << "Failed to upload people from file";
        exit(0);
    }

    string line;
    while (getline(peopleTextFile, line)) {

        string str = line;
        string parts[7];

        stringstream ss(str);

        int i = 0;
        while (ss.good() && i < 7) {
            string substr;
            getline(ss, substr, '|');
            parts[i] = substr;
            i++;
        }
        i = 0;

        Person person;
        person.setID(atoi(parts[0].c_str()));
        person.setUserID(atoi(parts[1].c_str()));
        person.setName(parts[2]);
        person.setSurname(parts[3]);
        person.setPhone(parts[4]);
        person.setEmail(parts[5]);
        person.setAddress(parts[6]);

        if ((atoi(parts[0].c_str()) > IDofLastPerson)) IDofLastPerson = (atoi(parts[0].c_str()));
        
        if(person.getUserID() == loggedID)
        people.push_back(person);
    }
    peopleTextFile.close();
    return people;
} 

void PeopleTextFile::deletePersonFromTextfile(int deletionID) {

    peopleTextFile.open(getFileName().c_str(), ios::in | ios::app);
    
    if (!peopleTextFile.good()) {
        cout << "Failed to open textfile for deletion ";
        system("pause");
    }

    fstream peopleTextFile2;
    peopleTextFile2.open("contacts2.txt", ios::out | ios::trunc);
    if (!peopleTextFile2.good()) {
        cout << "Failed to open temporary textfile for deletion";
        system("pause");
    }

    string line;
    while (getline(peopleTextFile, line)) {

        string str = line;
        string parts[7];

        stringstream ss(str);

        int i = 0;
        while (ss.good() && i < 7) {
            string substr;
            getline(ss, substr, '|');
            parts[i] = substr;
            i++;
        }
        i = 0;

        if (parts[0] != to_string(deletionID)) {  //parts[0] is the ID/ if doesnt match, rewrite line //
            for (int j = 0; j < 7; j++) {
                peopleTextFile2 << parts[j] << "|";
            }
            peopleTextFile2 << endl;
        }
    }
    peopleTextFile.close();
    peopleTextFile2.close();

    string temporaryFile = "people2.txt";
    string destinationFile = getFileName();
    
    if (remove(destinationFile.c_str()) != 0) {
        cout << "Failed to delete people file after closing the file." << endl;
        system("pause");
    }

    if (rename(temporaryFile.c_str(), destinationFile.c_str()) != 0) {
        cout << "Failed to rename temporary file after closing the file." << endl;
        system("pause");
    }
}

void PeopleTextFile::editPersonInTextFile(Person person) {

    peopleTextFile.open(getFileName().c_str(), ios::in | ios::app);

    if (!peopleTextFile.good()) {
        cout << "Failed to open textfile for edition ";
        system("pause");
    }

    fstream peopleTextFile2;
    peopleTextFile2.open("contacts2.txt", ios::out | ios::trunc);

    if (!peopleTextFile2.good()) {
        cout << "Failed to open temporary textfile for edition";
        system("pause");
    }

    string line;
    while (getline(peopleTextFile, line)) {
        string str = line;
        string parts[7];

        stringstream ss(str);

        int i = 0;
        while (ss.good() && i < 7) {
            string substr;
            getline(ss, substr, '|');
            parts[i] = substr;
            i++;
        }
        i = 0;

        if (parts[0] != to_string(person.getID()))    //// if doenst match, rewrite line 
            peopleTextFile2 << line << endl;

        if (parts[0] == to_string(person.getID())) {

            peopleTextFile2 << person.getID()      << "|";
            peopleTextFile2 << person.getUserID()  << "|";
            peopleTextFile2 << person.getName()    << "|";
            peopleTextFile2 << person.getSurname() << "|";
            peopleTextFile2 << person.getPhone()   << "|";
            peopleTextFile2 << person.getEmail()   << "|";
            peopleTextFile2 << person.getAddress() << "|" << endl;
        }
    }
    peopleTextFile.close();
    peopleTextFile2.close();

    string temporaryFile = "people2.txt";
    string destinationFile = getFileName();

    if (remove(destinationFile.c_str()) != 0) {
        cout << "Failed to edit contact file after closing the file. ";
        system("pause");
    }

    if (rename(temporaryFile.c_str(), destinationFile.c_str()) != 0) {
        cout << "Failed to rename temporary file after closing the file in edit function. ";
        system("pause");
    }

    cout << "Credentials edited successfully. ";
    system("pause");
}

string PeopleTextFile::createLineOfData(Person person) {

    string line = "";
    line += to_string(person.getID())     + "|";
    line += to_string(person.getUserID()) + "|";
    line += person.getName()              + "|";
    line += person.getSurname()           + "|";
    line += person.getPhone()             + "|";
    line += person.getEmail()             + "|";
    line += person.getAddress()           + "|";
    return line;
}