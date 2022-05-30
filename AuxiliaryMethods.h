#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
     static string IntToStringConversion(int number);
     static int stringToIntConversion(string number);
     static string getLine();
     static char getChar();
     static int getInteger();
};

#endif
