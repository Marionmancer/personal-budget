#include <iostream>

#include "PersonalBudgetApp.h"
#include "Menus.h"

using namespace std;

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
                Menus::showTitle(">>>Registration<<<\n");
                personalBudgetApp.userRegistration();
                break;
            case '2':
                Menus::showTitle(">>>Login<<<\n");
                personalBudgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                Menus::showTitle("Wrong digit!");
                cout << endl << "There is no such option in the menu" << endl << endl;
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
                Menus::showTitle(">>>ADD NEW INCOME<<<\n");
                personalBudgetApp.addIncome();
                break;
            case '2':
                Menus::showTitle(">>>ADD NEW EXPENSE<<<\n");
                personalBudgetApp.addExpense();
                break;
            case '3':
                Menus::showTitle(">>>CURRENT MONTH BALANCE<<<\n");
                personalBudgetApp.displayCurrenthMonthBalance();
                break;
            case '4':
                Menus::showTitle(">>>PREVIOUS MONTH BALANCE<<<\n");
                personalBudgetApp.displayPreviousMonthBalance();
                break;
            case '5':
                Menus::showTitle(">>>CUSTOM MONTH BALANCE<<<\n");
                personalBudgetApp.displaySelectedPeriodBalanace();
                break;
            case '6':
                Menus::showTitle(">>>PASSWORD CHANGE<<<\n");
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
