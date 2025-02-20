#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFile.h"
#include "UtilityMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User inputNewUserData();
    int getNewUserId();
    bool isLoginAlreadyTaken(string login);
public:
    UserManager(string usersFileName){

        loggedInUserId = 0;
    }

    void loginUser();
    void userRegistration();
    bool isUserLoggedIn();

    int getLoggedInUserId(){
        return loggedInUserId;
    }
};

#endif
