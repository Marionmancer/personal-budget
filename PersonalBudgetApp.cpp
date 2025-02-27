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
    if (userManager.getLoggedInUserId()!=0) {
        userManager.loggedInUserPasswordChange();
    }
}

void PersonalBudgetApp::userLogout(){
    userManager.setloggedInUserId(0);
    delete balanceManager;
    balanceManager = NULL;
}

void PersonalBudgetApp::addIncome(){
    balanceManager->addIncome();
}

void PersonalBudgetApp::addExpense(){
    balanceManager->addExpense();
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
