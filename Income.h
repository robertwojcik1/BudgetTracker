#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include <vector>
#include "BudgetOperation.h"

using namespace std;

class Income : public BudgetOperation
{

public:
    Income(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0)
    {};
};

#endif
