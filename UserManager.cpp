#include "UserManager.h"

void UserManager::createUser() {

    User user = gatherCredentialsOfNewUser();
    users.push_back(user);
    
    userTextFile.appendUserToFile(user);

    cout << "User added succesfully" << endl;
    system("pause");


}

User UserManager::gatherCredentialsOfNewUser() {

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

int UserManager::assignIDtoNewUser() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool UserManager::doesLoginExist(string login) {

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login)
            return true;
    }
    return false;
}

void UserManager::showAllUsers() {

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserID() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
    }
    system("pause");
}

void UserManager::uploadUsersFromTextFile() {

    users = userTextFile.uploadUsersFromTextFile();

}

int UserManager::loginUser() {

    string login, password;
    cout << "Enter login" << endl;
    cin >> login;
    cout << "Enter password" << endl;
    cin >> password;

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login && users[i].getUserPassword() == password) {
            cout << login << " logged in with ID" << users[i].getUserID() << endl;
            system("pause");
            return users[i].getUserID();
        }
    }
    return 0;
}