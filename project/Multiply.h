//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_MULTIPLY_H
#define PROJECT1_STARTER_CODE_MULTIPLY_H


#include "Automaton.h"

class Multiply : public Automaton
{
public:
    Multiply() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_MULTIPLY_H
