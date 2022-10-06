//
// Created by jnien on 10/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include "Lexer.h"
#include "datalogProgram.h"

class parser
{
public:
    parser(string inputFile)
    {
        lexer.Run(inputFile);
        lexer.deleteComments();
        tokenList = lexer.getTokenList();
        token = tokenList.at(0);
        tokenList.erase(tokenList.begin());
    }
    ~parser(){}
    void parse();
    void match(TokenType t);
    void parseScheme();
    void parseSchemeList();
    void parseFactList();
    void parseFact();
    void parseRuleList();
    void parseRule();
    predicate headPredicate();
    predicate parsePredicate();
    vector<predicate> parsePredicateList();
    parameter parseParameter();
    vector<parameter> parseParameterList();
    void parseQuery();
    void parseQueryList();
    vector<parameter> idList();
    vector<parameter> stringList();
    Token* token;

private:
    vector<Token*> tokenList;
    datalogProgram program;
    Lexer lexer;

};

#endif //PROJECT1_STARTER_CODE_PARSER_H
