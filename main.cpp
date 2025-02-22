#include <iostream>

#include "PersonalBudgetApp.h"
#include "Menus.h"

using namespace std;

//int main2(){
//    int lastId = 0;
//    CMarkup xmlDoc;
//
//    if (xmlDoc.Load("users.xml")) {
//        xmlDoc.AddElem("users");
//        xmlDoc.FindElem();
//        xmlDoc.IntoElem();
//        while (xmlDoc.FindElem()){
//            xmlDoc.FindChildElem("id");
//            lastId = atoi(xmlDoc.GetChildData().c_str());
//            cout << "Last id: " << lastId << endl;
//        }
//        xmlDoc.OutOfElem();
//        xmlDoc.Save("users.xml");
//    }
//    return 0;
//}

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
                personalBudgetApp.userRegistration();
                break;
            case '2':
                personalBudgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
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
                personalBudgetApp.addIncome();
                break;
            case '2':
                personalBudgetApp.addExpense();
                break;
            case '3':
                personalBudgetApp.displayCurrenthMonthBalance();
                break;
            case '4':
                personalBudgetApp.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudgetApp.displaySelectedPeriodBalanace();
                break;
            case '6':
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
