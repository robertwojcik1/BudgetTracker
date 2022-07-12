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

    incomeAmount = enterAmount();
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

    while(true)
    {
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
            incomeAmount = enterAmount();
            income.setId(fileWithIncomes.getLastIncomeId() + 1);
            income.setUserId(LOGGED_IN_USER_ID);
            income.setDate(AuxiliaryMethods::dateConversionToInt(date));
            income.setItem(incomeCategory);
            income.setAmount(incomeAmount);
            incomes.push_back(income);

            fileWithIncomes.addIncomeToFile(income);
            return;
        }
        else
        {
            cout << "Wprowadzona data jest nieprawidlowa! Sprobuj ponownie." << endl;
            system("pause");
        }
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

double OperationManager::enterAmount()
{
    double amount = 0.0;
    string amountStr = "";

    while(true)
    {
        system("cls");
        cout << "Wprowadz kwote operacji: ";
        amountStr = AuxiliaryMethods::getLine();

        if(AuxiliaryMethods::checkIfAmountIsCorrect(amountStr))
        {
            amount = AuxiliaryMethods::stringToDoubleConversion(amountStr);
            return amount;
        }
        else
        {
            cout << "Wprowadzono nieprawidlowa kwote. Kwota musi sie skladac wylacznie z cyfr oraz przecinka lub kropki. Wprowadz ponownie." << endl;
            system("pause");
        }
    }
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
    expenseAmount = enterAmount();
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

void OperationManager::addExpenseWithEnteredDate(int LOGGED_IN_USER_ID)
{
    Expense expense;
    string date = "", expenseCategory = "";
    double expenseAmount = 0.0;
    char select;

    while(true)
    {
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
            expenseAmount = enterAmount();
            expense.setId(fileWithExpenses.getLastExpenseId() + 1);
            expense.setUserId(LOGGED_IN_USER_ID);
            expense.setDate(AuxiliaryMethods::dateConversionToInt(date));
            expense.setItem(expenseCategory);
            expense.setAmount(expenseAmount);
            expenses.push_back(expense);

            fileWithExpenses.addExpenseToFile(expense);
            return;
        }
        else
        {
            cout << "Wprowadzona data jest nieprawidlowa! Sprobuj ponownie." << endl;
            system("pause");
        }
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
    string date = Date::getCurrentDate();
    string month = Date::getMonthFromDate(date);
    string year = Date::getYearFromDate(date);
    int lowerLimit = AuxiliaryMethods::stringToIntConversion(year+month+"01");
    int upperLimit = AuxiliaryMethods::stringToIntConversion(year+month+"31");
    system("cls");
    cout << "***BILANS Z BIEZACEGO MIESIACA***" << endl << endl;
    cout << "       >>> Przychody <<<" << endl;

    sort(incomes.begin(), incomes.end() );
    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= lowerLimit && incomes[i].getDate() <= upperLimit)
        {
            cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
            cout << "Kategoria przychodu: " << incomes[i].getItem() << endl << fixed;
            cout << "Kwota:               " << setprecision(2) <<incomes[i].getAmount() << " zl" << endl;
            cout << "****************" << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl << "       >>> Wydatki <<<" << endl;

    sort(expenses.begin(), expenses.end() );
    for(int j = 0; j < expenses.size(); j++)
    {
        if(expenses[j].getDate() >= lowerLimit && expenses[j].getDate() <= upperLimit)
        {
            cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
            cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
            cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
            cout << "****************" << endl;
            sumOfExpenses += expenses[j].getAmount();
        }
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
    string date = Date::getCurrentDate();
    string month = Date::getMonthFromDate(date);
    string year = Date::getYearFromDate(date);
    string previousMonth = Date::getPreviousMonth(month);
    if(previousMonth == "12")
        year = Date::getPreviousYear(year);

    int lowerLimit = AuxiliaryMethods::stringToIntConversion(year+previousMonth+"01");
    int upperLimit = AuxiliaryMethods::stringToIntConversion(year+previousMonth+"31");
    system("cls");
    cout << "***BILANS Z POPRZEDNIEGO MIESIACA***" << endl << endl;
    cout << "       >>> Przychody <<<" << endl;

    sort(incomes.begin(), incomes.end() );
    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= lowerLimit && incomes[i].getDate() <= upperLimit)
        {
            cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
            cout << "Kategoria przychodu: " << incomes[i].getItem() << endl << fixed;
            cout << "Kwota:               " << setprecision(2) << incomes[i].getAmount() << " zl" << endl;
            cout << "****************" << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl << "       >>> Wydatki <<<" << endl;

    sort(expenses.begin(), expenses.end() );
    for(int j = 0; j < expenses.size(); j++)
    {
        if(expenses[j].getDate() >= lowerLimit && expenses[j].getDate() <= upperLimit)
        {
            cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
            cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
            cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
            cout << "****************" << endl;
            sumOfExpenses += expenses[j].getAmount();
        }
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

    while(true)
    {
        system("cls");
        cout << "***BILANS Z WYBRANEGO OKRESU***" << endl << endl;
        cout << "Wpisz date poczatkowa w formacie rrrr-mm-dd: ";
        string initialDate = AuxiliaryMethods::getLine();
        cout << "Wpisz date koncowa w formacie rrrr-mm-dd: ";
        string finalDate = AuxiliaryMethods::getLine();

        if(Date::isDateCorrect(initialDate) && Date::isDateCorrect(finalDate))
        {
            int initialDateInt = AuxiliaryMethods::dateConversionToInt(initialDate);
            int finalDateInt = AuxiliaryMethods::dateConversionToInt(finalDate);

            if(initialDateInt <= finalDateInt)
            {
                cout << "       >>> Przychody <<<" << endl;
                sort(incomes.begin(), incomes.end() );
                for(int i = 0; i < incomes.size(); i++)
                {
                    if(incomes[i].getDate() >= initialDateInt && incomes[i].getDate() <= finalDateInt)
                    {
                        cout << "Data:                " << AuxiliaryMethods::dateConversionToString(incomes[i].getDate()) << endl;
                        cout << "Kategoria przychodu: " << incomes[i].getItem() << endl <<fixed;
                        cout << "Kwota:               " << setprecision(2) << incomes[i].getAmount() << " zl" << endl;
                        cout << "****************" << endl;
                        sumOfIncomes += incomes[i].getAmount();
                    }
                }
                cout << endl << "       >>> Wydatki <<<" << endl;

                sort(expenses.begin(), expenses.end() );
                for(int j = 0; j < expenses.size(); j++)
                {
                    if(expenses[j].getDate() >= initialDateInt && expenses[j].getDate() <= finalDateInt)
                    {
                        cout << "Data:                " << AuxiliaryMethods::dateConversionToString(expenses[j].getDate()) << endl;
                        cout << "Kategoria wydatku:   " << expenses[j].getItem() << endl;
                        cout << "Kwota:               " << expenses[j].getAmount() << " zl" << endl;
                        cout << "****************" << endl;
                        sumOfExpenses += expenses[j].getAmount();
                    }
                }
                balance = sumOfIncomes - sumOfExpenses;
                cout << endl << "Suma przychodow: " << sumOfIncomes << " zl" << endl;
                cout << "Suma wydatkow: " << sumOfExpenses << " zl" << endl;
                cout << "Saldo: " << balance << " zl" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Data koncowa jest wczesniejsza niz poczatkowa! Wpisz ponownie daty." << endl;
                system("pause");
            }
        }
        else
        {
            cout << "Wprowadziles niepoprawne daty! Sprobuj ponownie." << endl;
            system("pause");
        }
    }
}
