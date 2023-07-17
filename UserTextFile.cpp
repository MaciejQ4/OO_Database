#include "UserTextFile.h"


bool UserTextFile::isUserFileEmpty() {

    userFile.seekg(0, ios::end);
    if (userFile.tellg() == 0)
        return true;
    else
        return false;
}

vector<User> UserTextFile::uploadUsersFromTextFile() {

    vector<User> users;
    userFile.open(userFileName, ios::in | ios::app);

    if (!userFile.good()) {
        cout << "failed"; exit(0);
    }

    string line;
    while (getline(userFile, line)) {

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
    userFile.close();
    return users;
}

string UserTextFile::createLineOfData(User user) {

    string line = "";
    line += to_string(user.getUserID()) + "|";
    line += user.getUserLogin() + "|";
    line += user.getUserPassword() + "|";
    return line;
}


void UserTextFile::appendUserToFile(User user) {

    userFile.open(userFileName.c_str(), ios::in | ios::app);

    if (userFile.good() == true) {
        string lineOfData = "";
        lineOfData = createLineOfData(user);

        if (isUserFileEmpty()) userFile << lineOfData;
        else                 userFile << endl << lineOfData;
        
        userFile.close();
    }
    else cout << "failed";
}


void UserTextFile::replaceChangedPasswordInTextFile(int loggedID, string newPassword, User user) {

    const string tempFileName = "temp_users.txt";
    fstream tempFile(tempFileName, ios::out);

    if (!tempFile.good()) {
        cout << "Failed to create temporary file" << endl;
        system("pause");
        return;
    }

    userFile.open(userFileName, ios::in);

    if (!userFile.good()) {
        cout << "Failed to open file" << endl;
        system("pause");
        return;
    }

    string line;
    while (getline(userFile, line)) {
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

    userFile.close();
    tempFile.close();

    // Remove the original file
    remove(userFileName.c_str());
    // Rename the temporary file to the original file name
    rename(tempFileName.c_str(), userFileName.c_str());

}