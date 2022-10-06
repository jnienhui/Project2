//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_ID_H
#define PROJECT1_STARTER_CODE_ID_H


#include "Automaton.h"

class ID : public Automaton
{
public:
    ID() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_ID_H
