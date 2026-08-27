#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

// Function declarations
bool isFutureDate(string date);
bool eventExists(int eid);
bool isDuplicateEvent(int id, string name);
bool userExists(string uname);
bool alreadyBooked(string user, int eid);
bool alreadyReviewed(string user, int eid);

#endif