#include <iostream>

#include "Event.h"
#include "User.h"
#include "Booking.h"
#include "Review.h"
#include "Report.h"

using namespace std;

// ============================================================
// MAIN FUNCTION
// Controls Admin and User menus
// ============================================================

int main() {
    Event e;
    User u;
    Booking b;
    Review rv;
    Report r;

    int choice, ch;
    string currentUser;

    // Main menu loop
    while (1) {

        cout << "\n------ MAIN MENU ------\n";
        cout << "1.Admin Login \n2. User Register\n3. User Login\n4.Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        // Admin Login
        if (choice == 1) {

            string a, p;

            cout << "Admin Username: ";
            cin >> a;

            cout << "Password: ";
            cin >> p;

            // Admin credentials
            if (a == "admin" && p == "1234") {

                while (1) {

                    cout << "\n------ Admin MENU ------\n";
                    cout << "\n1.Add Event \n2.View Event\n3.Search Event"
                         << "\n4.Delete  Event\n5.Report Event"
                         << "\n6.Clear Data\n7.Exit\n";

                    cout << "Enter choice: ";
                    cin >> ch;

                    if (ch == 1)
                        e.addEvent();

                    else if (ch == 2)
                        e.viewEvents();

                    else if (ch == 3)
                        e.searchEvent();

                    else if (ch == 4)
                        e.deleteEvent();

                    else if (ch == 5)
                        r.generateReport();

                    else if (ch == 6)
                        r.clearReport();

                    else
                        break;
                }

            } else {
                cout << "Invalid Admin Login!\n";
            }
        }

        // User Registration
        else if (choice == 2) {
            u.registerUser();
        }

        // User Login
        else if (choice == 3) {

            if (u.loginUser(currentUser)) {

                while (1) {

                    cout << "\n------ User MENU ------\n";
                    cout << "\n1.View Events\n2.Book Event"
                         << "\n3.Delete Booking\n4.Add Review\n5.Exit\n";

                    cout << "Enter choice: ";
                    cin >> ch;

                    if (ch == 1)
                        e.viewEvents();

                    else if (ch == 2)
                        b.bookEvent(currentUser);

                    else if (ch == 3)
                        b.deleteBooking(currentUser);

                    else if (ch == 4)
                        rv.addReview(currentUser);

                    else
                        break;
                }
            }
        }

        // Exit program
        else
            break;
    }

    return 0;
}