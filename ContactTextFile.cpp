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

/*int ContactTextFile::assignNewIDtoContact() {

    int maxContactID = 0;

    ifstream contactsTextFile(contactsTextFileName);

    if (!contactsTextFile.good()) {
        cout << "Failed to open contacts file. assignID function in creating contact" << endl;
        exit(0);
    }

    string line;
    while (getline(contactsTextFile, line)) {
        stringstream ss(line);
        string contactIDStr;

        getline(ss, contactIDStr, '|');

        int contactID = atoi(contactIDStr.c_str());
        if (contactID > maxContactID) {
            maxContactID = contactID;
        }
    }
    contactsTextFile.close();
    return maxContactID + 1;
}*/

int ContactTextFile::getIDofLastContact() {

    return IDofLastContact;
}