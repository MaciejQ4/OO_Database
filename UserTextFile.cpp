#include "UserTextFile.h"

vector<User> UsersTextFile::uploadUsersFromTextFile() {

    vector<User> users;
    usersTextFile.open(getFileName(), ios::in | ios::app);

    if (!usersTextFile.good()) {
        cout << "Failed to open file for uploading users. ";
        system("pause");
    }

    string line;
    while (getline(usersTextFile, line)) {

        string str = line;
        string parts[3];

        stringstream ss(str);

        int i = 0;
        while (ss.good() && i < 3) {
            string substr;
            getline(ss, substr, '|');
            parts[i] = substr;
            i++;
        }
        i = 0;

        User user;
        user.setUserID(atoi(parts[0].c_str()));
        user.setUserLogin(parts[1]);
        user.setUserPassword(parts[2]);

        users.push_back(user);
    }
    usersTextFile.close();
    return users;
}

string UsersTextFile::createLineOfData(User user) {

    string line = "";
    line += to_string(user.getUserID()) + "|";
    line += user.getUserLogin() + "|";
    line += user.getUserPassword() + "|";
    return line;
}

void UsersTextFile::appendUserToFile(User user) {

    usersTextFile.open(getFileName().c_str(), ios::in | ios::app);

    if (usersTextFile.good() == true) {
        string lineOfData = "";
        lineOfData = createLineOfData(user);

        if (isFileEmpty()) usersTextFile << lineOfData;
        else               usersTextFile << endl << lineOfData;
        
        usersTextFile.close();
    }
    else { cout << "Failed to append user to file. "; system("pause"); }
}

void UsersTextFile::replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user) {

    const string tempFileName = "temp_users.txt";
    fstream tempFile(tempFileName, ios::out);

    if (!tempFile.good()) {
        cout << "Failed to create temporary file to change user password. "; system("pause");
        return;
    }

    usersTextFile.open(getFileName(), ios::in);

    if (!usersTextFile.good()) {
        cout << "Failed to create temporary file to change user password. "; system("pause");
        return;
    }

    string line;
    while (getline(usersTextFile, line)) {
        string str = line;
        string parts[3];

        stringstream ss(str);

        int i = 0;
        while (ss.good() && i < 3) {
            string substr;
            getline(ss, substr, '|');
            parts[i] = substr;
            i++;
        }
        i = 0;

        if (parts[0] == to_string(loggedID)) {
            
            line = parts[0] + "|" + parts[1] + "|" + newPassword + "|";
        }
        tempFile << line << endl;
    }

    usersTextFile.close();
    tempFile.close();

    remove(getFileName().c_str());
  
    if (rename(tempFileName.c_str(), getFileName().c_str()) != 0) {
 
        cout << "Failed to rename temporary file to original filename. "; system("pause");
    }
}