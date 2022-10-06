//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_FACTS_H
#define PROJECT1_STARTER_CODE_FACTS_H


#include "Automaton.h"

class Facts : public Automaton
{
public:
    Facts() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_FACTS_H
