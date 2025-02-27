#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>

#include "Operation.h"
#include "OperationType.h"
#include "OperationsFile.h"
#include "DateMethods.h"
#include "Menus.h"

using namespace std;

class BalanceManager{
    const int LOGGED_IN_USER_ID;
    OperationsFile incomesFile;
    OperationsFile expensesFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const OperationType &operationType);

public:
    BalanceManager(int loggedInUserId, string incomesFileName, string expensesFileName)
                :LOGGED_IN_USER_ID(loggedInUserId){

    }

    void addIncome();
    void addExpense();

};

#endif
