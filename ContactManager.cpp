#include "OtherFunctions.h"
#include "ContactManager.h"


//OtherFunctions otherFunctions;

Contact ContactManager::gatherCredentialsOfNewContact() {

    Contact contact;
    //contact.setContactID(assignNewIDtoContact());
    contact.setContactID(contactsTextFile.getIDofLastContact()+1);


    contact.setUserIDofContact(getLoggedID());
    
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

void ContactManager::uploadContactsFromTextFile() {

    contacts = contactsTextFile.uploadContactsFromTextFile(loggedID);
}

void ContactManager::createContact() {


    Contact contact = gatherCredentialsOfNewContact();
    contacts.push_back(contact);
    contactsTextFile.appendContactToTextFile(contact);
    cout << "User added succesfully. ";  system("pause");

}

//int ContactManager::assignNewIDtoContact() {
//
//    int newID = contactsTextFile.assignNewIDtoContact();
//    return newID;
//}

void ContactManager::showAllContacts() {

    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }

    else {
        for (Contact contact : contacts)
            otherFunctions.print(contact);
 
        system("pause");
    }
}

void ContactManager::clearVector() {

    contacts.clear();
}