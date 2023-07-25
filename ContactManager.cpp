#include "OtherFunctions.h"
#include "ContactManager.h"


//OtherFunctions otherFunctions;

Contact ContactManager::gatherCredentialsOfNewContact() {

    Contact contact;
    contact.setContactID(assignNewIDtoContact());

    int id = getLoggedID();
    contact.setUserIDofContact(id);
    
    cout << "Enter name: " << endl;
    string name = OtherFunctions::readLine();
    contact.setContactName(name);

    cout << "Enter surname: " << endl;
    string surname = OtherFunctions::readLine();
    contact.setContactSurname(surname);

    cout << "Enter phone: " << endl;
    string phone = OtherFunctions::readLine();
    contact.setContactPhone(phone);

    cout << "Enter email: " << endl;
    string email = OtherFunctions::readLine();
    contact.setContactEmail(email);

    cout << "Enter address: " << endl;
    string address = OtherFunctions::readLine();
    contact.setContactAddress(address);

    return contact;
}

void ContactManager::setLoggedID(int id) {

    loggedID = id;
}

int ContactManager::getLoggedID() {

    return loggedID;
}

void ContactManager::uploadContactsFromTextFile(int id) {

    contacts = contactsTextFile.uploadContactsFromTextFile(id);
}

void ContactManager::createContact() {


    Contact contact = gatherCredentialsOfNewContact();
    contacts.push_back(contact);
    contactsTextFile.appendContactToTextFile(contact);
    cout << "User added succesfully. ";  system("pause");

}

int ContactManager::assignNewIDtoContact() {

    int newID = contactsTextFile.assignNewIDtoContact();
    return newID;
}

void ContactManager::showAllContacts() {

    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }

    else {
        for (int i = 0; i < contacts.size(); i++) {
            cout << contacts[i].getContactID() << "|";
            cout << contacts[i].getContactName() << "|";
            cout << contacts[i].getContactSurname() << "|";
            cout << contacts[i].getContactPhone() << "|";
            cout << contacts[i].getContactEmail() << "|";
            cout << contacts[i].getContactAddress() << "|" << endl;
        }
        system("pause");
    }
}

