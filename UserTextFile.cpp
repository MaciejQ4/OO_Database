#include "UserTextFile.h"


bool UsersTextFile::isUserFileEmpty() {

    usersTextFile.seekg(0, ios::end);
    if (usersTextFile.tellg() == 0)
        return true;
    else
        return false;
}

vector<User> UsersTextFile::uploadUsersFromTextFile() {

    vector<User> users;
    usersTextFile.open(usersTextFileName, ios::in | ios::app);

    if (!usersTextFile.good()) {
        cout << "failed"; exit(0);
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

    usersTextFile.open(usersTextFileName.c_str(), ios::in | ios::app);

    if (usersTextFile.good() == true) {
        string lineOfData = "";
        lineOfData = createLineOfData(user);

        if (isUserFileEmpty()) usersTextFile << lineOfData;
        else                   usersTextFile << endl << lineOfData;
        
        usersTextFile.close();
    }
    else cout << "failed";
}


void UsersTextFile::replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user) {

    const string tempFileName = "temp_users.txt";
    fstream tempFile(tempFileName, ios::out);

    if (!tempFile.good()) {
        cout << "Failed to create temporary file" << endl;
        system("pause");
        return;
    }

    usersTextFile.open(usersTextFileName, ios::in);

    if (!usersTextFile.good()) {
        cout << "Failed to open file" << endl;
        system("pause");
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
            // Update the password in the line
            line = parts[0] + "|" + parts[1] + "|" + newPassword + "|";
        }
        tempFile << line << endl;
    }

    usersTextFile.close();
    tempFile.close();

    // Remove the original file
    remove(usersTextFileName.c_str());
    // Rename the temporary file to the original file name
    rename(tempFileName.c_str(), usersTextFileName.c_str());

}