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
