#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses
{
    CMarkup expensesXml;
    const string FILE_WITH_EXPENSES_NAME;
    int expenseId;
public:
    FileWithExpenses(string fileWithExpensesName) : FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
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
    vector <Expense> loadExpensesFromFile(vector <Expense> expenses, int LOGGED_IN_USER_ID);
};

#endif
