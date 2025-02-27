#include "UtilityMethods.h"

char UtilityMethods::getChar() {
    string input = "";
    char singleSign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            singleSign = input[0];
            break;
        }
        cout << "That's not single sign. Try again." << endl;
    }
    return singleSign;
}

string UtilityMethods::readLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string UtilityMethods::floatToStringFixedConvertion(float number){
    ostringstream out;
    out << fixed << setprecision(2) << number;
    return out.str();
}

bool UtilityMethods::validateInput(string &stringInput){

    if (stringInput.empty()) return false;
    transform(stringInput.begin(), stringInput.end(), stringInput.begin(), ::tolower);
    stringInput[0] = toupper(stringInput[0]);

    return true;
}
