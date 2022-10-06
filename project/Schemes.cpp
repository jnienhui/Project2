#include "Schemes.h"

void Schemes::S0(const std::string& input) {
    if (input.size() >= 7 && input.substr(0,7) == "Schemes") {
        inputRead += 7;
        index += 7;
    }
    else {
        Serr();
    }
}