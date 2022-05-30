#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;
    string name;
    string surname;

public:
    User(int userId = 0, string login = "", string password = "", string name = "", string surname = "")
    {
        this->userId = userId;
        this->login = login;
        this->password = password;
        this->name = name;
        this->surname = surname;
    };

    void setUserId(int userId);
    void setLogin(string login);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
    int getUserId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
