#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetTracker
{
    UserManager userManager;

public:
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
};

#endif
