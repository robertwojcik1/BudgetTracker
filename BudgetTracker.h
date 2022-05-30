#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetTracker
{

public:
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    void userRegister();
    void userLogin();
    void exitProgram();
    void incorrectSelectOfMenuOptions();
};

#endif
