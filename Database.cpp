#include "User.h"
#include "Database.h"

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

Database::Database() {
    
    userFileName = "users.txt";
}

void Database::createUser(){

    User user = gatherCredentialsOfNewUser();
    users.push_back(user);
    appendUserToFile(user);

    cout << "User added succesfully" << endl;
    system("pause");

     
    }

User Database::gatherCredentialsOfNewUser() {

    User user;
    user.setUserID(assignIDtoNewUser());

    cout << "Enter login: " << endl;
    string login;
    cin >> login;
    user.setUserLogin(login);

    cout << "Enter password: " << endl;
    string password;
    cin >> password;
    user.setUserPassword(password);

    return user;
}

int Database::assignIDtoNewUser() {
    
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool Database::doesLoginExist(string login) {

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login)
            return true;
    }
    return false;
}

void Database::showAllUsers() {

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserID() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
    }
}

void Database::appendUserToFile(User user) {

    fstream userFile;
    userFile.open(userFileName.c_str(), ios::out | ios::app);

    if (userFile.good() == true) {

            userFile << user.getUserID() << "|";
            userFile << user.getUserLogin() << "|";
            userFile << user.getUserPassword() << "|" << endl;
       
        userFile.close();
    }

    else cout << "failed";
}


bool Database::isUserFileEmpty(fstream& userFile) {

    userFile.seekg(0, ios::end);
    if (userFile.tellg() == 0)
        return true;
    else
        return false;
}
