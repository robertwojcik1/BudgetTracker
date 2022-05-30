#include "BudgetTracker.h"

char BudgetTracker::selectOptionFromMainMenu()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << "   >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

void BudgetTracker::exitProgram()
{
    cout << "Koniec programu." << endl;
    exit(0);
}

void BudgetTracker::userRegister()
{
    userManager.userRegister();
}
