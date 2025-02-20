#ifndef PERSONALBUDGETAPP_H
#define PERSONALBUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "BalanceManager.h"

using namespace std;

class PersonalBudgetApp {
    UserManager userManager;
    BalanceManager *balanceManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    PersonalBudgetApp(string usersFileName, string incomesFileName, string expensesFileName)
        :userManager(usersFileName),INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName){

        balanceManager = NULL;
    };
    ~PersonalBudgetApp(){
        delete balanceManager;
        balanceManager = NULL;
    };

    void loginUser();
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
