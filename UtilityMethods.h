#ifndef UTILITYMETHODS_H
#define UTILITYMETHODS_H

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class UtilityMethods {

public:
    static char getChar();
    static string readLine();
    static string floatToStringFixedConvertion(float number);
    static bool validateInput(string &stringInput);

};

#endif
