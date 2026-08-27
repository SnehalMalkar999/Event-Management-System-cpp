#include "Utils.h"
#include <fstream>
#include <ctime>
#include <cstdio>

using namespace std;

// Check whether the date is in the future
bool isFutureDate(string date) {
    int d, m, y;

    if (sscanf(date.c_str(), "%d/%d/%d", &d, &m, &y) != 3)
        return false;

    time_t t = time(0);
    tm *now = localtime(&t);

    if (y > now->tm_year + 1900) return true;
    if (y == now->tm_year + 1900 && m > now->tm_mon + 1) return true;
    if (y == now->tm_year + 1900 &&
        m == now->tm_mon + 1 &&
        d > now->tm_mday) return true;

    return false;
}

// Check whether event ID exists
bool eventExists(int eid) {
    ifstream fin("events.txt");

    int id;
    string name, type, location, date;
    float budget;

    while (fin >> id >> name >> type >> budget >> location >> date) {
        if (id == eid)
            return true;
    }

    return false;
}

// Check duplicate event ID or name
bool isDuplicateEvent(int id, string name) {
    ifstream fin("events.txt");

    int eid;
    string ename, type, loc, date;
    float budget;

    while (fin >> eid >> ename >> type >> budget >> loc >> date) {
        if (eid == id || ename == name)
            return true;
    }

    return false;
}

// Check whether user already exists
bool userExists(string uname) {
    ifstream fin("users.txt");

    string u, p;

    while (fin >> u >> p) {
        if (u == uname)
            return true;
    }

    return false;
}

// Check whether user already booked event
bool alreadyBooked(string user, int eid) {
    ifstream fin("bookings.txt");

    string u;
    int id;

    while (fin >> u >> id) {
        if (u == user && id == eid)
            return true;
    }

    return false;
}

// Check whether user already reviewed event
bool alreadyReviewed(string user, int eid) {
    ifstream fin("reviews.txt");

    string u, review;
    int id;

    while (fin >> u >> id >> review) {
        if (u == user && id == eid)
            return true;
    }

    return false;
}