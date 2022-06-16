#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include "BudgetOperation.h"
#include "FileWithExpenses.h"

using namespace std;

class Expense : public BudgetOperation
{
    FileWithExpenses fileWithExpenses;
    vector<Expense> expenses;
};

#endif
