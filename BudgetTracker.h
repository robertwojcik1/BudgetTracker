#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>

using namespace std;

class BudgetTracker
{

public:
    bool isUserLoggedIn();
    char selectoptionFromMainMenu();
    void userRegister();
    void userLogin();
    void exitProgram();
    void incorrectSelectOfMenuOptions();
};

#endif
