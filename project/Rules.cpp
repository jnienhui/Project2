#include "Rules.h"

void Rules::S0(const std::string& input) {
    if (input.size() >= 5 && input.substr(0,5) == "Rules") {
        inputRead += 5;
        index += 5;
    }
    else {
        Serr();
    }
}