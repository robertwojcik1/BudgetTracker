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

int FileWithExpenses::getExpenseId()
{
    return expenseId;
}

vector <Expense> FileWithExpenses::loadExpensesFromFile()
{
    Expense expense;
    vector <Expense> expenses;

    expensesXml.Load("expenses.xml");
    expensesXml.FindElem();
    expensesXml.IntoElem();
    while (expensesXml.FindElem("Expense"))
    {
        expensesXml.IntoElem();
        expensesXml.FindElem( "expenseId" );
        expense.setId(atoi( MCD_2PCSZ(expensesXml.GetData()) ));
        expensesXml.FindElem( "userId" );
        expense.setUserId(atoi(MCD_2PCSZ(expensesXml.GetData()) ));
        expensesXml.FindElem( "date" );
        expense.setDate(expensesXml.GetData());
        expensesXml.FindElem( "item" );
        expense.setItem(expensesXml.GetData());
        expensesXml.FindElem( "amount" );
        expense.setAmount(expensesXml.GetData());
        expensesXml.OutOfElem();
        expenses.push_back(expense);
    }
    return expenses;
}
