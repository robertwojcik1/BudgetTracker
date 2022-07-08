#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    string amountString = AuxiliaryMethods::doubleToStringConversion(expense.getAmount());
    string date = AuxiliaryMethods::dateConversionToString(expense.getDate());
    expensesXml.Load(FILE_WITH_EXPENSES_NAME);
    expensesXml.ResetPos();
    expensesXml.FindElem();
    expensesXml.IntoElem();
    expensesXml.AddElem("Expense");
    expensesXml.IntoElem();
    expensesXml.AddElem("expenseId", expense.getId());
    expensesXml.AddElem("userId", expense.getUserId());
    expensesXml.AddElem("date", date);
    expensesXml.AddElem("item", expense.getItem());
    expensesXml.AddElem("amount", amountString);
    expensesXml.Save(FILE_WITH_EXPENSES_NAME);
    cout << "Pomyslnie dodano wydatek." << endl;
    system("pause");
}

int FileWithExpenses::getLastExpenseId()
{
    int expenseId = 0;
    expensesXml.Load( FILE_WITH_EXPENSES_NAME );
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

vector <Expense> FileWithExpenses::loadExpensesFromFile(vector <Expense> expenses, int LOGGED_IN_USER_ID)
{
    Expense expense;

    expensesXml.Load(FILE_WITH_EXPENSES_NAME);
    expensesXml.FindElem();
    expensesXml.IntoElem();
    while (expensesXml.FindElem("Expense"))
    {
        expensesXml.IntoElem();
        expensesXml.FindElem( "expenseId" );
        expense.setId(atoi( MCD_2PCSZ(expensesXml.GetData()) ));
        expensesXml.FindElem( "userId" );
        if(LOGGED_IN_USER_ID != atoi(MCD_2PCSZ(expensesXml.GetData()) ))
        {
            expensesXml.OutOfElem();
            continue;
        }
        expense.setUserId(atoi(MCD_2PCSZ(expensesXml.GetData()) ));
        expensesXml.FindElem( "date" );
        expense.setDate(AuxiliaryMethods::dateConversionToInt(expensesXml.GetData() ));
        expensesXml.FindElem( "item" );
        expense.setItem(expensesXml.GetData());
        expensesXml.FindElem( "amount" );
        expense.setAmount(stod(expensesXml.GetData()));
        expensesXml.OutOfElem();
        expenses.push_back(expense);
    }
    return expenses;
}
