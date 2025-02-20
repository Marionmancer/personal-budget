#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include "OperationsFile.h"

using namespace std;

class BalanceManager{
    const int LOGGED_IN_USER_ID;
    OperationsFile incomesFile;
    OperationsFile expensesFile;

public:
    BalanceManager(int loggedInUserId, string incomesFileName, string expensesFileName)
                :LOGGED_IN_USER_ID(loggedInUserId){

    }

};

#endif
