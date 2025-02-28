#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <algorithm>

#include "Operation.h"
#include "OperationType.h"
#include "OperationsFile.h"
#include "DateMethods.h"
#include "CashMethods.h"
#include "Menus.h"

using namespace std;

class BalanceManager{
    const int LOGGED_IN_USER_ID;
    OperationsFile incomesFile;
    OperationsFile expensesFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const OperationType &operationType);
    static bool sortDataAscendingByDate(const Operation& operationA, const Operation& operationB);

public:
    BalanceManager(int loggedInUserId, string incomesFileName, string expensesFileName)
                :LOGGED_IN_USER_ID(loggedInUserId), incomesFile(incomesFileName),
                expensesFile(expensesFileName){

        incomes = incomesFile.loadOperationsOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expensesFile.loadOperationsOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    }

    void addIncome();
    void addExpense();
    void showBalance(); //tymczasowo publiczny

};

#endif
