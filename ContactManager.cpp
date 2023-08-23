#include "ContactManager.h"

void ContactManager::createContact() {

    system("cls");
    Contact contact = gatherCredentialsOfNewContact();
    contacts.push_back(contact);
    contactsTextFile.appendContactToTextFile(contact);
    cout << "User added succesfully. ";  system("pause");
}

void ContactManager::print(Contact contact) {

    cout << contact.getContactID() << "|";
    cout << contact.getContactName() << "|";
    cout << contact.getContactSurname() << "|";
    cout << contact.getContactPhone() << "|";
    cout << contact.getContactEmail() << "|";
    cout << contact.getContactAddress() << "|" << endl;
}

void ContactManager::searchAndShowByName() {

    system("cls");
    if (contacts.size() == 0) {
        cout << "You have no contacts in your account. "; system("pause"); return;
    }
    cout << "Enter name: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    system("cls");
    cout << "Contacts containing the name " << keyword << ":" << endl << endl;
    for (Contact contact : contacts) {
        if (keyword == contact.getContactName())
            print(contact);
    }
    cout << endl; system("pause");
}

void ContactManager::searchAndShowBySurname() {

    system("cls");
    if (contacts.size() == 0) {
        cout << "You have no contacts in your account. "; system("pause"); return;
    }
    cout << "Enter surname: ";
    string keyword = OtherFunctions::readLine();
    keyword = OtherFunctions::uppercase(keyword);

    system("cls");
    cout << "Contacts containing the surname " << keyword << ":" << endl << endl;
    for (Contact contact : contacts) {
        if (keyword == contact.getContactSurname())
            print(contact);
    }
    cout << endl; system("pause");
}

void ContactManager::showAllContacts() {

    system("cls");
    if (contacts.empty()) { cout << "No contacts in your account. "; system("pause"); }

    else {
        cout << "Contacts in your account:" << endl << endl;
        for (Contact contact : contacts) {
            cout << "ID: " << contact.getContactID() << endl;
            cout << "Name: " << contact.getContactName() << endl;
            cout << "Surname: " << contact.getContactSurname() << endl;
            cout << "Phone: " << contact.getContactPhone() << endl;
            cout << "Email: " << contact.getContactEmail() << endl;
            cout << "Adress: " << contact.getContactAddress() << endl << endl;
        }
        cout << endl; system("pause");
    }
}

void ContactManager::deleteContact() {

    system("cls");
    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }

    else {
        cout << "Contacts in your account:" << endl << endl;
        for (Contact contact : contacts)
            print(contact);

        cout << endl << "Delete contact with which ID? ";
        string ID = OtherFunctions::readLine();
        int deletionID = stoi(ID);
        if (!doesIDexist(deletionID)) { cout << "No contact with intputed ID in this user's account. ";  system("pause"); return; }

        cout << "About to delete account with ID:" << ID << ". Press 'y' to confirm ";
        char confirm = OtherFunctions::readChar();

        if (confirm == 'y' || confirm == 'Y')
        {
            for (vector<Contact>::iterator itr = contacts.begin(); itr != contacts.end();) {

                if (itr->getContactID() == deletionID) {
                    itr = contacts.erase(itr);
                    contactsTextFile.deleteContactFromTextfile(deletionID);
                    cout << "Contact deleted successfully. "; system("pause"); return;
                }
                else itr++;
            }
        }
    }
}

void ContactManager::editContact() {

    system("cls");
    if (contacts.empty()) { cout << "No contacts yet. "; system("pause"); }
    
    cout << "Contacts in your account:" << endl << endl;
    for (Contact contact : contacts)
        print(contact);
    
    cout << endl << "Edit contact with which ID? ";
    int editionID = stoi(OtherFunctions::readLine());

    if (!doesIDexist(editionID)) { cout << "No contact with intputed ID in this user's account. ";  system("pause");  return; }
 
    system("cls");
    cout << "Edit which paremeter?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Surname" << endl;
    cout << "3. Phone" << endl;
    cout << "4. Email" << endl;
    cout << "5. Address" << endl;
    char choice = OtherFunctions::readChar();

    for (Contact& contact : contacts) {

        if (contact.getContactID() == editionID) {

            system("cls");
            cout << "Enter the new value: ";
            string newValue = OtherFunctions::readLine();

            switch (choice) {
            case '1':newValue = OtherFunctions::uppercase(newValue);
                     contact.setContactName(newValue);          break;

            case '2': newValue = OtherFunctions::uppercase(newValue);
                      contact.setContactSurname(newValue);      break;
            
            case '3': contact.setContactPhone(newValue);        break;
            case '4': contact.setContactEmail(newValue);        break;
            case '5': contact.setContactAddress(newValue);      break;
            default: cout << "invalid input"; system("pause");  break;
            }
            contactsTextFile.editContactInTextFile(contact);
        }
    }                                                           
}

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

bool ContactManager::doesIDexist(int id) {

    for (vector<Contact>::iterator itr = contacts.begin(); itr != contacts.end();) {

        if (itr->getContactID() == id) return true;
        else ++itr;
    }
    return false; 
}