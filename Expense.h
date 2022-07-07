#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "BudgetOperation.h"

using namespace std;

class Expense : public BudgetOperation
{
    int lastIncomeId;
public:
    Expense(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0)
    {

    }
};

#endif
