//
// Created by jnien on 9/22/2022.
//

#ifndef PROJECT1_STARTER_CODE_COMMENT_H
#define PROJECT1_STARTER_CODE_COMMENT_H


#include "Automaton.h"

class Comment : public Automaton
{
public:
    Comment() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //PROJECT1_STARTER_CODE_COMMENT_H
