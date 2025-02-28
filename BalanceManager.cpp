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

bool BalanceManager::sortDataAscendingByDate(const Operation& operationA, const Operation& operationB){
    struct tm dateAStruct;
    struct tm dateBStruct;

    dateAStruct = DateMethods::convertStringToTmStruct(operationA.date);
    dateBStruct = DateMethods::convertStringToTmStruct(operationB.date);

    return mktime(&dateAStruct) < mktime(&dateBStruct);
}

void BalanceManager::showBalance(){

    cout << fixed << setprecision(2);

    sort(incomes.begin(), incomes.end(), sortDataAscendingByDate);
    cout << ">>>INCOMES<<<" << endl;
    cout << "Date\t\t" << "Amount\t\t" << "Item\t\t" << endl;
    for (size_t i = 0; i < incomes.size(); i++){
        cout << incomes[i].date << "\t" <<incomes[i].amount << "\t\t" << incomes[i].item << endl;
    }

    sort(expenses.begin(), expenses.end(), sortDataAscendingByDate);
    cout << endl << ">>>EXPENSES<<<" << endl;
    cout << "Date\t\t" << "Amount\t\t" << "Item\t\t" << endl;
    for (size_t i = 0; i < expenses.size(); i++){
        cout << expenses[i].date << "\t" << expenses[i].amount << "\t\t" << expenses[i].item << endl;
    }

    float incomesSum = calculateOperationTypeBalance(INCOME);
    float expensesSum = calculateOperationTypeBalance(EXPENSE);
    cout << endl << ">>>BALANCE SUMMARY<<<" << endl;
    cout << "Incomes: \t\t" << incomesSum << endl;
    cout << "Expenses: \t\t" << expensesSum << endl;

    float balance = incomesSum - expensesSum;
    if (balance < 0)
        cout << "Total debt: \t\t" << balance << endl;
    else
        cout << "Total savings: \t\t" << balance << endl;
    system("pause");
}

float BalanceManager::calculateOperationTypeBalance (/*string startDate, string endDate, */const OperationType &operationType){
    float operationSum = 0;

    switch (operationType){
        case INCOME:
            for (size_t i = 0; i < incomes.size(); i++){
                operationSum += incomes[i].amount;
            }
        break;
        case EXPENSE:
            for (size_t i = 0; i < expenses.size(); i++){
                operationSum += expenses[i].amount;
            }
        break;
    }
    return operationSum;
}
