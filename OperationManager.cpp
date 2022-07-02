#include "OperationManager.h"

void OperationManager::addIncomeWithCurrentDate(int loggedInUserId)
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
    income.setId(fileWithIncomes.getIncomeId() + 1);
    income.setUserId(loggedInUserId);
    income.setDate(date);
    income.setItem(incomeCategory);
    income.setAmount(incomeAmount);
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(loggedInUserId, date, incomeCategory, incomeAmount);
}

void OperationManager::addIncomeWithEnteredDate(int loggedInUserId)
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
        income.setId(fileWithIncomes.getIncomeId() + 1);
        income.setUserId(loggedInUserId);
        income.setDate(date);
        income.setItem(incomeCategory);
        income.setAmount(incomeAmount);
        incomes.push_back(income);

        fileWithIncomes.addIncomeToFile(loggedInUserId, date, incomeCategory, incomeAmount);
    }
    else
    {
        cout << "Wprowadzona data jest nieprawidlowa!" << endl;
        system("pause");
        return;
    }
}

char OperationManager::selectIncomeCategory()
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

string OperationManager::enterIncomeCategory()
{
    string newIncomeCategory = "";
    cout << "Wprowadz kategorie przychodu: ";
    newIncomeCategory = AuxiliaryMethods::getLine();

    return newIncomeCategory;
}

string OperationManager::enterIncomeAmount()
{
    string incomeAmount = "";
    cout << "Wprowadz wysokosc przychodu: ";
    incomeAmount = AuxiliaryMethods::getLine();

    return incomeAmount;
}

void OperationManager::addIncome(int loggedInUserId)
{
    char select;

    select = selectOptionFromAddIncomeMenu();

    switch(select)
    {
    case '1':
        OperationManager::addIncomeWithCurrentDate(loggedInUserId);
        break;
    case '2':
        OperationManager::addIncomeWithEnteredDate(loggedInUserId);
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
}

char OperationManager::selectOptionFromAddIncomeMenu()
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

char OperationManager::selectOptionFromAddExpenseMenu()
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

void OperationManager::addExpenseWithCurrentDate(int loggedInUserId)
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
    expense.setId(fileWithExpenses.getLastExpenseId());
    expense.setUserId(loggedInUserId);
    expense.setDate(date);
    expense.setItem(expenseCategory);
    expense.setAmount(expenseAmount);
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(loggedInUserId, date, expenseCategory, expenseAmount);
}

char OperationManager::selectExpenseCategory()
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

string OperationManager::enterExpenseCategory()
{
    string newExpenseCategory = "";
    cout << "Wprowadz kategorie wydatku: ";
    newExpenseCategory = AuxiliaryMethods::getLine();

    return newExpenseCategory;
}

string OperationManager::enterExpenseAmount()
{
    string expenseAmount = "";
    cout << "Wprowadz wysokosc wydatku: ";
    expenseAmount = AuxiliaryMethods::getLine();

    return expenseAmount;
}

void OperationManager::addExpenseWithEnteredDate(int loggedInUserId)
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
        expense.setId(fileWithExpenses.getLastExpenseId());
        expense.setUserId(loggedInUserId);
        expense.setDate(date);
        expense.setItem(expenseCategory);
        expense.setAmount(expenseAmount);
        expenses.push_back(expense);

        fileWithExpenses.addExpenseToFile(loggedInUserId, date, expenseCategory, expenseAmount);
    }
    else
    {
        cout << "Wprowadzona data jest nieprawidlowa!" << endl;
        system("pause");
        return;
    }
}

void OperationManager::addExpense(int loggedInUserId)
{
    char select;

    select = selectOptionFromAddExpenseMenu();

    switch(select)
    {
    case '1':
        OperationManager::addExpenseWithCurrentDate(loggedInUserId);
        break;
    case '2':
        OperationManager::addExpenseWithEnteredDate(loggedInUserId);
        break;
    case '9':
        return;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
    }
}

void OperationManager::printBalanceFromCurrentMonth()
{
    for(int i = 0; i < incomes.size(); i++)
    {
    cout << incomes[i].getId() << endl;
    cout << incomes[i].getUserId() << endl;
    cout << incomes[i].getDate() << endl;
    cout << incomes[i].getItem() << endl;
    cout << incomes[i].getAmount() << endl;
    cout << "******************************************" << endl;
    }
    system("pause");
    for(int j = 0; j < expenses.size(); j++)
    {
    cout << expenses[j].getId() << endl;
    cout << expenses[j].getUserId() << endl;
    cout << expenses[j].getDate() << endl;
    cout << expenses[j].getItem() << endl;
    cout << expenses[j].getAmount() << endl;
    cout << "******************************************" << endl;
    }
    system("pause");
}
