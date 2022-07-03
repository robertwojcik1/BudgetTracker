#include "UserManager.h"

void UserManager::userRegister()
{
    User user = enterNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

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

bool UserManager::isUserLoggedIn()
{
    if( loggedInUserId > 0 )
        return true;
    else
        return false;
}

void UserManager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                password = AuxiliaryMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::logOut()
{
    loggedInUserId = 0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedInUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordInFile(newPassword, loggedInUserId);
}

void UserManager::addIncome()
{
    operationManager.addIncome(loggedInUserId);
}

void UserManager::addExpense()
{
    operationManager.addExpense(loggedInUserId);
}

void UserManager::printBalanceFromCurrentMonth()
{
    operationManager.printBalanceFromCurrentMonth();
}

void UserManager::printBalanceFromPreviousMonth()
{
    operationManager.printBalanceFromPreviousMonth();
}

void UserManager::printBalanceOfSelectedPeriod()
{
    operationManager.printBalanceOfSelectedPeriod();
}
