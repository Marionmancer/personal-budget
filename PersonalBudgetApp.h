#ifndef PERSONALBUDGETAPP_H
#define PERSONALBUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "BalanceManager.h"

using namespace std;

class PersonalBudgetApp {
    UserManager userManager;
    BalanceManager *balanceManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    PersonalBudgetApp(string userFileName, string incomeFileName, string expenseFileName)
        :/*userManager(userFileName),*/INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName){

        balanceManager = NULL;
    };
    ~PersonalBudgetApp(){
        delete balanceManager;
        balanceManager = NULL;
    };

    void userLoggingIn();
    void userRegistration();
    void loggedInUserPasswordChange();
    void userLogout();
    void addIncome();
    void addExpense();
    void displayCurrenthMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalanace();
    bool isUserLoggedIn();

};


#endif
