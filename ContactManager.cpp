#include "ContactManager.h"


Contact ContactManager::gatherCredentialsOfNewContact() {

    Contact contact;
    contact.setContactID(contactsTextFile.getIDofLastContact() + 1);
    contact.setUserIDofContact(LOGGED_ID);
    
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

void ContactManager::uploadContactsFromTextFile() {

    contacts = contactsTextFile.uploadContactsFromTextFile(LOGGED_ID);
}

void ContactManager::createContact() {


    Contact contact = gatherCredentialsOfNewContact();
    contacts.push_back(contact);
    contactsTextFile.appendContactToTextFile(contact);
    cout << "User added succesfully. ";  system("pause");

}

void ContactManager::showAllContacts() {

    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }

    else {
        for (Contact contact : contacts)
            print(contact);
 
        system("pause");
    }
}

void ContactManager::clearVector() {

    contacts.clear();
    
}

void ContactManager::print(Contact contact) {

    cout << contact.getContactID() << "|";
    cout << contact.getContactName() << "|";
    cout << contact.getContactSurname() << "|";
    cout << contact.getContactPhone() << "|";
    cout << contact.getContactEmail() << "|";
    cout << contact.getContactAddress() << "|" << endl;
}