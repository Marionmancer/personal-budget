#include "UserManager.h"

void UserManager::loginUser() {
    User user;
    string login = "", password = "";
    bool isLoggedIn = false;
    bool isLoginExisting = false;

    cout << "Podaj login: ";
    login = UtilityMethods::readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].login == login) {
            isLoginExisting = true;
            for (int attemptsLeft = 3; attemptsLeft > 0; attemptsLeft--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsLeft << ": ";
                password = UtilityMethods::readLine();

                if (users[i].password == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].id;
                    isLoggedIn = true;
                }
                if (isLoggedIn == true) break;
            }
        }
    }
    if (isLoggedIn == false && isLoginExisting == true) {
        cout << "Wprowadzono 3 razy bledne haslo." << endl;
        system("pause");
        loggedInUserId = 0;
    } else if (isLoginExisting == false) {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        loggedInUserId = 0;
    }
}

void UserManager::userRegistration() {

    User user = inputNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::loggedInUserPasswordChange() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = UtilityMethods::readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].id == loggedInUserId) {
            users[i].password = newPassword;
            if (usersFile.changeUserPasswordInFile(users[i])){
                cout << "Haslo zostalo zmienione." << endl << endl;
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
        cout << "Podaj login: ";
        cin >> login;
        user.login = login;
    } while (isLoginAlreadyTaken(user.login) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.password = password;

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.name = name;

    string surname;
    cout << "Podaj nazwisko: ";
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
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
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
