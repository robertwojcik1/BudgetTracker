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
    const string FILE_WITH_INCOMES_NAME;
    const string FILE_WITH_EXPENSES_NAME;

public:
    BudgetTracker(string fileWithUsersName, string fileWithIncomesName, string fileWithExpensesName) : userManager(fileWithUsersName), FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
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
