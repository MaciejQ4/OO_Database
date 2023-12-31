#include "UserManager.h"
#include "OtherFunctions.h"

int UserManager::getLoggedID() {

    return loggedID;
}

void UserManager::setLoggedID(int id) {

    loggedID = id;
}

bool UserManager::isUserLogged() {

    if (loggedID > 0) return true;
    else return false;
}

void UserManager::loginUser() {
    
    system("cls");
    cout << "Enter Login:" << endl;
    string login = OtherFunctions::readLine();
    cout << "Enter Password:" << endl;
    string password = OtherFunctions::readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login && users[i].getUserPassword() == password) {
            cout << login << " logged in with ID: " << users[i].getUserID() << endl;
            system("pause");
            int id = users[i].getUserID();
            setLoggedID(id);
            return;
        }
    }
    cout << "No such user with this password. "; system("pause"); return;
}

void UserManager::createUser() {

    system("cls");
    User user = gatherCredentialsOfNewUser();
    users.push_back(user);
    usersTextFile.appendUserToFile(user);
    cout << "User added succesfully. "; system("pause");
}

void UserManager::showAllUsers() {

    if (users.empty()) { cout << "No users yet. "; system("pause"); }

    else {
        system("cls");
        cout << "Active users accounts: " << endl << endl;
        for (size_t i = 0; i < users.size(); i++) {
            cout << users[i].getUserID() << "|";
            cout << users[i].getUserLogin() << "|";
            cout << users[i].getUserPassword() << "|" << endl;
        }
        cout << endl; system("pause");
    }
}

void UserManager::changePassword() {

    system("cls");
    cout << "Enter new password: " << endl;
    string newPassword  = OtherFunctions::readLine();
  
    for (User& user: users) {

        if (user.getUserID() == loggedID) {
            user.setUserPassword(newPassword);
            usersTextFile.replaceChangedPasswordInTextFile(loggedID, newPassword, user);
            break;
        }
    }
    cout << "Password changed succesfully. "; system("pause");
}

void UserManager::logOut() {

    loggedID = 0;
}

User UserManager::gatherCredentialsOfNewUser() {

    string login = "";
    bool flag = true;
    do {
        system("cls");
        cout << "Enter Login: " << endl;
        login = OtherFunctions::readLine();
        if (doesLoginExist(login)) {
            cout << "Login already exists. Please choose a diffrent login. "; system("pause");
        }
        else flag = false;

    } while (flag);

    User user;
    user.setUserID(assignIDtoNewUser());
    user.setUserLogin(login);

    cout << "Enter Password: " << endl;
    string password = OtherFunctions::readLine();
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