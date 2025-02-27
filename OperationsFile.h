#ifndef OPERATIONSFILE_H
#define OPERATIONSFILE_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "UtilityMethods.h"
#include "XmlFile.h"

using namespace std;

class OperationsFile : public XmlFile{

public:
    OperationsFile(string operationsFileName)
                :XmlFile(operationsFileName){};
    vector <Operation> loadOperationsOfLoggedInUserFromFile(const int loggedInUserId);
    bool addNewOperationToFile(const Operation &operation);

};

#endif
