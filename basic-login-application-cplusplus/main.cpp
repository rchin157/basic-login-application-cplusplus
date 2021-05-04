// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

void createAccount(string username, string password) {
    struct stat buffer;
    if (stat((username + ".txt").c_str(), &buffer) == 0) {
        cout << "That account already exists!\n";
    }
    else {
        ofstream newaccount(username + ".txt");
        newaccount << password;
        newaccount.close();
        cout << "Account created.\n";
    }
}

void login(string username, string password) {
    struct stat buffer;
    if (stat((username + ".txt").c_str(), &buffer) == 0) {
        ifstream account(username + ".txt");
        string storedPassword;
        getline(account, storedPassword);
        if (password == storedPassword)
            cout << "Logged in.\n";
        else
            cout << "Incorrect username or password.\n";
        account.close();
    }
    else {
        cout << "Incorrect username or password.\n";
    }
}

void getLoginInfo(string& username, string& password) {
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
}

int main()
{
    int choice;

    string username;
    string password;

    cout << "1: Make an account\n";
    cout << "2: Login\n";
    cout << "Choose an action: ";
    cin >> choice;

    getLoginInfo(username, password);

    if (choice == 1)
        createAccount(username, password);
    else if (choice == 2)
        login(username, password);
    else
        cout << "Invalid choice.\n";

    return 0;
}
