#include "AuxiliaryMethods.h"

char AuxiliaryMethods::getChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}


string AuxiliaryMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::stringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxiliaryMethods::stringToDoubleConversion(string number)
{
    double numberDouble = 0.0;
    for(int i = 0; i < number.length(); i++)
    {
        if(number[i] == ',')
            number[i] = '.';
    }
    numberDouble = stod(number);
    return numberDouble;
}

int AuxiliaryMethods::getInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::doubleToStringConversion(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::dateConversionToInt(string date)
{
    int dateInt = 0;
    string dateWithoutDashes = "";
    for(int i = 0; i < date.length(); i++)
    {
        if(date[i] == '-')
            continue;
        dateWithoutDashes += date[i];
    }
    dateInt = AuxiliaryMethods::stringToIntConversion(dateWithoutDashes);
    return dateInt;
}

string AuxiliaryMethods::dateConversionToString(int date)
{
    string dateString = "";
    dateString = intToStringConversion(date);
    dateString.insert(4, "-");
    dateString.insert(7, "-");

    return dateString;
}

bool AuxiliaryMethods::checkIfAmountIsCorrect(string amountStr)
{
    bool isCorrect = true;
    for(int i = 0; i < amountStr.length(); i++)
    {
        if(!isdigit(amountStr[i]) && amountStr[i] != '.' && amountStr[i] != ',')
            isCorrect = false;
    }
    return isCorrect;
}
