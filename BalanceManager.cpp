#include "BalanceManager.h"

Operation BalanceManager::addOperationDetails(const OperationType &operationType) {

    Operation operation;
    string operationDescription;

    system("cls");
    Menus::showTitle("ADD OPERATION DETAILS \n");

    switch (operationType){
        case INCOME:
            operation.id = incomesFile.getLastId()+1;
            operationDescription = "income";
            break;
        case EXPENSE:
            operation.id = expensesFile.getLastId()+1;
            operationDescription = "expense";
            break;
    }
    operation.userId = LOGGED_IN_USER_ID;

    cout << "Is the " << operationDescription << " related to today's date? [y/n]" << endl;
    char userChoice;
    do{
        userChoice = UtilityMethods::getChar();
        switch (userChoice){
            case 'y':
                operation.date = DateMethods::convertTmStructDateToStringDate(DateMethods::getCurrentDate());
                break;
            case 'n':
                bool isDateValid;
                do{
                    cout << endl << "Enter " << operationDescription << " date in format yyyy-mm-dd." << endl;
                    operation.date = UtilityMethods::readLine();

                    isDateValid = DateMethods::validateDate(operation.date);
                    if (isDateValid == false){
                        cout << endl << "Invalid date entered. Try again, correct format is yyyy-mm-dd." << endl;
                    }

                }while (!isDateValid);
                break;
            default:
                cout << endl << "Wrong input. Try again" << endl;
        }
    } while ((userChoice!='y') && (userChoice!='n'));

    bool amountValidationResult = false;
    do{
        cout << endl << "Enter " << operationDescription << " amount." << endl;
        string tempAmount = UtilityMethods::readLine();
        amountValidationResult = CashMethods::validateAmount(tempAmount);

        if (amountValidationResult){
            operation.amount = stof(tempAmount);
        } else {
            cout << endl << "Wrong amount entered. Try again." << endl;
        }

    } while (!amountValidationResult);

    cout << endl << "Enter short " << operationDescription << " description." << endl;
    operation.item = UtilityMethods::readLine();

    return operation;
}

void BalanceManager::addIncome(){
    if(incomesFile.addNewOperationToFile(addOperationDetails(INCOME)))
        cout << "Income successfully added to library" << endl;
}

void BalanceManager::addExpense(){
    if(expensesFile.addNewOperationToFile(addOperationDetails(EXPENSE)))
        cout << "Expense successfully added to library" << endl;
}
