#include "PeopleManager.h"

void PeopleManager::addPerson() {

    system("cls");
    Person person = gatherCredentialsOfNewPerson();
    people.push_back(person);
    peopleTextFile.appendPersonToTextFile(person);
    cout << "Person added succesfully. ";  
    system("pause");
}

void PeopleManager::print(Person person) {

    cout << person.getID()      << "|";
    cout << person.getName()    << "|";
    cout << person.getSurname() << "|";
    cout << person.getPhone()   << "|";
    cout << person.getEmail()   << "|";
    cout << person.getAddress() << "|" << endl;
}

void PeopleManager::searchAndShowByName() {

    system("cls");
    if (people.size() == 0) {
        cout << "You have no people in your account. ";
        system("pause");
        return;
    }

    cout << "Enter name: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    system("cls");
    cout << "People with the name " << keyword << ":" << endl << endl;
    for (Person person : people) {
        if (keyword == person.getName())
            print(person);
    }
    cout << endl; 
    system("pause");
}

void PeopleManager::searchAndShowBySurname() {

    system("cls");
    if (people.size() == 0) {
        cout << "You have no people in your account. ";
        system("pause");
        return;
    }
    cout << "Enter surname: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    system("cls");
    cout << "People with the surname " << keyword << ":" << endl << endl;
    for (Person person : people) {
        if (keyword == person.getSurname())
            print(person);
    }
    cout << endl;
    system("pause");
}

void PeopleManager::showAllPeople() {

    system("cls");

    if (people.empty()) {
        cout << "No people in your account. ";
        system("pause"); 
    }

    else {
        cout << "People in your account:"             << endl << endl;
        for (Person person : people) {
            cout << "ID: " << person.getID()                  << endl;
            cout << "Name: " << person.getName()              << endl;
            cout << "Surname: " << person.getSurname()        << endl;
            cout << "Phone: " << person.getPhone()            << endl;
            cout << "Email: " << person.getEmail()            << endl;
            cout << "Adress: " << person.getAddress() << endl << endl;
            cout << "------------------------"                << endl;
        }
        cout << endl;
        system("pause");
    }
}

void PeopleManager::deletePerson() {

    system("cls");

    if (people.empty()) { 
        cout << "No contacts yet. ";
        system("pause");
    }

    else {
        cout << "People in your account:" << endl << endl;
        for (Person person : people)
            print(person);

        cout << endl << "Delete person with which ID? ";
        string ID = OtherFunctions::readLine();
        int deletionID = stoi(ID);
        if (!doesIDexist(deletionID)) { 
            cout << "No person with intputed ID in this user's account. ";
            system("pause");
            return;
        }

        cout << "About to delete person with ID:" << ID << ". Press 'y' to confirm ";
        char confirm = OtherFunctions::readChar();

        if (confirm == 'y' || confirm == 'Y')
        {
            for (vector<Person>::iterator itr = people.begin(); itr != people.end();) {

                if (itr->getID() == deletionID) {
                    itr = people.erase(itr);
                    peopleTextFile.deletePersonFromTextfile(deletionID);
                    cout << "Person deleted successfully. ";
                    system("pause");
                    return;
                }
                else itr++;
            }
        }
    }
}

void PeopleManager::editPerson() {

    system("cls");
    if (people.empty()) {
        cout << "No People in your account yet. ";
        system("pause");
    }
    
    cout << "People in your account:" << endl << endl;

    for (Person person : people)
        print(person);
    
    cout << endl << "Edit person with which ID? ";
    int editionID = stoi(OtherFunctions::readLine());

    if (!doesIDexist(editionID)) {
        cout << "No person with intputed ID in this user's account. ";
        system("pause");
        return;
    }
 
    system("cls");
    cout << "Edit which paremeter?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Surname" << endl;
    cout << "3. Phone" << endl;
    cout << "4. Email" << endl;
    cout << "5. Address" << endl;
    char choice = OtherFunctions::readChar();

    for (Person& person : people) {

        if (person.getID() == editionID) {

            system("cls");
            cout << "Enter the new value: ";
            string newValue = OtherFunctions::readLine();

            switch (choice) {
            case '1': newValue = OtherFunctions::uppercase(newValue);
                      person.setName(newValue);                         break;

            case '2': newValue = OtherFunctions::uppercase(newValue);
                      person.setSurname(newValue);                      break;
            
            case '3': person.setPhone(newValue);                        break;
            case '4': person.setEmail(newValue);                        break;
            case '5': person.setAddress(newValue);                      break;

            default: cout << "Invalid input";
                     system("pause");                                   break;
            }
            peopleTextFile.editPersonInTextFile(person);
        }
    }                                                           
}

Person PeopleManager::gatherCredentialsOfNewPerson() {

    Person person;
    person.setID(peopleTextFile.getIDofLastPerson() + 1);
    person.setUserID(LOGGED_ID);

    cout << "Enter name: " << endl;
    string name = OtherFunctions::readLine();
    name = OtherFunctions::uppercase(name);
    person.setName(name);

    cout << "Enter surname: " << endl;
    string surname = OtherFunctions::readLine();
    surname = OtherFunctions::uppercase(surname);
    person.setSurname(surname);

    cout << "Enter phone: " << endl;
    string phone = OtherFunctions::readLine();
    person.setPhone(phone);

    cout << "Enter email: " << endl;
    string email = OtherFunctions::readLine();
    person.setEmail(email);

    cout << "Enter address: " << endl;
    string address = OtherFunctions::readLine();
    person.setAddress(address);

    return person;
}

bool PeopleManager::doesIDexist(int id) {

    for (vector<Person>::iterator itr = people.begin(); itr != people.end();) {

        if (itr->getID() == id) return true;
        else ++itr;
    }
    return false; 
}