#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include "Markup.h"
#include "Expense.h"

using namespace std;

class FileWithExpenses
{
    CMarkup expensesXml;
    int expenseId;

    string doubleToStringConversion(double number);
public:
    FileWithExpenses()
    {
    bool fileExists = expensesXml.Load( "expenses.xml" );

        if (!fileExists)
        {
            expensesXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            expensesXml.AddElem("Expenses");
            expenseId = 0;
        }
        else
          expenseId = getLastExpenseId();
    }
    void addExpenseToFile( int loggedInUserId, string date, string expenseCategory, double expenseAmount);
    int getLastExpenseId();
    int getExpenseId();
    vector <Expense> loadExpensesFromFile();
};

#endif
