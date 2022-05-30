#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    vector <User> users;
    FileWithUsers fileWithUsers;
    User enterNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);
public:
    void userRegister();
};

#endif
