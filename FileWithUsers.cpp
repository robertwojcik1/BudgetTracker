#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.OutOfElem();
    xml.ResetPos();
    xml.Save("users.xml");
}
