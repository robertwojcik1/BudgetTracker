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
public:
    static string getCurrentDate();

};

#endif
