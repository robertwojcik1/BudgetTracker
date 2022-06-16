#include "Income.h"

void Income::addIncome(int loggedInUserId)
{
    char select;

    select = selectOptionFromAddIncomeMenu();

    switch(select)
    {
    case '1':
        Income::addIncomeWithCurrentDate(loggedInUserId);
        break;
    case '2':
        Income::addIncomeWithEnteredDate(loggedInUserId);
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
}

char Income::selectOptionFromAddIncomeMenu()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << "  >>> DODAJ PRZYCHOD <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Z dnia dzisiejszego" << endl;
    cout << "2. Z inna data" << endl;
    cout << "9. Wroc do menu uzytkownika" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

void Income::addIncomeWithCurrentDate(int loggedInUserId)
{
    Income income;
    string date = "", incomeCategory = "", incomeAmount = "";
    char select;
    date = Date::getCurrentDate();
    select = selectIncomeCategory();
    switch(select)
    {
    case '1':
        incomeCategory = "Wyplata";
        break;
    case '2':
        incomeCategory = "Sprzedaz internetowa";
        break;
    case '3':
        incomeCategory = enterIncomeCategory();
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
    incomeAmount = enterIncomeAmount();
    fileWithIncomes.addIncomeToFile(loggedInUserId, date, incomeCategory, incomeAmount);
}

char Income::selectIncomeCategory()
{
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << ">>> KATEGORIA PRZYCHODU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Wyplata" << endl;
    cout << "2. Sprzedaz internetowa" << endl;
    cout << "3. Inne" << endl;
    cout << "9. Wroc do menu uzytkownika" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::getChar();

    return select;
}

string Income::enterIncomeCategory()
{
    string newIncomeCategory = "";
    cout << "Wprowadz kategorie przychodu: ";
    newIncomeCategory = AuxiliaryMethods::getLine();

    return newIncomeCategory;
}

string Income::enterIncomeAmount()
{
    string incomeAmount = "";
    cout << "Wprowadz wysokosc przychodu: ";
    incomeAmount = AuxiliaryMethods::getLine();

    return incomeAmount;
}

void Income::addIncomeWithEnteredDate(int loggedInUserId)
{
    Income income;
    string date = "", incomeCategory = "", incomeAmount = "";
    char select;

    system("cls");
    cout << " ***APLIKACJA BUDZETOWA***    " << endl;
    cout << "Wpisz date w formacie rrrr-mm-dd: ";
    date = AuxiliaryMethods::getLine();

    if(Date::isDateCorrect(date))
    {
        select = selectIncomeCategory();
        switch(select)
        {
        case '1':
            incomeCategory = "Wyplata";
            break;
        case '2':
            incomeCategory = "Sprzedaz internetowa";
            break;
        case '3':
            incomeCategory = enterIncomeCategory();
            break;
        case '9':
            return;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
        }
        incomeAmount = enterIncomeAmount();
        fileWithIncomes.addIncomeToFile(loggedInUserId, date, incomeCategory, incomeAmount);
    }
    else
    {
        cout << "Wprowadzona data jest nieprawidlowa!" << endl;
        system("pause");
        return;
    }
}

