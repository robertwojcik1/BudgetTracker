#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.ResetPos();
    xml.Save("users.xml");
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        user.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());
        xml.FindElem( "Password" );
        user.setPassword(xml.GetData());
        xml.FindElem( "Name" );
        user.setName(xml.GetData());
        xml.FindElem( "Surname" );
        user.setSurname(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::changePasswordInFile(string newPassword, int loggedInUserId)
{
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        if(xml.GetData() == AuxiliaryMethods::intToStringConversion(loggedInUserId))
        {
            xml.FindElem( "Password" );
            xml.RemoveElem();
            xml.AddElem("Password", newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save("users.xml");
}
