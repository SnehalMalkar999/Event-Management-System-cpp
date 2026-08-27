#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {
public:
    int id;
    string name, type, location, date;
    float budget;

    // Event functions
    void addEvent();
    void viewEvents();
    void searchEvent();
    void deleteEvent();
};

#endif