//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_RIGHT_PAREN_H
#define PROJECT1_STARTER_CODE_RIGHT_PAREN_H

#include "Automaton.h"

class Right_Paren : public Automaton
{
public:
    Right_Paren() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_RIGHT_PAREN_H
