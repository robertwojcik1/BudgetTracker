#include "BudgetOperation.h"

int BudgetOperation::getId()
{
    return id;
}

int BudgetOperation::getUserId()
{
    return userId;
}

string BudgetOperation::getDate()
{
    return date;
}

string BudgetOperation::getItem()
{
    return item;
}

string BudgetOperation::getAmount()
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

void BudgetOperation::setDate(string date)
{
    this->date = date;
}

void BudgetOperation::setItem(string item)
{
    this->item = item;
}

void BudgetOperation::setAmount(string amount)
{
    this->amount = amount;
}
