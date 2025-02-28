#include "Menus.h"

char Menus::chooseLoginMenuOption() {
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Close the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = UtilityMethods::getChar();

    return choice;
}

char Menus::chooseBalanceMenuOption() {
    char choice;

    system("cls");
    cout << " >>> BUDGET MANAGEMENT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance of current month" << endl;
    cout << "4. Balance of previous month" << endl;
    cout << "5. Balance of custom period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = UtilityMethods::getChar();

    return choice;
}

void Menus::showTitle(string title) {

    system("cls");
    cout << title << endl;

}
