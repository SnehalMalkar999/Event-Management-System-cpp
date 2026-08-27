#include "User.h"
#include "Utils.h"

#include <iostream>
#include <fstream>

using namespace std;

// Register new user
void User::registerUser() {
    cout << "Username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream fout("users.txt", ios::app);
    fout << username << " " << password << endl;

    cout << "Registered!\n";
}

// Login user
bool User::loginUser(string &currentUser) {
    string u, p;

    cout << "Username: ";
    cin >> u;

    cout << "Password: ";
    cin >> p;

    ifstream fin("users.txt");

    while (fin >> username >> password) {
        if (username == u && password == p) {
            currentUser = u;
            cout << "Login Success!\n";
            return true;
        }
    }

    cout << "Invalid!\n";
    return false;
}