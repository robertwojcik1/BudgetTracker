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
    CMarkup xml;
    const string FILE_WITH_USERS_NAME;
public:
    FileWithUsers(string fileWithUsersName) : FILE_WITH_USERS_NAME(fileWithUsersName)
    {
        bool fileExists = xml.Load( "users.xml" );

        if (!fileExists)
        {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Users");
        }
    }
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changePasswordInFile(string newPassword, int loggedInUserId);
};

#endif
