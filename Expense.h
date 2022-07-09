#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include "BudgetOperation.h"

using namespace std;

class Expense : public BudgetOperation
{

public:
    Expense(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0)
    {};
};

#endif
