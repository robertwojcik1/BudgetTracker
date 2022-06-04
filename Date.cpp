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
