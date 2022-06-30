#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "BudgetOperation.h"
#include "FileWithIncomes.h"

using namespace std;

class Income : public BudgetOperation
{
    FileWithIncomes fileWithIncomes;
    vector<Income> incomes;
    //int incomeId;
    int lastIncomeId;

    void addIncomeWithCurrentDate(int loggedInUserId);
    void addIncomeWithEnteredDate(int loggedInUserId);
    char selectIncomeCategory();
    string enterIncomeCategory();
    string enterIncomeAmount();
public:
    Income(int id = 0, int userId = 0, string date = "", string item = "", string amount = "")
    {

    }
    void addIncome(int loggedInUserId);
    char selectOptionFromAddIncomeMenu();

};

#endif
