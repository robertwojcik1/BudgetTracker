#ifndef BUDGETOPERATION_H
#define BUDGETOPERATION_H
#include <iostream>

using namespace std;

class BudgetOperation
{
    int id;
    int userId;
    string date;
    string item;
    string amount;
public:
    int getId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
    void setId(int id);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(string amount);
};

#endif
