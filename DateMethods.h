#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <regex>

#include "Operation.h"

using namespace std;

class DateMethods{

    static bool isItLeapYear(int year);
    static int calculatePreviousMonthNumber(int currentMonth);
    static int checkHowManyDaysMonthHas(struct tm previousMonthLastDayDate);

public:
    static bool validateDate(string date);
    static string convertTmStructDateToStringDate (struct tm dateToConvert);
    static struct tm convertStringToTmStruct(string strinHoldingFormatedDate);
    static struct tm getCurrentDate();
    static struct tm getCurrentsMonthFirstDayDate();
    static struct tm getPreviousMonthLastDayDate();
    static struct tm getPreviousMonthFirstDayDate();

};

#endif
