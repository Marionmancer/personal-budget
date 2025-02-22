#include <iostream>

#include "PersonalBudgetApp.h"
#include "Menus.h"

using namespace std;

int main3(){
    int lastId = 0;
    CMarkup xmlDoc;
    string userXmlFileName = "usesrs.xml";

    bool fileExists = xmlDoc.Load(userXmlFileName);

    if (!fileExists){
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("users");
        cout << "Nie ma takiego pliku. Utworzylem wiec nowy " << endl;
    }

    xmlDoc.ResetPos();
    xmlDoc.AddElem("users");
    cout << "Tutaj sie wywala" << endl;
    xmlDoc.FindElem("users");
    /*xmlDoc.AddChildElem("user");
    cout << "Tutaj sie wywala" << endl;
    xmlDoc.IntoElem(); // Tutaj jest blad
    xmlDoc.AddChildElem("id", lastId);
    xmlDoc.AddChildElem("login", user.login);
    xmlDoc.AddChildElem("password", user.password);
    xmlDoc.AddChildElem("name", user.name);
    xmlDoc.AddChildElem("surname", user.surname);*/

    xmlDoc.Save(userXmlFileName);

    return 0;
}

int main2(){
    int lastId = 0;
    CMarkup xmlDoc;

    if (xmlDoc.Load("users.xml")) {
        xmlDoc.AddElem("users");
        xmlDoc.FindElem();
        xmlDoc.IntoElem();
        while (xmlDoc.FindElem()){
            xmlDoc.FindChildElem("id");
            lastId = atoi(xmlDoc.GetChildData().c_str());
            cout << "Last id: " << lastId << endl;
        }
        xmlDoc.OutOfElem();
        xmlDoc.Save("users.xml");
    }
    return 0;
}

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
