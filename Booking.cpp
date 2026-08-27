#include "Booking.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

// Book an event
void Booking::bookEvent(string user) {
    int eid;

    cout << "Enter Event ID: ";
    cin >> eid;

    if (!eventExists(eid)) {
        cout << "Event does not exist!\n";
        return;
    }

    if (alreadyBooked(user, eid)) {
        cout << "Already booked!\n";
        return;
    }

    ofstream fout("bookings.txt", ios::app);
    fout << user << " " << eid << endl;

    cout << "Booked!\n";
}

// Delete booking
void Booking::deleteBooking(string user) {
    int eid;

    cout << "Enter Event ID to cancel: ";
    cin >> eid;

    ifstream fin("bookings.txt");
    ofstream fout("temp.txt");

    string u;
    int id;
    bool found = false;

    while (fin >> u >> id) {
        if (u == user && id == eid) {
            found = true;
            continue;
        }

        fout << u << " " << id << endl;
    }

    fin.close();
    fout.close();

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found)
        cout << "Booking Deleted!\n";
    else
        cout << "Booking Not Found!\n";
}