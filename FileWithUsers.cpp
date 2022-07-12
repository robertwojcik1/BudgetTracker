#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup usersXml;
    usersXml.Load(FILE_WITH_USERS_NAME);
    if(!usersXml.FindElem("Users"))
    {
        usersXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        usersXml.AddElem("Users");
    }

    usersXml.IntoElem();
    usersXml.AddElem("User");
    usersXml.IntoElem();
    usersXml.AddElem("Id", user.getUserId());
    usersXml.AddElem("Login", user.getLogin());
    usersXml.AddElem("Password", user.getPassword());
    usersXml.AddElem("Name", user.getName());
    usersXml.AddElem("Surname", user.getSurname());
    usersXml.OutOfElem();
    usersXml.Save(FILE_WITH_USERS_NAME);
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    CMarkup usersXml;
    User user;
    vector <User> users;

    bool fileExists = usersXml.Load(FILE_WITH_USERS_NAME);
    if(fileExists)
    {
        usersXml.FindElem();
        usersXml.IntoElem();
        while (usersXml.FindElem("User"))
        {
            usersXml.IntoElem();
            usersXml.FindElem("Id");
            user.setUserId(atoi( MCD_2PCSZ(usersXml.GetData()) ));
            usersXml.FindElem("Login");
            user.setLogin(usersXml.GetData());
            usersXml.FindElem("Password");
            user.setPassword(usersXml.GetData());
            usersXml.FindElem("Name");
            user.setName(usersXml.GetData());
            usersXml.FindElem("Surname");
            user.setSurname(usersXml.GetData());
            usersXml.OutOfElem();
            users.push_back(user);
        }
        return users;
    }
    else
        return users;
}

void FileWithUsers::changePasswordInFile(string newPassword, int loggedInUserId)
{
    CMarkup usersXml;

    usersXml.Load(FILE_WITH_USERS_NAME);
    usersXml.FindElem();
    usersXml.IntoElem();
    while (usersXml.FindElem("User"))
    {
        usersXml.IntoElem();
        usersXml.FindElem("Id");
        if(usersXml.GetData() == AuxiliaryMethods::intToStringConversion(loggedInUserId))
        {
            usersXml.FindElem("Password");
            usersXml.SetData(newPassword);
        }
        usersXml.OutOfElem();
    }
    usersXml.Save(FILE_WITH_USERS_NAME);
}
