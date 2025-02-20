#include <iostream>

#include "PersonalBudgetApp.h"
#include "Menus.h"

using namespace std;

int main()
{
    //PersonalBudgetApp personalBudgetApp("users.txt","incomes.txt", "expenses.txt");
    char choice;

    while (true)
    {
        if (/*personalBudgetApp.isUserLoggedIn() == false*/true)
        {
            choice = Menus::mainMenuDisplay();

            switch (choice)
            {
            case '1':
                //personalBudgetApp.rejestracjaUzytkownika();
                break;
            case '2':
                //personalBudgetApp.logowanieUzytkownika();
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
            choice = Menus::balanceManagerMenuDisplay();

            switch (choice)
            {
            case '1':
                //personalBudgetApp.dodajAdresata();
                break;
            case '2':
                //personalBudgetApp.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //personalBudgetApp.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //personalBudgetApp.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //personalBudgetApp.usunAdresata();
                break;
            case '6':
                //personalBudgetApp.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                //personalBudgetApp.wylogujUzytkownika();
                break;
            }
        }
    }
    return 0;
}
