
#ifndef PROJECT1_STARTER_CODE_PERIOD_H
#define PROJECT1_STARTER_CODE_PERIOD_H

#include "Automaton.h"

class Period : public Automaton
{
public:
    Period() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_PERIOD_H
