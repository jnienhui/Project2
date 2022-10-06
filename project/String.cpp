#include "String.h"

void String::S0(const std::string& input) {
    if (input.at(0) == '\'') {
        inputRead++;
        index++;
        bool isBadString = true;
        for (unsigned int i = 1; i < input.size(); i++) {
            inputRead++;
            index++;
            if (input[i] == '\'') {
                if ((i < (input.size() - 1)) and (input[(i + 1)] == '\'')) {
                    //do nothing, go back to loop.
                    i++;
                    inputRead++;
                    index++;
                } else {
                    isBadString = false;
                    break;
                }
            }
        }

        if (isBadString) {
            this->type = TokenType::UNDEFINED;
        }
    }
    else {
        Serr();
    }
}