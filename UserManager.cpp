#include "UserManager.h"

void UserManager::loginUser() {
    User user;
    string login = "", password = "";
    bool isLoggedIn = false;
    bool isLoginExisting = false;

    cout << "Provide login: ";
    login = UtilityMethods::readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].login == login) {
            isLoginExisting = true;
            for (int attemptsLeft = 3; attemptsLeft > 0; attemptsLeft--) {
                cout << "Provide password. Attempts left: " << attemptsLeft << ": ";
                password = UtilityMethods::readLine();

                if (users[i].password == password) {
                    cout << endl << "You have logged in!" << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].id;
                    isLoggedIn = true;
                }
                if (isLoggedIn == true) break;
            }
        }
    }
    if (isLoggedIn == false && isLoginExisting == true) {
        cout << "An incorrect password was entered 3 times." << endl;
        system("pause");
        loggedInUserId = 0;
    } else if (isLoginExisting == false) {
        cout << "There is no user with this login." << endl << endl;
        system("pause");
        loggedInUserId = 0;
    }
}

void UserManager::userRegistration() {

    User user = inputNewUserData();

    users.push_back(user);
    if(usersFile.addUserToFile(user)){
        cout << endl << "The account was created successfully!" << endl << endl;
        system("pause");
    }
}

void UserManager::loggedInUserPasswordChange() {
    string newPassword = "";
    cout << "Provide new password: ";
    newPassword = UtilityMethods::readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].id == loggedInUserId) {
            users[i].password = newPassword;
            if (usersFile.changeUserPasswordInFile(users[i])){
                cout << "Password has been changed." << endl << endl;
                system("pause");
            }
        }
    }
}


User UserManager::inputNewUserData() {
    User user;

    user.id = getNewUserId();

    string login;
    do {
        cout << "Provide login: ";
        cin >> login;
        user.login = login;
    } while (isLoginAlreadyTaken(user.login) == true);

    string password;
    cout << "Provide password: ";
    cin >> password;
    user.password = password;

    string name;
    cout << "Provide name: ";
    cin >> name;
    user.name = name;

    string surname;
    cout << "Provide surname: ";
    cin >> surname;
    user.surname = surname;

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().id + 1;
}

bool UserManager::isLoginAlreadyTaken(string login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].login == login) {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0) {
        return true;
    } else
        return false;
}
