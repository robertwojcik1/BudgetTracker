#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes
{
    const string FILE_WITH_INCOMES_NAME;

public:
    FileWithIncomes(string fileWithIncomesName) : FILE_WITH_INCOMES_NAME(fileWithIncomesName)
    {};
    void addIncomeToFile(Income income);
    int getLastIncomeId();
    vector<Income> loadIncomesFromFile(vector<Income> incomes, int LOGGED_IN_USER_ID);
};

#endif
