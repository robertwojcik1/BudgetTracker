#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup incomesXml;

    incomesXml.Load(FILE_WITH_INCOMES_NAME);
    if(!incomesXml.FindElem("Incomes"))
    {
        incomesXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        incomesXml.AddElem("Incomes");
    }

    string amountString = AuxiliaryMethods::doubleToStringConversion(income.getAmount());
    string date = AuxiliaryMethods::dateConversionToString(income.getDate());

    incomesXml.IntoElem();
    incomesXml.AddElem("Income");
    incomesXml.IntoElem();
    incomesXml.AddElem("incomeId", income.getId());
    incomesXml.AddElem("userId", income.getUserId());
    incomesXml.AddElem("date", date);
    incomesXml.AddElem("item", income.getItem());
    incomesXml.AddElem("amount", amountString);
    incomesXml.OutOfElem();
    incomesXml.Save(FILE_WITH_INCOMES_NAME);
    cout << "Pomyslnie dodano przychod." << endl;
    system("pause");
}

int FileWithIncomes::getLastIncomeId()
{
    CMarkup incomesXml;
    int incomeId = 0;

    incomesXml.Load(FILE_WITH_INCOMES_NAME);
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

vector<Income> FileWithIncomes::loadIncomesFromFile(vector<Income> incomes, int LOGGED_IN_USER_ID)
{
    CMarkup incomesXml;
    Income income;

    bool fileExists = incomesXml.Load(FILE_WITH_INCOMES_NAME);
    if(fileExists)
    {
        incomesXml.FindElem();
        incomesXml.IntoElem();
        while (incomesXml.FindElem("Income"))
        {
            incomesXml.IntoElem();
            incomesXml.FindElem( "incomeId" );
            income.setId(atoi( MCD_2PCSZ(incomesXml.GetData()) ));
            incomesXml.FindElem( "userId" );
            if(LOGGED_IN_USER_ID != atoi(MCD_2PCSZ(incomesXml.GetData()) ))
            {
                incomesXml.OutOfElem();
                continue;
            }
            income.setUserId(atoi(MCD_2PCSZ(incomesXml.GetData()) ));
            incomesXml.FindElem( "date" );
            income.setDate(AuxiliaryMethods::dateConversionToInt(incomesXml.GetData() ));
            incomesXml.FindElem( "item" );
            income.setItem(incomesXml.GetData());
            incomesXml.FindElem( "amount" );
            income.setAmount(stod(incomesXml.GetData()));
            incomesXml.OutOfElem();
            incomes.push_back(income);
        }
        return incomes;
    }
    else
    {
        cout << "Nie odnaleziono pliku z przychodami!" << endl;
        system("pause");
        return incomes;
    }
}
