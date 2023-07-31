#include "UserManager.h"
#include "ContactManager.h"
#include "OtherFunctions.h"
OtherFunctions otherFunctions;

User UserManager::gatherCredentialsOfNewUser() {

    User user;
    user.setUserID(assignIDtoNewUser());

    cout << "Enter login: " << endl;
    string login = otherFunctions.readLine();
    user.setUserLogin(login);

    cout << "Enter password: " << endl;
    string password = otherFunctions.readLine();
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

void UserManager::setLoggedID(int id) {

    loggedID = id;
}

int UserManager::getLoggedID() {

    return loggedID;
}

void UserManager::uploadUsersFromTextFile() {

    users = usersTextFile.uploadUsersFromTextFile();

}

bool UserManager::isUserLogged() {

    if (loggedID > 0) return true;
    else return false;
}

void UserManager::loginUser() {

    
    cout << "Enter login" << endl;
    string login = otherFunctions.readLine();
    cout << "Enter password" << endl;
    string password = otherFunctions.readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login && users[i].getUserPassword() == password) {
            cout << login << " logged in with ID: " << users[i].getUserID() << endl;
            system("pause");
            int id = users[i].getUserID();
            setLoggedID(id);
            return;
        }
    }
    cout << "No such user. "; system("pause"); return;
}

void UserManager::logOut() {

    loggedID = 0;
    //contactManager.clearVector(); // jak to wyczyscic bez nowej instancji?
    //ContactManager::clearVector();
}


void UserManager::createUser() {

    User user = gatherCredentialsOfNewUser();
    users.push_back(user);

    usersTextFile.appendUserToFile(user);

    cout << "User added succesfully" << endl;
    system("pause");

}

void UserManager::showAllUsers() {

    uploadUsersFromTextFile();
    if (users.empty()) { cout << "No users yet. "; system("pause"); }

    else {
        for (int i = 0; i < users.size(); i++) {
            cout << users[i].getUserID() << "|";
            cout << users[i].getUserLogin() << "|";
            cout << users[i].getUserPassword() << "|" << endl;
        }
        system("pause");
    }
}


void UserManager::changePassword() {

    cout << "Enter new password" << endl;
    string newPassword  = otherFunctions.readLine();
  
    for (User& user: users) {

        if (user.getUserID() == loggedID) {
            user.setUserPassword(newPassword);
            usersTextFile.replaceChangedPasswordInTextFile(loggedID, newPassword, user);
            break;
        }
    }
    cout << "Password changed succesfully. "; system("pause");
}
