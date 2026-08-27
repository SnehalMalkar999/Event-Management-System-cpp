#include "Review.h"
#include "Utils.h"

#include <iostream>
#include <fstream>

using namespace std;

// Add review for an event
void Review::addReview(string user) {
    int eid;
    string review;

    cout << "Enter Event ID: ";
    cin >> eid;

    if (!eventExists(eid)) {
        cout << "Event not found!\n";
        return;
    }

    if (!alreadyBooked(user, eid)) {
        cout << "Book event first!\n";
        return;
    }

    if (alreadyReviewed(user, eid)) {
        cout << "Already reviewed!\n";
        return;
    }

    cout << "Enter Review: ";
    cin >> review;

    ofstream fout("reviews.txt", ios::app);
    fout << user << " " << eid << " " << review << endl;

    cout << "Review Added!\n";
}