#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile( int loggedInUserId, string date, string expenseCategory, string expenseAmount)
{
    expenseId++;
    expensesXml.ResetPos();
    expensesXml.FindElem();
    expensesXml.IntoElem();
    expensesXml.AddElem("Expense");
    expensesXml.IntoElem();
    expensesXml.AddElem("expenseId", expenseId);
    expensesXml.AddElem("userId", loggedInUserId);
    expensesXml.AddElem("date", date);
    expensesXml.AddElem("item", expenseCategory);
    expensesXml.AddElem("amount", expenseAmount);
    expensesXml.ResetPos();
    expensesXml.Save("expenses.xml");
    cout << "Pomyslnie dodano wydatek." << endl;
    system("pause");
}

int FileWithExpenses::getLastExpenseId()
{
    expensesXml.FindElem();
    expensesXml.IntoElem();
    while ( expensesXml.FindElem("Expense") )
    {
        expensesXml.IntoElem();
        expensesXml.FindElem( "expenseId" );
        expenseId = atoi( MCD_2PCSZ(expensesXml.GetData()) );
        expensesXml.OutOfElem();
    }
    return expenseId;
}
