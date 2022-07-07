#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
     static string intToStringConversion(int number);
     static int stringToIntConversion(string number);
     static double stringToDoubleConversion(string number);
     static string doubleToStringConversion(double number);
     static int dateConversionToInt(string date);
     static string dateConversionToString(int date);
     static string getLine();
     static char getChar();
     static int getInteger();

};

#endif
