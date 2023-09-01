// OO_Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Database.h"
#include "OtherFunctions.h"
#include <iostream>
using namespace std;

int main()
{
    Database database("users.txt", "contacts.txt");

    while (true) {
        
        if (database.isUserLogged() == false) {

            system("cls");
            cout << ">> DATABASE MAIN MENU <<"  << endl << endl;
            cout << "1. Create new User"        << endl;
            cout << "2. Login"                  << endl;
            cout << "3. Show all Users"         << endl;
            cout << "9. Close Database"         << endl;
            
            char choice = OtherFunctions::readChar();
            switch (choice) {
            
            case '1': database.createUser();              break;
            case '2': database.loginUser();               break;
            case '3': database.showAllUsers();            break;
            case '4': exit(0);                            break;

            default: cout << "Wrong input. "; system("pause");
            }
        }
////////////////////////////////////////////////////////////////       
        else {
   
            system("cls");
            cout << ">> USER MENU <<"           << endl << endl;
            cout << "1. Create a contact"               << endl;
            cout << "2. Search contacts by name"        << endl;
            cout << "3. Search contacts by surname"     << endl;
            cout << "4. Show all contacts in database"  << endl;
            cout << "5. Delete a contact"               << endl;
            cout << "6. Edit a contact"                 << endl;
            cout << "7. Change password"                << endl;
            cout << "8. Sign out"                       << endl;
            cout << "9. Exit"                           << endl;
            
            char choice = OtherFunctions::readChar();
            switch (choice) {

            case '1': database.createContact();           break;
            case '2': database.searchAndShowByName();     break;
            case '3': database.searchAndShowBySurname();  break;
            case '4': database.showAllContacts();         break;
            case '5': database.deleteContact();           break;
            case '6': database.editContact();             break;
            case '7': database.changePassword();          break;
            case '8': database.logOut();                  break;
            case '9': exit(0);                            break;

            default: cout << "Wrong input. "; system("pause");
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
