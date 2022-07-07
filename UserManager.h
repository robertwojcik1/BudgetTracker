#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include "OperationManager.h"

using namespace std;

class UserManager
{
    FileWithUsers fileWithUsers;
    int loggedInUserId;
    vector<User> users;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);
public:
    UserManager(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedInUserId = 0;
    }
    void userRegister();
    bool isUserLoggedIn();
    void userLogin();
    void logOut();
    void changePassword();
    int getLoggedInUserId();
};

#endif
