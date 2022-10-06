//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_COMMA_H
#define PROJECT1_STARTER_CODE_COMMA_H

#include "Automaton.h"

class Comma : public Automaton
{
public:
    Comma() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_COMMA_H
