//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_SCHEMES_H
#define PROJECT1_STARTER_CODE_SCHEMES_H


#include "Automaton.h"

class Schemes : public Automaton
{
public:
    Schemes() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_SCHEMES_H
