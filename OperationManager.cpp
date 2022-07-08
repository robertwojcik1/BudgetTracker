#include "OperationManager.h"

void OperationManager::addIncomeWithCurrentDate(int LOGGED_IN_USER_ID)
{
    Income income;
    string date = "", incomeCategory = "";
    double incomeAmount = 0.0;
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
    income.setId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(AuxiliaryMethods::dateConversionToInt(date));
    income.setItem(incomeCategory);
    income.setAmount(incomeAmount);
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
}

void OperationManager::addIncomeWithEnteredDate(int LOGGED_IN_USER_ID)
{
    Income income;
    string date = "", incomeCategory = "";
    double incomeAmount = 0.0;
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
        income.setId(fileWithIncomes.getLastIncomeId() + 1);
        income.setUserId(LOGGED_IN_USER_ID);
        income.setDate(AuxiliaryMethods::dateConversionToInt(date));
        income.setItem(incomeCategory);
        income.setAmount(incomeAmount);
        incomes.push_back(income);

        fileWithIncomes.addIncomeToFile(income);
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

double OperationManager::enterIncomeAmount()
{
    double incomeAmount = 0.0;
    cout << "Wprowadz wysokosc przychodu: ";
    incomeAmount = AuxiliaryMethods::stringToDoubleConversion(AuxiliaryMethods::getLine());

    return incomeAmount;
}

void OperationManager::addIncome(int LOGGED_IN_USER_ID)
{
    char select;

    select = selectOptionFromAddIncomeMenu();

    switch(select)
    {
    case '1':
        OperationManager::addIncomeWithCurrentDate(LOGGED_IN_USER_ID);
        break;
    case '2':
        OperationManager::addIncomeWithEnteredDate(LOGGED_IN_USER_ID);
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

void OperationManager::addExpenseWithCurrentDate(int LOGGED_IN_USER_ID)
{
    Expense expense;
    string date = "", expenseCategory = "";
    double expenseAmount = 0.0;
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
    expense.setId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(AuxiliaryMethods::dateConversionToInt(date));
    expense.setItem(expenseCategory);
    expense.setAmount(expenseAmount);
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
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

double OperationManager::enterExpenseAmount()
{
    double expenseAmount = 0.0;
    cout << "Wprowadz wysokosc wydatku: ";
    expenseAmount = AuxiliaryMethods::stringToDoubleConversion(AuxiliaryMethods::getLine());

    return expenseAmount;
}

void OperationManager::addExpenseWithEnteredDate(int LOGGED_IN_USER_ID)
{
    Expense expense;
    string date = "", expenseCategory = "";
    double expenseAmount = 0.0;
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
        expense.setId(fileWithExpenses.getLastExpenseId() + 1);
        expense.setUserId(LOGGED_IN_USER_ID);
        expense.setDate(AuxiliaryMethods::dateConversionToInt(date));
        expense.setItem(expenseCategory);
        expense.setAmount(expenseAmount);
        expenses.push_back(expense);

        fileWithExpenses.addExpenseToFile(expense);
    }
    else
    {
        cout << "Wprowadzona data jest nieprawidlowa!" << endl;
        system("pause");
        return;
    }
}

void OperationManager::addExpense(int LOGGED_IN_USER_ID)
{
    char select;

    select = selectOptionFromAddExpenseMenu();

    switch(select)
    {
    case '1':
        OperationManager::addExpenseWithCurrentDate(LOGGED_IN_USER_ID);
        break;
    case '2':
        OperationManager::addExpenseWithEnteredDate(LOGGED_IN_USER_ID);
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
    double sumOfIncomes = 0.0, sumOfExpenses = 0.0, balance = 0.0;
    cout << "***BILANS Z BIEZACEGO MIESIACA***" << endl << endl;
    cout << "       >>> Przychody <<<" << endl;

    sort(incomes.begin(), incomes.end() );
    for(int i = 0; i < incomes.size(); i++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
    cout << "Kategoria przychodu: " << incomes[i].getItem() << endl;
    cout << "Kwota:               " << incomes[i].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfIncomes += incomes[i].getAmount();
    }
    cout << endl << "       >>> Wydatki <<<" << endl;

    sort(expenses.begin(), expenses.end() );
    for(int j = 0; j < expenses.size(); j++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
    cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
    cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfExpenses += expenses[j].getAmount();
    }
    balance = sumOfIncomes - sumOfExpenses;
    cout << endl << "Suma przychodow: " << sumOfIncomes << " zl" << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << " zl" << endl;
    cout << "Saldo: " << balance << " zl" << endl;
    system("pause");
}

void OperationManager::printBalanceFromPreviousMonth()
{
    double sumOfIncomes = 0.0, sumOfExpenses = 0.0, balance = 0.0;
    cout << "***BILANS Z POPRZEDNIEGO MIESIACA***" << endl << endl;
    cout << "       >>> Przychody <<<" << endl;

    sort(incomes.begin(), incomes.end() );
    for(int i = 0; i < incomes.size(); i++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
    cout << "Kategoria przychodu: " << incomes[i].getItem() << endl;
    cout << "Kwota:               " << incomes[i].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfIncomes += incomes[i].getAmount();
    }
    cout << endl << "       >>> Wydatki <<<" << endl;

    sort(expenses.begin(), expenses.end() );
    for(int j = 0; j < expenses.size(); j++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
    cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
    cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfExpenses += expenses[j].getAmount();
    }
    balance = sumOfIncomes - sumOfExpenses;
    cout << endl << "Suma przychodow: " << sumOfIncomes << " zl" << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << " zl" << endl;
    cout << "Saldo: " << balance << " zl" << endl;
    system("pause");
}

void OperationManager::printBalanceOfSelectedPeriod()
{
    double sumOfIncomes = 0.0, sumOfExpenses = 0.0, balance = 0.0;
    cout << "***BILANS Z WYBRANEGO OKRESU***" << endl << endl;
    cout << "       >>> Przychody <<<" << endl;

    sort(incomes.begin(), incomes.end() );
    for(int i = 0; i < incomes.size(); i++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
    cout << "Kategoria przychodu: " << incomes[i].getItem() << endl;
    cout << "Kwota:               " << incomes[i].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfIncomes += incomes[i].getAmount();
    }
    cout << endl << "       >>> Wydatki <<<" << endl;

    sort(expenses.begin(), expenses.end() );
    for(int j = 0; j < expenses.size(); j++)
    {
    cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
    cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
    cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
    cout << "****************" << endl;
    sumOfExpenses += expenses[j].getAmount();
    }
    balance = sumOfIncomes - sumOfExpenses;
    cout << endl << "Suma przychodow: " << sumOfIncomes << " zl" << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << " zl" << endl;
    cout << "Saldo: " << balance << " zl" << endl;
    system("pause");
}
