#include "DateMethods.h"

bool DateMethods::isItLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

struct tm DateMethods::convertStringToTmStruct(string strinHoldingFormatedDate) {
    bool is_dst = false;
    const string dateFormat = "%Y-%m-%d";

    tm dataAsStructure = {0};
    dataAsStructure.tm_isdst = is_dst ? true : false;
    istringstream ss(strinHoldingFormatedDate);
    ss >> get_time(&dataAsStructure, dateFormat.c_str());
    return dataAsStructure;
}

time_t DateMethods::convertStringToTime_t(string strinHoldingFormatedDate) {

    struct tm stringConvertedToStructTm;

    stringConvertedToStructTm = convertStringToTmStruct(strinHoldingFormatedDate);

    return mktime(&stringConvertedToStructTm);
}


string DateMethods::convertTmStructDateToStringDate (struct tm dateToConvert) {

    string year, month, day;
    string mergedStringDate;
    const int DEFAULT_START_YEAR = 1900;
    const int MONTH_CORRECTION = 1;

    year = to_string(dateToConvert.tm_year + DEFAULT_START_YEAR);
    month = to_string(dateToConvert.tm_mon + MONTH_CORRECTION);
    day = to_string(dateToConvert.tm_mday);

    month.size() == 1 ? month = "0" + month : month;
    day.size() == 1 ? day = "0" + day : day;

    mergedStringDate = year + "-" + month + "-" + day;

    return mergedStringDate;
}

struct tm DateMethods::getCurrentDate() {
    const int MAXLEN = 80;
    char currentDateAsString[MAXLEN];
    time_t numberOfSecondsSince1970 = time(NULL);
    struct tm currentDate = {0};

    strftime(currentDateAsString, MAXLEN, "%Y-%m-%d", localtime(&numberOfSecondsSince1970));
    currentDate = convertStringToTmStruct(currentDateAsString);
    return currentDate;
}

int DateMethods::calculatePreviousMonthNumber(int currentMonth) {
    int previousMonth = 0;

    currentMonth == 12 ? previousMonth = 1 : previousMonth = currentMonth - 1;
    return previousMonth;
}

int DateMethods::checkHowManyDaysMonthHas(struct tm month){
    const int MONTH_CORRECTION = 1;
    int days[] = {0 ,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month.tm_mon + MONTH_CORRECTION == 2 && (isItLeapYear(month.tm_year))) {
        return 29;
    }

    return days[month.tm_mon + MONTH_CORRECTION];
}

bool DateMethods::validateDate(string date) {
    regex datePattern(R"(^(2\d{3})-(0[1-9]|1[0-2])-([0-2]\d|3[01])$)");
    smatch match;

    if (regex_match(date, match, datePattern)) {
        int day = stoi(match[3]);
        return day <= checkHowManyDaysMonthHas(convertStringToTmStruct(date));
    }
    return false;
}

struct tm DateMethods::getPreviousMonthLastDayDate() {

    struct tm currentDate = getCurrentDate();
    struct tm previousMonthLastDayDate;

    int currentMonth = currentDate.tm_mon;
    int previousMonth = calculatePreviousMonthNumber(currentMonth);
    int yearOfPreviousMonth =
            currentMonth == 12
            ? currentDate.tm_year - 1
            : currentDate.tm_year;

    previousMonthLastDayDate.tm_year = yearOfPreviousMonth;
    previousMonthLastDayDate.tm_mon = previousMonth;
    previousMonthLastDayDate.tm_mday = checkHowManyDaysMonthHas(previousMonthLastDayDate);

    return previousMonthLastDayDate;
}

struct tm DateMethods::getPreviousMonthFirstDayDate() {
    struct tm previousMonthFirstDayDate = getPreviousMonthLastDayDate();
    previousMonthFirstDayDate.tm_mday = 1;

    return previousMonthFirstDayDate;
}

struct tm DateMethods::getCurrentsMonthFirstDayDate() {
    struct tm currentsMonthFirstDayDate = getCurrentDate();
    currentsMonthFirstDayDate.tm_mday = 1;

    return currentsMonthFirstDayDate;
}
