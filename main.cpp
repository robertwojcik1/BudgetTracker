#include <iostream>
#include "BudgetTracker.h"

using namespace std;

int main()
{
    BudgetTracker budgetTracker;
    char select;

    while(true)
    {
        if(!budgetTracker.isUserLoggedIn())
        {
            select = budgetTracker.selectOptionFromMainMenu();

            switch(select)
            {
            case '1':
                budgetTracker.userRegister();
                break;
            case '2':
                budgetTracker.userLogin();
                break;
            case '9':
                budgetTracker.exitProgram();
                break;
            default:
                budgetTracker.incorrectSelectOfMenuOptions();
                break;
            }
        }
        else
        {
            select = budgetTracker.selectOptionFromUserMenu();

            switch (select)
            {
            case '1':
                budgetTracker.addIncome();
                break;
            case '2':
                budgetTracker.addExpense();
                break;
            case '3':
                // budgetTracker.printBalanceFromCurrentMonth();
                break;
            case '4':
                // budgetTracker.printBalanceFromPreviousMonth();
                break;
            case '5':
                // budgetTracker.printBalanceOfSelectedPeriod();
                break;
            case '6':
                budgetTracker.changePassword();
                break;
            case '7':
                budgetTracker.logOut();
                break;
            default:
                budgetTracker.incorrectSelectOfMenuOptions();
                break;
            }
        }
    }
    return 0;
}
