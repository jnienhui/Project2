#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Comma.h"
#include "Period.h"
#include "Q_Mark.h"
#include "Left_Paren.h"
#include "Right_Paren.h"
#include "Multiply.h"
#include "Add.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "ID.h"
#include "String.h"
#include "Comment.h"
#include <cctype>
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {

    for (unsigned int i = 0; i < this->automata.size(); i++) {
        delete automata[i];
    }

    for (unsigned int i = 0; i < tokens.size(); i++) {
        delete tokens[i];
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new Comma());
    automata.push_back(new Period());
    automata.push_back(new Q_Mark());
    automata.push_back(new Left_Paren());
    automata.push_back(new Right_Paren());
    automata.push_back(new Multiply());
    automata.push_back(new Add());
    automata.push_back(new Schemes());
    automata.push_back(new Facts());
    automata.push_back(new Rules());
    automata.push_back(new Queries());
    automata.push_back(new ID());
    automata.push_back(new String());
    automata.push_back(new Comment());
    // TODO: Add the other needed automata here
}

std::vector<Token*> Lexer::getTokenList(){
    return tokens;
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    std::string thingsToTokenize = input;

    unsigned int lineNumber = 1;

    while(thingsToTokenize.size() > 0){
        unsigned int maxRead = 0;
        Automaton* maxAutomata = automata.at(0);

        unsigned int i = 0;
        while(std::isspace(thingsToTokenize.at(i)) && i < thingsToTokenize.length()-1){
            if(thingsToTokenize.at(i) == '\n'){
                lineNumber++;
            }
            i++;
        }
        thingsToTokenize = thingsToTokenize.substr(i);

        for (unsigned int i = 0; i < automata.size(); i++) {
            unsigned int inputRead = automata.at(i)->Start(thingsToTokenize);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomata = automata.at(i);
            }
        }

        if(maxRead > 0){
            std::string description = thingsToTokenize.substr(0,maxRead);
            Token* newToken = maxAutomata->CreateToken(description,lineNumber);
            tokens.push_back(newToken);

            for(unsigned int i = 0; i < maxRead; i++){
                if(thingsToTokenize.at(i) == '\n'){
                    lineNumber++;
                }
            }
        }
        else{
            maxRead = 1;
            if(thingsToTokenize.at(0) == '\n'){
                lineNumber++;
            }
            else{
                Token* newToken = new Token(TokenType::UNDEFINED, thingsToTokenize.substr(0,maxRead), lineNumber);
                tokens.push_back(newToken);
            }

        }
        if(thingsToTokenize.length() != maxRead){
            thingsToTokenize = thingsToTokenize.substr(maxRead);
        }
        else{
            thingsToTokenize = "";
        }

    }
    Token* eofToken = new Token(TokenType::EOF_TYPE, "", lineNumber);
    tokens.push_back(eofToken);
}

void Lexer::deleteComments(){
    for(unsigned int i = 0; i < tokens.size(); i++){
        if(tokens.at(i)->getType() == TokenType::COMMENT){
            tokens.erase(tokens.begin()+i);
            i--;
        }
    }
}