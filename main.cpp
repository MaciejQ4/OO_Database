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
    int userID;
    ContactManager contactManager;
    UserManager userManager;


    while (true) {
        system("cls");
        cout << "Main menu\n";
        cout << "1. Create new user \n";
        cout << "2. Login \n";
        cout << "3. Show all users \n";
        //cout << "4. Change password \n"; // ROZWAZALEM ZMIANE HASLA Z TEGO POZIOMU ALE W KONCU UDALO MI SIE Z NIZSZEGO
        char choice;
        cin >> choice;

        switch (choice) {
        case '1': database.createUser(); break;
        case '2': userID = database.loginUser(); 
                    if (userID) contactManager.Menu(userID);
                    else system("pause");
                    break;
        case '3': database.showAllUsers(); break;
        //case '4': 
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
