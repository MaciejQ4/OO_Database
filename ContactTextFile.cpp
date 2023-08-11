#include "ContactTextFile.h"


bool ContactTextFile::isContactsTextFileEmpty() {

    contactsTextFile.seekg(0, ios::end);
    if (contactsTextFile.tellg() == 0)
        return true;
    else
        return false;
}

string ContactTextFile::createLineOfData(Contact contact) {

    string line = "";
    line += to_string(contact.getContactID()) + "|";
    line += to_string(contact.getUserIDofContact()) + "|";
    line += contact.getContactName() + "|";
    line += contact.getContactSurname() + "|";
    line += contact.getContactPhone() + "|";
    line += contact.getContactEmail() + "|";
    line += contact.getContactAddress() + "|";
    return line;
}

void ContactTextFile::appendContactToTextFile(Contact contact) {

    
    contactsTextFile.open(contactsTextFileName.c_str(), ios::in | ios::app);

    if (contactsTextFile.good() == true) {

        string line = "";
        line = createLineOfData(contact);
        
        if (isContactsTextFileEmpty()) contactsTextFile << line;
        else                           contactsTextFile << endl << line;

        contactsTextFile.close();
        IDofLastContact++;
    }
    else cout << "failed";
}


vector<Contact> ContactTextFile::uploadContactsFromTextFile(int loggedID) {
                            
    vector<Contact> contacts;
    contactsTextFile.open(contactsTextFileName, ios::in | ios::app);

    if (!contactsTextFile.good()) {
        cout << "failed"; exit(0);
    }

    string line;
    while (getline(contactsTextFile, line)) {

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

        Contact contact;
        contact.setContactID(atoi(parts[0].c_str()));
        contact.setUserIDofContact(atoi(parts[1].c_str()));
        contact.setContactName(parts[2]);
        contact.setContactSurname(parts[3]);
        contact.setContactPhone(parts[4]);
        contact.setContactEmail(parts[5]);
        contact.setContactAddress(parts[6]);

        if ((atoi(parts[0].c_str()) > IDofLastContact)) IDofLastContact = (atoi(parts[0].c_str()));
        
        if(contact.getUserIDofContact() == loggedID)
        contacts.push_back(contact);
    }
    contactsTextFile.close();
    return contacts;
} 

int ContactTextFile::getIDofLastContact() {

    return IDofLastContact;
}

void ContactTextFile::deleteContactFromTextfile(int deletionID) {


    fstream contactsFile;
    contactsFile.open("contacts.txt", ios::in || ios::app);
    if (!contactsFile.good()) {
        cout << "failed. delete contact funtion"; system("pause");
    }

    fstream contactsFile2;
    contactsFile2.open("contacts2.txt", ios::out | ios::trunc);
    if (!contactsFile2.good()) {
        cout << "failed. delte contact funtion. creating second file"; system("pause");
    }

    string line;
    while (getline(contactsFile, line)) {

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

        if (parts[0] != to_string(deletionID)) {           //// if doenst match, rewrite line // if entered id doesnt match 
            for (int i = 0; i < 7; i++) {
                contactsFile2 << parts[i] << "|";
            }
            contactsFile2 << endl;
        }
    }

    contactsFile.close();
    contactsFile2.close();

    if (remove("contacts2.txt") != 0) {
        cout << "Failed to delete contacts file. deleteContact function." << endl; system("pause");
    }

    if (rename("contacts2.txt", "contacts.txt") != 0) {
        cout << "Failed to rename temporary file. deleteContact function." << endl; system("pause");
    }

    cout << "Contact deleted successfully." << endl;
    system("pause");

}
