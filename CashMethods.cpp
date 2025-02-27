#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount){

    bool result = false;
    regex pattern("(\\d+)[.,](\\d{2})");
    result = regex_match(amount, pattern);

    if (result){
        amount = regex_replace(amount, pattern, "$1.$2");
    }

    return result;
}
