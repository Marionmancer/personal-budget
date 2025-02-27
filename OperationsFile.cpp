#include "OperationsFile.h"

vector <Operation> OperationsFile::loadOperationsOfLoggedInUserFromFile(const int loggedInUserId) {
    Operation operation;
    vector <Operation> operations;
    CMarkup xmlDoc;
    string operationsXmlFileName = getFileName();
    bool fileExists = xmlDoc.Load(operationsXmlFileName);

    if (fileExists){
        xmlDoc.ResetPos();
        xmlDoc.FindElem("operations");
        xmlDoc.IntoElem();
        while (xmlDoc.FindElem("operation")) {
            xmlDoc.FindChildElem("userId");
            if(atoi(xmlDoc.GetChildData().c_str()) == loggedInUserId){
                operation.userId = loggedInUserId;
                xmlDoc.FindChildElem("id");
                operation.id = atoi(xmlDoc.GetChildData().c_str());
                xmlDoc.FindChildElem("date");
                operation.date = xmlDoc.GetChildData();
                xmlDoc.FindChildElem("amount");
                operation.amount = stof(xmlDoc.GetChildData());
                xmlDoc.FindChildElem("item");
                operation.item = xmlDoc.GetChildData();
                operations.push_back(operation);
            }
        }
    }
    return operations;
}

bool OperationsFile::addNewOperationToFile(const Operation &operation){

    bool status = false;
    CMarkup xmlDoc;
    string operationsXmlFileName = getFileName();

    bool fileExists = xmlDoc.Load(operationsXmlFileName);

    if (!fileExists){
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("operations");
        cout << "Such file doesn't exists. Created new one." << endl;
    }

    xmlDoc.ResetPos();
    if(xmlDoc.FindElem("operations")){
        xmlDoc.IntoElem();
        xmlDoc.AddElem("operation");
        xmlDoc.AddChildElem("id", operation.id);
        xmlDoc.AddChildElem("userId", operation.userId);
        xmlDoc.AddChildElem("date", operation.date);
        xmlDoc.AddChildElem("amount", operation.amount);
        xmlDoc.AddChildElem("item", operation.item);
        xmlDoc.ResetPos();
        xmlDoc.Save(operationsXmlFileName);
        status = true;
    }

    return status;
}
