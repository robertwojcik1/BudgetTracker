#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H
#include <iostream>
#include <vector>
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Income.h"
#include "Expense.h"
#include "Date.h"
#include "AuxiliaryMethods.h"

using namespace std;

class OperationManager
{
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    vector<Income> incomes;
    vector<Expense> expenses;

    void addIncomeWithCurrentDate(int loggedInUserId);
    void addIncomeWithEnteredDate(int loggedInUserId);
    char selectIncomeCategory();
    string enterIncomeCategory();
    string enterIncomeAmount();
    char selectOptionFromAddExpenseMenu();
    void addExpenseWithCurrentDate(int loggedInUserId);
    char selectExpenseCategory();
    string enterExpenseCategory();
    string enterExpenseAmount();
    void addExpenseWithEnteredDate(int loggedInUserId);
public:
    OperationManager()
    {
        incomes = fileWithIncomes.loadIncomesFromFile();
        expenses = fileWithExpenses.loadExpensesFromFile();
    }

    void addIncome(int loggedInUserId);
    char selectOptionFromAddIncomeMenu();
    void addExpense(int loggedInUserId);
    void printBalanceFromCurrentMonth();
};

#endif
