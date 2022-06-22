#include "Expense.h"

void Expense::addExpense(int loggedInUserId)
{
    char select;

    select = selectOptionFromAddExpenseMenu();

    switch(select)
    {
    case '1':
        Expense::addExpenseWithCurrentDate(loggedInUserId);
        break;
    case '2':
        Expense::addExpenseWithEnteredDate(loggedInUserId);
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
}

char Expense::selectOptionFromAddExpenseMenu()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << "  >>> DODAJ WYDATEK <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Z dnia dzisiejszego" << endl;
    cout << "2. Z inna data" << endl;
    cout << "9. Wroc do menu uzytkownika" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

void Expense::addExpenseWithCurrentDate(int loggedInUserId)
{
    Expense expense;
    string date = "", expenseCategory = "", expenseAmount = "";
    char select;
    date = Date::getCurrentDate();
    select = selectExpenseCategory();
    switch(select)
    {
    case '1':
        expenseCategory = "Rachunki";
        break;
    case '2':
        expenseCategory = "Kredyt";
        break;
    case '3':
        expenseCategory = "Raty";
        break;
    case '4':
        expenseCategory = "Zakupy";
        break;
    case '5':
        expenseCategory = enterExpenseCategory();
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
    expenseAmount = enterExpenseAmount();
    fileWithExpenses.addExpenseToFile(loggedInUserId, date, expenseCategory, expenseAmount);
}

char Expense::selectExpenseCategory()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << ">>> KATEGORIA WYDATKU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rachunki" << endl;
    cout << "2. Kredyt" << endl;
    cout << "3. Raty" << endl;
    cout << "4. Zakupy" << endl;
    cout << "5. Inne" << endl;
    cout << "9. Wroc do menu uzytkownika" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

string Expense::enterExpenseCategory()
{
    string newExpenseCategory = "";
    cout << "Wprowadz kategorie wydatku: ";
    newExpenseCategory = AuxiliaryMethods::getLine();

    return newExpenseCategory;
}

string Expense::enterExpenseAmount()
{
    string expenseAmount = "";
    cout << "Wprowadz wysokosc wydatku: ";
    expenseAmount = AuxiliaryMethods::getLine();

    return expenseAmount;
}

void Expense::addExpenseWithEnteredDate(int loggedInUserId)
{
    Expense expense;
    string date = "", expenseCategory = "", expenseAmount = "";
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << "Wpisz date w formacie rrrr-mm-dd: ";
    date = AuxiliaryMethods::getLine();

    if(Date::isDateCorrect(date))
    {
        select = selectExpenseCategory();
        switch(select)
        {
        case '1':
            expenseCategory = "Rachunki";
            break;
        case '2':
            expenseCategory = "Kredyt";
            break;
        case '3':
            expenseCategory = "Raty";
            break;
        case '4':
            expenseCategory = "Zakupy";
            break;
        case '5':
            expenseCategory = enterExpenseCategory();
            break;
        case '9':
            return;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
        }
        expenseAmount = enterExpenseAmount();
        fileWithExpenses.addExpenseToFile(loggedInUserId, date, expenseCategory, expenseAmount);
    }
    else
    {
        cout << "Wprowadzona data jest nieprawidlowa!" << endl;
        system("pause");
        return;
    }
}
