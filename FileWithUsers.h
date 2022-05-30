#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{

public:
    void addUserToFile(User user);
};

#endif
