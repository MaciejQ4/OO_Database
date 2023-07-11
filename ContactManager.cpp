#include "ContactManager.h"
#include "UserManager.h"

void ContactManager::Menu(int userID) {

    uploadContactsFromTextFile(userID);
    UserManager userManager; // <-TO MUSI BYC ZEBY MOC Z POZIOMU
                             // TEGO MENU ZMIENIC HASLO

    bool flag = true;
    while (flag) {

        system("cls");
        cout << " USER MENU " << endl << endl;
        cout << "1. Create an contact" << endl;
        //cout << "2. Search database by name" << endl;
        //cout << "3. Search database by surname" << endl;
        cout << "4. Show all contacts in database" << endl;
        //cout << "5. Delete a contact" << endl;
        //cout << "6. Edit a contact" << endl;
        cout << "7. Change password" << endl;
        cout << "8. Sign out" << endl << endl;
        cout << "9. Exit" << endl;

        char choice;
        cin >> choice;
        switch (choice) {

        case '1': createContact(userID);                  break;
        //case '2': searchAndShowByName(contacts);        break;
        //case '3': searchAndShowBySurname(contacts);     break;
        case '4': showAllContacts(userID);                break;
        //case '5': deleteContact(contacts, userID);      break;
        //case '6': editContact(contacts, userID);        break;
        case '7': userManager.changePassword(userID);     break;
        case '8': flag = false;                           break;
        case '9': exit(0);                                break;
        }
    }
}

void ContactManager::createContact(int userID) {

    Contact contact = gatherCredentialsOfNewContact();
    contacts.push_back(contact);

    contactsTextFile.appendContactToTextFile(contact, userID);

    cout << "User added succesfully. ";  system("pause");
}

Contact ContactManager::gatherCredentialsOfNewContact() {

    Contact contact;
    contact.setContactID(assignNewIDtoContact());

    cout << "Enter name: " << endl;
    string name;
    cin >> name;
    contact.setContactName(name);

    cout << "Enter surname: " << endl;
    string surname;
    cin >> surname;
    contact.setContactSurname(surname);

    cout << "Enter phone: " << endl;
    string phone;
    cin >> phone;
    contact.setContactPhone(phone);

    cout << "Enter email: " << endl;
    string email;
    cin >> email;
    contact.setContactEmail(email);

    cout << "Enter address: " << endl;
    string address;
    cin >> address;
    contact.setContactAddress(address);

    return contact;
}

void ContactManager::showAllContacts(int userID) {

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

int ContactManager::assignNewIDtoContact() {

    int newID = contactsTextFile.assignNewIDtoContact();
    return newID;
}

void ContactManager::uploadContactsFromTextFile(int userID) {

    contacts = contactsTextFile.uploadContactsFromTextFile(userID);

}


