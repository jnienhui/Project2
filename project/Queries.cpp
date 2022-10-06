#include "Queries.h"

void Queries::S0(const std::string& input) {
    if (input.size() >= 7 && input.substr(0,7) == "Queries") {
        inputRead += 7;
        index += 7;
    }
    else {
        Serr();
    }
}