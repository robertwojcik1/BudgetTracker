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
    CMarkup incomesXml;
    const string FILE_WITH_INCOMES_NAME;

public:
    FileWithIncomes(string fileWithIncomesName) : FILE_WITH_INCOMES_NAME(fileWithIncomesName)
    {
        bool fileExists = incomesXml.Load( FILE_WITH_INCOMES_NAME );

        if (!fileExists)
        {
            incomesXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            incomesXml.AddElem("Incomes");
        }
    };
    void addIncomeToFile(Income income);
    int getLastIncomeId();
    vector<Income> loadIncomesFromFile(vector<Income> incomes, int LOGGED_IN_USER_ID);
};

#endif
