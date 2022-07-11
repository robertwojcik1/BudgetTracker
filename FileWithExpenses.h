#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses
{
    const string FILE_WITH_EXPENSES_NAME;

public:
    FileWithExpenses(string fileWithExpensesName) : FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
    {};
    void addExpenseToFile(Expense expense);
    int getLastExpenseId();
    vector <Expense> loadExpensesFromFile(vector <Expense> expenses, int LOGGED_IN_USER_ID);
};

#endif
