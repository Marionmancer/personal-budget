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
