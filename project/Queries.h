//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_QUERIES_H
#define PROJECT1_STARTER_CODE_QUERIES_H


#include "Automaton.h"

class Queries : public Automaton
{
public:
    Queries() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_QUERIES_H
