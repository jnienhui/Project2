//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_LEFT_PAREN_H
#define PROJECT1_STARTER_CODE_LEFT_PAREN_H


#include "Automaton.h"

class Left_Paren : public Automaton
{
public:
    Left_Paren() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_LEFT_PAREN_H
