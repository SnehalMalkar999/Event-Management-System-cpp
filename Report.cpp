#include "Report.h"

#include <iostream>
#include <fstream>

using namespace std;

// Generate project report
void Report::generateReport() {
    int e = 0, u = 0, b = 0;

    int id;
    string name, type, location, date;
    float budget;

    // Count events
    ifstream fe("events.txt");

    while (fe >> id >> name >> type >> budget >> location >> date)
        e++;

    string a, c;

    // Count users
    ifstream fu("users.txt");

    while (fu >> a >> c)
        u++;

    // Count bookings
    ifstream fb("bookings.txt");

    while (fb >> a >> c)
        b++;

    cout << "\n===== REPORT =====\n";
    cout << "Events: " << e << endl;
    cout << "Users: " << u << endl;
    cout << "Bookings: " << b << endl;
}

// Clear all project data
void Report::clearReport() {
    char confirm;

    cout << "Are you sure you want to delete ALL data? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        ofstream("events.txt", ios::trunc);
        ofstream("users.txt", ios::trunc);
        ofstream("bookings.txt", ios::trunc);
        ofstream("reviews.txt", ios::trunc);

        cout << "All Data Cleared!\n";
    } else {
        cout << "Operation Cancelled.\n";
    }
}