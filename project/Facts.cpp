#include "Facts.h"

void Facts::S0(const std::string& input) {
    if (input.size() >= 5 && input.substr(0,5) == "Facts") {
        inputRead += 5;
        index += 5;
    }
    else {
        Serr();
    }
}