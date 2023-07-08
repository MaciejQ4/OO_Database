#include "UserTextFile.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool UserTextFile::isUserFileEmpty() {

    userFile.seekg(0, ios::end);
    if (userFile.tellg() == 0)
        return true;
    else
        return false;
}

void UserTextFile::appendUserToFile(User user) {

    userFile.open(userFileName.c_str(), ios::out | ios::app);

    if (userFile.good() == true) {

        userFile << user.getUserID() << "|";
        userFile << user.getUserLogin() << "|";
        userFile << user.getUserPassword() << "|" << endl;

        userFile.close();
    }
    else cout << "failed";
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