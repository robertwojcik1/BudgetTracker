#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetTracker
{
    UserManager userManager;
    OperationManager *operationManager;

public:
    BudgetTracker()
    {
    operationManager = NULL;
    };
    ~BudgetTracker()
    {
        delete operationManager;
        operationManager = NULL;
    };
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    void userRegister();
    void userLogin();
    void exitProgram();
    void incorrectSelectOfMenuOptions();
    char selectOptionFromUserMenu();
    void logOut();
    void changePassword();
    void addIncome();
    void addExpense();
    void printBalanceFromCurrentMonth();
    void printBalanceFromPreviousMonth();
    void printBalanceOfSelectedPeriod();
};

#endif
