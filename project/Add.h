//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_ADD_H
#define PROJECT1_STARTER_CODE_ADD_H


#include "Automaton.h"

class Add : public Automaton
{
public:
    Add() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_ADD_H
