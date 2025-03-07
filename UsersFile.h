#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UtilityMethods.h"
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile{

public:
    UsersFile(string usersFileName)
            :XmlFile(usersFileName){};

    bool addUserToFile(User &user);
    bool changeUserPasswordInFile(User user);
    vector <User> loadUsersFromFile();

};

#endif
