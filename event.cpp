#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdio>
using namespace std;
bool isFutureDate(string date) {
    int d, m, y;

    if (sscanf(date.c_str(), "%d/%d/%d", &d, &m, &y) != 3)
        return false;

    time_t t = time(0);
    tm *now = localtime(&t);

    if (y > now->tm_year + 1900) return true;
    if (y == now->tm_year + 1900 && m > now->tm_mon + 1) return true;
    if (y == now->tm_year + 1900 && m == now->tm_mon + 1 && d > now->tm_mday) return true;

    return false;
}
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
bool userExists(string uname) {
    ifstream fin("users.txt");
    string u, p;

    while (fin >> u >> p) {
        if (u == uname)
            return true;
    }
    return false;
}
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
class Event {
public:
    int id;
    string name, type, location, date;
    float budget;

    void addEvent() {
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

    void viewEvents() {
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

    void searchEvent() {
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

    void deleteEvent() {
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
};
class User {
public:
    string username, password;

    void registerUser() {
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

    bool loginUser(string &currentUser) {
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
};

class Booking {
public:
    void bookEvent(string user) {
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

    void deleteBooking(string user) {
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
};

class Review {
public:

    void addReview(string user) {
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
};
class Report {
public:
    void generateReport() {
        int e = 0, u = 0, b = 0;

        int id;
        string name, type, location, date;
        float budget;

        ifstream fe("events.txt");
        while (fe >> id >> name >> type >> budget >> location >> date)
            e++;

        string a, c;

        ifstream fu("users.txt");
        while (fu >> a >> c)
            u++;

        ifstream fb("bookings.txt");
        while (fb >> a >> c)
            b++;

        cout << "\n===== REPORT =====\n";
        cout << "Events: " << e << endl;
        cout << "Users: " << u << endl;
        cout << "Bookings: " << b << endl;
    }
    void clearReport() {
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
};
int main() {
    Event e;
    User u;
    Booking b;
    Review rv;
    Report r;

    int choice, ch;
    string currentUser;

    while (1) {
        cout << "\n------ MAIN MENU ------\n";
        cout << "1.Admin Login \n2. User Register\n3. User Login\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string a, p;
            cout << "Admin Username: ";
            cin >> a;
            cout << "Password: ";
            cin >> p;

            if (a == "admin" && p == "1234") {
                while (1) {
                	cout << "\n------ Admin MENU ------\n";
                    cout << "\n1.Add Event \n2.View Event\n3.Search Event\n4.Delete  Event\n5.Report Event\n6.Clear Data\n7.Exit\n";
                    cout << "Enter choice: ";
                    cin >> ch;

                    if (ch == 1) e.addEvent();
                    else if (ch == 2) e.viewEvents();
                    else if (ch == 3) e.searchEvent();
                    else if (ch == 4) e.deleteEvent();
                    else if (ch == 5) r.generateReport();
                    else if (ch == 6) r.clearReport();
                    else break;
                }
            } else {
                cout << "Invalid Admin Login!\n";
            }
        }

        else if (choice == 2) {
            u.registerUser();
        }

        else if (choice == 3) {
            if (u.loginUser(currentUser)) {
                while (1) {
                	cout << "\n------ User MENU ------\n";
                    cout << "\n1.View Events\n2.Book Event\n3.Delete Booking\n4.Add Review\n5.Exit\n";
                    cout << "Enter choice: ";
                    cin >> ch;

                    if (ch == 1) e.viewEvents();
                    else if (ch == 2) b.bookEvent(currentUser);
                    else if (ch == 3) b.deleteBooking(currentUser);
                    else if (ch == 4) rv.addReview(currentUser);
                    else break;
                }
            }
        }

        else break;
    }
}
