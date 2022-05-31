#include <iostream>
#include "BudgetTracker.h"

using namespace std;

int main()
{
    BudgetTracker budgetTracker;
    char select;

    while(true)
    {
       // if(!budgetTracker.isUserLoggedIn())
        {
            select = budgetTracker.selectOptionFromMainMenu();

            switch(select)
            {
            case '1':
                budgetTracker.userRegister();
                break;
            case '2':
               // budgetTracker.userLogin();
                break;
            case '9':
                budgetTracker.exitProgram();
                break;
            default:
                budgetTracker.incorrectSelectOfMenuOptions();
                break;
            }
        }
    }
    return 0;
}
