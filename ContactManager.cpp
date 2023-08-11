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

void ContactManager::deleteContact() {

    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }

    else {
        for (Contact contact : contacts)
            print(contact);

        cout << "Delete contact with which ID?. ";
        string ID = OtherFunctions::readLine();
        int deletionID = stoi(ID);

        cout << "About to delete account with ID: " << ID << "press 'y' to confirm ";
        char confirm = OtherFunctions::readChar();
        
        if (deletionID <= contactsTextFile.getIDofLastContact() && confirm == 'y' || confirm == 'Y')
        {
 
            for (vector<Contact>::iterator itr = contacts.begin(); itr != contacts.end();) {
                if (itr->getContactID() == deletionID) {
                    itr = contacts.erase(itr);
                }
                else {
                    ++itr; 
                }
            }
            contactsTextFile.deleteContactFromTextfile(deletionID);
        }
        else cout << "Failed to delete contact.";
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