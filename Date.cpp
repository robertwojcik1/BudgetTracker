#include "Date.h"

string Date::getCurrentDate()
{
    string date = "", day = "", month = "", year = "", correctedDay = "", correctedMonth = "";
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    day = AuxiliaryMethods::intToStringConversion(systemTime.wDay);
    month = AuxiliaryMethods::intToStringConversion(systemTime.wMonth);
    year = AuxiliaryMethods::intToStringConversion(systemTime.wYear);
    correctedDay = addMissingZeroToDate(day);
    correctedMonth = addMissingZeroToDate(month);

    date = year + '-' + correctedMonth + '-' + correctedDay;
    return date;
}

string Date::addMissingZeroToDate(string date)
{
    string correctedDate = "";
    if( date.length() == 1 )
    {
        correctedDate = "0" + date;
        return correctedDate;
    }
    else return date;
}

bool Date::isDateCorrect(string date)
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    bool isDateCorrect = false;
    string givenDay = "", givenMonth = "", givenYear = "";
    int givenDayInt = 0, givenMonthInt = 0, givenYearInt = 0, currentDayInt = 0, currentMonthInt = 0, currentYearInt = 0;
    int daysCountOfGivenMonth = 0;

    givenDay = getDayFromDate( date );
    givenDayInt = AuxiliaryMethods::stringToIntConversion(givenDay);
    givenMonth = getMonthFromDate(date);
    givenMonthInt = AuxiliaryMethods::stringToIntConversion(givenMonth);
    givenYear = getYearFromDate(date);
    givenYearInt = AuxiliaryMethods::stringToIntConversion(givenYear);
    daysCountOfGivenMonth = getDaysCountOfCurrentMonth(givenMonthInt, givenYearInt);

    currentDayInt = systemTime.wDay;
    currentMonthInt = systemTime.wMonth;
    currentYearInt = systemTime.wYear;

    if( (givenYearInt >= 2000 && givenYearInt <= currentYearInt) && (givenMonthInt >= 1 && givenMonthInt <= 12) && (givenDayInt >= 1 && givenDayInt <= daysCountOfGivenMonth) )
        isDateCorrect = true;
    else
        isDateCorrect = false;
    if( givenYearInt == currentYearInt && givenMonthInt > currentMonthInt )
        isDateCorrect = false;

    return isDateCorrect;
}

string Date::getDayFromDate(string date)
{
    string day = "", month = "", year = "";
    for( int i = 0; i < date.length() ; i++)
    {
        if( date[i] == '-')
            break;
        year += date[i];
    }
    date.erase(0, year.length() + 1);

    for( int j = 0; j < date.length(); j++)
    {
        if( date[j] == '-')
            break;
        month += date[j];
    }
    date.erase(0, month.length() + 1);

    for( int k = 0; k < date.length(); k++)
    {
        day += date[k];
    }
    return day;
}

string Date::getMonthFromDate(string date)
{
    string month = "", year = "";
    for( int i = 0; i < date.length(); i++)
    {
        if( date[i] == '-')
            break;
        year += date[i];
    }
    date.erase(0, year.length() + 1);
    for( int j = 0; j < date.length(); j++)
    {
        if( date[j] == '-')
            break;
        month += date[j];
    }

    return month;
}

string Date::getYearFromDate(string date)
{
    string year = "";
    for( int i = 0; i < date.length(); i++)
    {
        if(date[i] == '-')
            break;
        year += date[i];
    }
    return year;
}

int Date::getDaysCountOfCurrentMonth(int month, int year)
{
    int days = 0;
    if( month == 4 || month == 6 || month == 9 || month == 11 )
        days = 30;

    else if( month == 2)
    {
        bool leapYear = isLeapYear( year );
        if (leapYear)
            days = 29;
        else
            days = 28;
    }
    else
        days = 31;

    return days;
}

bool Date::isLeapYear(int year)
{
    bool leapYear = false;
    if( ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 ) )
        leapYear = true;
    else
        leapYear = false;

    return leapYear;
}

