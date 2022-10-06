//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_STRING_H
#define PROJECT1_STARTER_CODE_STRING_H


#include "Automaton.h"

class String : public Automaton
{
public:
    String() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_STRING_H
