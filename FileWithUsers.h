#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string FILE_WITH_USERS_NAME;
public:
    FileWithUsers(string fileWithUsersName) : FILE_WITH_USERS_NAME(fileWithUsersName)
    {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changePasswordInFile(string newPassword, int loggedInUserId);
};

#endif
