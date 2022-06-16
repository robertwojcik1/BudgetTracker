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

void BudgetTracker::incorrectSelectOfMenuOptions()
{
    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
    system("pause");
}

bool BudgetTracker::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetTracker::userLogin()
{
    userManager.userLogin();
}

char BudgetTracker::selectOptionFromUserMenu()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << " >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

void BudgetTracker::logOut()
{
    userManager.logOut();
}

void BudgetTracker::changePassword()
{
    userManager.changePassword();
}

void BudgetTracker::addIncome()
{
    userManager.addIncome();
}
