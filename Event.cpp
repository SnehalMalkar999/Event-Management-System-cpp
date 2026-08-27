#include "Event.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;

// Add a new event
void Event::addEvent() {
    cout << "Enter Event ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    if (isDuplicateEvent(id, name)) {
        cout << "Duplicate ID/Name not allowed!\n";
        return;
    }

    cout << "Enter Type: ";
    getline(cin, type);

    cout << "Enter Budget: ";
    cin >> budget;
    cin.ignore();

    cout << "Enter Location: ";
    getline(cin, location);

    cout << "Enter Date (dd/mm/yyyy): ";
    cin >> date;

    if (!isFutureDate(date)) {
        cout << "Enter future date only!\n";
        return;
    }

    ofstream fout("events.txt", ios::app);

    fout << id << " " << name << " " << type << " "
         << budget << " " << location << " " << date << endl;

    cout << "Event Added!\n";
}

// View all events
void Event::viewEvents() {
    ifstream fin("events.txt");

    cout << setw(8) << "ID"
         << setw(12) << "NAME"
         << setw(12) << "TYPE"
         << setw(12) << "BUDGET"
         << setw(12) << "LOCATION"
         << setw(15) << "DATE" << endl;

    while (fin >> id >> name >> type >> budget >> location >> date) {
        cout << setw(8) << id
             << setw(12) << name
             << setw(12) << type
             << setw(12) << budget
             << setw(12) << location
             << setw(15) << date << endl;
    }
}

// Search event by ID
void Event::searchEvent() {
    int sid;

    cout << "Enter Event ID: ";
    cin >> sid;

    ifstream fin("events.txt");
    bool found = false;

    while (fin >> id >> name >> type >> budget >> location >> date) {
        if (id == sid) {
            cout << "\nEvent Found:\n";

            cout << id << " " << name << " " << type << " "
                 << budget << " " << location << " " << date << endl;

            found = true;
        }
    }

    if (!found)
        cout << "Event Not Found!\n";
}

// Delete event by ID
void Event::deleteEvent() {
    int did;

    cout << "Enter Event ID to Delete: ";
    cin >> did;

    ifstream fin("events.txt");
    ofstream fout("temp.txt");

    while (fin >> id >> name >> type >> budget >> location >> date) {
        if (id != did) {
            fout << id << " " << name << " " << type << " "
                 << budget << " " << location << " " << date << endl;
        }
    }

    fin.close();
    fout.close();

    remove("events.txt");
    rename("temp.txt", "events.txt");

    cout << "Event Deleted!\n";
}