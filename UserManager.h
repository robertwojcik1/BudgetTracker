#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;
    FileWithUsers fileWithUsers;
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
};

#endif
