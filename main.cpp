// OO_Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Database.h"
#include "OtherFunctions.h"
#include <iostream>
using namespace std;

int main()
{
    Database database("users.txt", "contacts.txt");
    char choice;

    while (true) {
        
        if (database.isUserLogged() == false) {

            system("cls");
            cout << "Main menu\n";
            cout << "1. Create new user \n";
            cout << "2. Login \n";
            cout << "3. Show all users \n";
            
            choice = OtherFunctions::readChar();

            switch (choice) {
            case '1': database.createUser();              break;
            case '2': database.loginUser();               break;
            case '3': database.showAllUsers();            break; 
            }
        }
/////////////////////////////////////////////////////////////////////        
        else {
   
            system("cls");
            cout << " USER MENU "               << endl << endl;
            cout << "1. Create a contact"               << endl;
            cout << "4. Show all contacts in database"  << endl;
            cout << "7. Change password"                << endl;
            cout << "8. Sign out"               << endl << endl;
            cout << "9. Exit"                           << endl;
            
            choice = OtherFunctions::readChar();
            switch (choice) {

            case '1': database.createContact();           break;
            case '4': database.showAllContacts();         break;
            case '7': database.changePassword();          break;
            case '8': database.logOut();                  break;
            case '9': exit(0);                            break;
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
