//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_RULES_H
#define PROJECT1_STARTER_CODE_RULES_H


#include "Automaton.h"

class Rules : public Automaton
{
public:
    Rules() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_RULES_H
