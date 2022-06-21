#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "BudgetOperation.h"
#include "FileWithExpenses.h"

using namespace std;

class Expense : public BudgetOperation
{
    FileWithExpenses fileWithExpenses;
    vector<Expense> expenses;

    char selectOptionFromAddExpenseMenu();
    void addExpenseWithCurrentDate(int loggedInUserId);
    char selectExpenseCategory();
    string enterExpenseCategory();
    string enterExpenseAmount();
public:
    void addExpense(int loggedInUserId);
};

#endif
