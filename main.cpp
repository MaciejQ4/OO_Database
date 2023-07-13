// OO_Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "User.h"
#include "Database.h"
#include "ContactManager.h"

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

int main()
{

    Database database;
    int loggedID = 0;
    char choice;

    while (true) {
        
        if (database.isUserLogged() == false) {

            system("cls");
            cout << "Main menu\n";
            cout << "1. Create new user \n";
            cout << "2. Login \n";
            cout << "3. Show all users \n";
            cin >> choice;

            switch (choice) {
            case '1': database.createUser();            break;
            case '2': loggedID = database.loginUser();  break;
            case '3': database.showAllUsers();          break; 
            }
        }
/////////////////////////////////////////////////////////////////////        
        else {

            
            system("cls");
            cout << " USER MENU "               << endl << endl;
            cout << "1. Create a contact"              << endl;
            cout << "4. Show all contacts in database"  << endl;
            cout << "8. Sign out"               << endl << endl;
            cout << "9. Exit"                           << endl;

            cin >> choice;

            switch (choice) {

            case '1': database.createContact(loggedID);         break;
            case '4': database.showAllContacts(loggedID);       break;
            //case '7': userManager.changePassword(userID);     break;
            case '8': database.logOut();                        break;
            case '9': exit(0);                                  break;
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
