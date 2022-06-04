#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class UserManager
{
    Income income;
    Expense expense;
    FileWithUsers fileWithUsers;
    int loggedInUserId;
    vector<User> users;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);
public:
    UserManager()
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedInUserId = 0;
    }
    void userRegister();
    bool isUserLoggedIn();
    void userLogin();
    void logOut();
    void changePassword();
    void addIncome();
};

#endif
