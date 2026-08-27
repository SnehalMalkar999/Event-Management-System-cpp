#ifndef BOOKING_H
#define BOOKING_H

#include <string>
using namespace std;

class Booking {
public:
    // Booking functions
    void bookEvent(string user);
    void deleteBooking(string user);
};

#endif