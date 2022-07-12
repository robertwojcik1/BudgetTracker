#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Income.h"
#include "Expense.h"
#include "Date.h"
#include "AuxiliaryMethods.h"
#include "Markup.h" //

using namespace std;

class OperationManager
{
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    vector<Income> incomes;
    vector<Expense> expenses;
    const int LOGGED_IN_USER_ID;

    void addIncomeWithCurrentDate(int LOGGED_IN_USER_ID);
    void addIncomeWithEnteredDate(int LOGGED_IN_USER_ID);
    char selectIncomeCategory();
    string enterIncomeCategory();
    double enterIncomeAmount();
    char selectOptionFromAddExpenseMenu();
    void addExpenseWithCurrentDate(int LOGGED_IN_USER_ID);
    char selectExpenseCategory();
    string enterExpenseCategory();
    double enterExpenseAmount();
    void addExpenseWithEnteredDate(int LOGGED_IN_USER_ID);
public:
    OperationManager(string fileWithIncomesName, string fileWithExpensesName, int loggedInUserId) : fileWithIncomes(fileWithIncomesName), fileWithExpenses(fileWithExpensesName), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(incomes, LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(expenses, LOGGED_IN_USER_ID);
    };
    void addIncome(int LOGGED_IN_USER_ID);
    char selectOptionFromAddIncomeMenu();
    void addExpense(int LOGGED_IN_USER_ID);
    void printBalanceFromCurrentMonth();
    void printBalanceFromPreviousMonth();
    void printBalanceOfSelectedPeriod();
};

#endif
