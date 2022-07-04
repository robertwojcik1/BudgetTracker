#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(int loggedInUserId, string date, string incomeCategory, double incomeAmount)
{
    string amountString = doubleToStringConversion(incomeAmount);
    incomeId++;
    incomesXml.Load("incomes.xml");
    incomesXml.ResetPos();
    incomesXml.FindElem("Incomes");
    incomesXml.IntoElem();
    incomesXml.AddElem("Income");
    incomesXml.IntoElem();
    incomesXml.AddElem("incomeId", incomeId);
    incomesXml.AddElem("userId", loggedInUserId);
    incomesXml.AddElem("date", date);
    incomesXml.AddElem("item", incomeCategory);
    incomesXml.AddElem("amount", amountString);
    incomesXml.OutOfElem();
    //incomesXml.ResetPos();
    incomesXml.Save("incomes.xml");
    cout << "Pomyslnie dodano przychod." << endl;
    system("pause");
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

vector<Income> FileWithIncomes::loadIncomesFromFile()
{
    Income income;
    vector <Income> incomes;

    incomesXml.Load("incomes.xml");
    incomesXml.FindElem();
    incomesXml.IntoElem();
    while (incomesXml.FindElem("Income"))
    {
        incomesXml.IntoElem();
        incomesXml.FindElem( "incomeId" );
        income.setId(atoi( MCD_2PCSZ(incomesXml.GetData()) ));
        incomesXml.FindElem( "userId" );
        income.setUserId(atoi(MCD_2PCSZ(incomesXml.GetData()) ));
        incomesXml.FindElem( "date" );
        income.setDate(incomesXml.GetData());
        incomesXml.FindElem( "item" );
        income.setItem(incomesXml.GetData());
        incomesXml.FindElem( "amount" );
        income.setAmount(stod(incomesXml.GetData()));
        incomesXml.OutOfElem();
        incomes.push_back(income);
    }
    return incomes;
}

int FileWithIncomes::getIncomeId()
{
    return incomeId;
}

string FileWithIncomes::doubleToStringConversion(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
