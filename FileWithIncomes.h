#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include "Markup.h"

using namespace std;

class FileWithIncomes
{
    CMarkup incomesXml;
    int incomeId;
   // int lastIncomeId;
public:
    FileWithIncomes()
    {
    bool fileExists = incomesXml.Load( "incomes.xml" );

        if (!fileExists)
        {
            incomesXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            incomesXml.AddElem("Incomes");
            incomeId = 0;
        }
        else
          incomeId = getLastIncomeId();
    }
    void addIncomeToFile( int loggedInUserId, string date, string incomeCategory, string incomeAmount);
    int getLastIncomeId();
};

#endif
