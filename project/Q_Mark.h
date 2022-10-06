//
// Created by jnien on 9/21/2022.
//

#ifndef PROJECT1_STARTER_CODE_Q_MARK_H
#define PROJECT1_STARTER_CODE_Q_MARK_H


#include "Automaton.h"

class Q_Mark : public Automaton
{
public:
    Q_Mark() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_Q_MARK_H
