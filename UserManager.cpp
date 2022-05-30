#include "UserManager.h"

void UserManager::userRegister()
{
    User user = enterNewUserData();

    users.push_back(user);

    //fileWithUsers.addUserToFile(user);

    cin.sync();
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

User UserManager::enterNewUserData()
{
    User user;

    user.setUserId(getNewUserId());

    string login, password, name, surname;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

bool UserManager::isLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie. Wprowadz inny login." << endl;
            return true;
        }
    }
    return false;
}
