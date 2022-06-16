#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    static string addMissingZeroToDate(string date);
    static string getDayFromDate(string date);
    static string getMonthFromDate(string date);
    static string getYearFromDate(string date);
    static int getDaysCountOfCurrentMonth(int month, int year);
    static bool isLeapYear(int year);
public:
    static string getCurrentDate();
    static bool isDateCorrect(string date);

};

#endif
