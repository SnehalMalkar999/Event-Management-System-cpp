#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string username, password;

    // User functions
    void registerUser();
    bool loginUser(string &currentUser);
};

#endif