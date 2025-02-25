#include <iostream>

#include "PersonalBudgetApp.h"
#include "Menus.h"

using namespace std;

//int main2(){
//    string dataPoprawna = "2001-01-31";
//    string dataNiepoprawnaPoprawna = "1999-01-31";
//    string nieData = "r001-m1-d1";
//
//    validateDate(dataPoprawna);
//    validateDate(dataNiepoprawnaPoprawna);
//    validateDate(nieData);
//
//
//    return 0;
//}

int main()
{
    PersonalBudgetApp personalBudgetApp("users.xml","incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (personalBudgetApp.isUserLoggedIn() == false)
        {
            choice = Menus::chooseLoginMenuOption();

            switch (choice)
            {
            case '1':
                personalBudgetApp.userRegistration();
                break;
            case '2':
                personalBudgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = Menus::chooseBalanceMenuOption();

            switch (choice)
            {
            case '1':
                personalBudgetApp.addIncome();
                break;
            case '2':
                personalBudgetApp.addExpense();
                break;
            case '3':
                personalBudgetApp.displayCurrenthMonthBalance();
                break;
            case '4':
                personalBudgetApp.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudgetApp.displaySelectedPeriodBalanace();
                break;
            case '6':
                personalBudgetApp.loggedInUserPasswordChange();
                break;
            case '7':
                personalBudgetApp.userLogout();
                break;
            }
        }
    }
    return 0;
}
