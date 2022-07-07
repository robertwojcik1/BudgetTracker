#include "BudgetOperation.h"

int BudgetOperation::getId()
{
    return id;
}

int BudgetOperation::getUserId()
{
    return userId;
}

int BudgetOperation::getDate()
{
    return date;
}

string BudgetOperation::getItem()
{
    return item;
}

double BudgetOperation::getAmount()
{
    return amount;
}

void BudgetOperation::setId(int id)
{
    if(id > 0)
        this->id = id;
}

void BudgetOperation::setUserId(int userId)
{
    if(userId > 0)
        this->userId = userId;
}

void BudgetOperation::setDate(int date)
{
    this->date = date;
}

void BudgetOperation::setItem(string item)
{
    this->item = item;
}

void BudgetOperation::setAmount(double amount)
{
    this->amount = amount;
}

bool BudgetOperation::operator <( BudgetOperation& rhs)
{
    return this->getDate() < rhs.getDate();
}
