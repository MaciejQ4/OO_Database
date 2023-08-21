#include "ContactManager.h"

Contact ContactManager::gatherCredentialsOfNewContact() {

    Contact contact;
    contact.setContactID(contactsTextFile.getIDofLastContact() + 1);
    contact.setUserIDofContact(LOGGED_ID);
    
    cout << "Enter name: " << endl;
    string name = OtherFunctions::readLine();
    name = OtherFunctions::uppercase(name);
    contact.setContactName(name);

    cout << "Enter surname: " << endl;
    string surname = OtherFunctions::readLine();
    surname = OtherFunctions::uppercase(surname);
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

void ContactManager::searchAndShowByName() {

    if (contacts.size() == 0) {
        cout << "You have no contacts in your account. "; system("pause"); return;
    }
    cout << "Enter name: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    cout << "Contacts containing the name " << keyword << ":" << endl << endl;
    for (Contact contact : contacts) {
        if (keyword == contact.getContactName())
            print(contact);
    }
    system("pause");
}

void ContactManager::searchAndShowBySurname() {

    if (contacts.size() == 0) {
        cout << "You have no contacts in your account. "; system("pause"); return;
    }
    cout << "Enter surname: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    cout << "Contacts containing the surname " << keyword << ":" << endl << endl;
    for (Contact contact : contacts) {
        if (keyword == contact.getContactSurname())
            print(contact);
    }
    system("pause");
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
                else ++itr; 
            }
            contactsTextFile.deleteContactFromTextfile(deletionID);
        }
        else cout << "Failed to delete contact.";
    }
}

void ContactManager::editContact() {

    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }
    
    for (Contact contact : contacts)
        print(contact);
    
    cout << "Edit contact with which ID?";
    int editionID = stoi(OtherFunctions::readLine());
 
    cout << "Edit which paremeter?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Surname" << endl;
    cout << "3. Phone" << endl;
    cout << "4. Email" << endl;
    cout << "5. Address" << endl;
    char choice = OtherFunctions::readChar();

    for (Contact& contact : contacts) {

        if (contact.getContactID() == editionID) {

            cout << "Enter the new value: ";
            string newValue = OtherFunctions::readLine();
            newValue = OtherFunctions::uppercase(newValue);

            switch (choice) {
            case '1': contact.setContactName(newValue);         break;
            case '2': contact.setContactSurname(newValue);      break;
            case '3': contact.setContactPhone(newValue);        break;
            case '4': contact.setContactEmail(newValue);        break;
            case '5': contact.setContactAddress(newValue);      break;
            default: cout << "invalid input"; system("pause");  break;
            }
            contactsTextFile.editContactInTextFile(contact);
        }
    }                                                           
}

void ContactManager::print(Contact contact) {

    cout << contact.getContactID() << "|";
    cout << contact.getContactName() << "|";
    cout << contact.getContactSurname() << "|";
    cout << contact.getContactPhone() << "|";
    cout << contact.getContactEmail() << "|";
    cout << contact.getContactAddress() << "|" << endl;
}