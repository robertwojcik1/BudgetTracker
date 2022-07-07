#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "BudgetOperation.h"

using namespace std;

class Income : public BudgetOperation
{
    //int incomeId;
    int lastIncomeId;

public:
    Income(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0)
    {

    }
    //bool operator <( Income& rhs);
};

#endif
