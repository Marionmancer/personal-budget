#ifndef MENUS_H
#define MENUS_H

#include <iostream>

#include "UtilityMethods.h"

using namespace std;

class Menus{

public:
    static char chooseLoginMenuOption();
    static char chooseBalanceMenuOption();
    static void showTitle(string title);
};

#endif
