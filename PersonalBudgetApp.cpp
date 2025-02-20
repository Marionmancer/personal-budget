#include "PersonalBudgetApp.h"

void PersonalBudgetApp::loginUser(){
    userManager.loginUser();
    if (userManager.isUserLoggedIn())   {
        balanceManager = new BalanceManager(userManager.getLoggedInUserId(), INCOMES_FILE_NAME, EXPENSES_FILE_NAME);
    }
}

void PersonalBudgetApp::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudgetApp::loggedInUserPasswordChange(){

}

void PersonalBudgetApp::userLogout(){

}

void PersonalBudgetApp::addIncome(){

}

void PersonalBudgetApp::addExpense(){

}

void PersonalBudgetApp::displayCurrenthMonthBalance(){

}

void PersonalBudgetApp::displayPreviousMonthBalance(){

}

void PersonalBudgetApp::displaySelectedPeriodBalanace(){

}

bool PersonalBudgetApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}
