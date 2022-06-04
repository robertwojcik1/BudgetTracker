#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(int loggedInUserId, string date, string incomeCategory, string incomeAmount)
{
    incomeId++;
    incomesXml.ResetPos();
    incomesXml.FindElem();
    incomesXml.IntoElem();
    incomesXml.AddElem("Income");
    incomesXml.IntoElem();
    incomesXml.AddElem("incomeId", incomeId);
    incomesXml.AddElem("userId", loggedInUserId);
    incomesXml.AddElem("date", date);
    incomesXml.AddElem("item", incomeCategory);
    incomesXml.AddElem("amount", incomeAmount);
    incomesXml.ResetPos();
    incomesXml.Save("incomes.xml");
}

int FileWithIncomes::getLastIncomeId()
{
    incomesXml.FindElem();
    incomesXml.IntoElem();
    while ( incomesXml.FindElem("Income") )
    {
        incomesXml.IntoElem();
        incomesXml.FindElem( "incomeId" );
        incomeId = atoi( MCD_2PCSZ(incomesXml.GetData()) );
        incomesXml.OutOfElem();
    }
    return incomeId;
}
