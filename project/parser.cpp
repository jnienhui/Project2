#include "parser.h"
#include <algorithm>
#include <iostream>

void parser::parse()
{
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    parseScheme();
    parseSchemeList();

    match(TokenType::FACTS);
    match(TokenType::COLON);
    parseFactList();
    program.makeDomain();

    match(TokenType::RULES);
    match(TokenType::COLON);
    parseRuleList();

    match(TokenType::QUERIES);
    match(TokenType::COLON);
    parseQuery();
    parseQueryList();

    cout << "Success!\n" << program.toString();
}

void parser::match(TokenType t)
{
    if(token->getType() == t)
    {
        token = tokenList[0];
        tokenList.erase(tokenList.begin());
    }
    else{
        cout << "Failure!\n  " << token->toString() << endl;
        exit(EXIT_SUCCESS);
    }
}

void parser::parseScheme()
{
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    parameter param;
    predicate newScheme(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    param.setData(token->getDescription());
    newScheme.addParameter(param);
    match(TokenType::ID);
    newScheme.addParameter(idList());
    match(TokenType::RIGHT_PAREN);


    program.addScheme(newScheme);

}

void parser::parseSchemeList()
{
    if(token->getType() != TokenType::FACTS)
    {
        parseScheme();
        parseSchemeList();
    }
}

void parser::parseFact()
{
    parameter param;
    predicate newFact(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    param.setData(token->getDescription());
    newFact.addParameter(param);
    match(TokenType::STRING);
    newFact.addParameter(stringList());
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);

    program.addFact(newFact);
}

void parser::parseFactList()
{
    if(token->getType() != TokenType::RULES)
    {
        parseFact();
        parseFactList();
    }


}

void parser::parseRuleList()
{
    if(token->getType() != TokenType::QUERIES)
    {
        parseRule();
        parseRuleList();
    }
}

void parser::parseRule()
{
    rule newRule;
    newRule.addHead(headPredicate());
    match(TokenType::COLON_DASH);
    newRule.addPred(parsePredicate());
    newRule.addPred(parsePredicateList());
    match(TokenType::PERIOD);

    program.addRule(newRule);

}

predicate parser::headPredicate()
{
    predicate newHead(token->getDescription());
    parameter initial;
    vector<parameter> pList;
    vector<parameter> temp;
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    initial.setData(token->getDescription());
    newHead.addParameter(initial);
    match(TokenType::ID);
    temp = idList();
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        parameter a;
        a.setData(temp[i].getData());
        pList.push_back(a);
    }
    newHead.addParameter(pList);
    match(TokenType::RIGHT_PAREN);

    return newHead;
}

predicate parser::parsePredicate()
{
    predicate newPred(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    newPred.addParameter(parseParameter());
    newPred.addParameter(parseParameterList());
    match(TokenType::RIGHT_PAREN);

    return newPred;
}

vector<predicate> parser::parsePredicateList()
{
    vector<predicate> newPredList;
    if(token->getType() != TokenType::PERIOD && token->getType() != TokenType::QUERIES)
    {
        match(TokenType::COMMA);
        newPredList.push_back(parsePredicate());
        vector<predicate> temp = parsePredicateList();
        newPredList.insert(newPredList.end(), temp.begin(), temp.end());
    }

    return newPredList;
}

parameter parser::parseParameter()
{
    parameter newParam;
    if(token->getType() == TokenType::STRING)
    {
        newParam.setData(token->getDescription());
        match(TokenType::STRING);
    }
    else if(token->getType() == TokenType::ID)
    {
        newParam.setData(token->getDescription());
        match(TokenType::ID);
    }
    return newParam;
}

vector<parameter> parser::parseParameterList()
{
    vector<parameter> newParamList;
    if(token->getType() != TokenType::RIGHT_PAREN)
    {
        match(TokenType::COMMA);
        newParamList.push_back(parseParameter());
        vector<parameter> temp = parseParameterList();
        newParamList.insert(newParamList.end(), temp.begin(), temp.end());
    }

    return newParamList;
}

void parser::parseQuery()
{
    program.addQuery(parsePredicate());
    match(TokenType::Q_MARK);
}

void parser::parseQueryList()
{
    if(token->getType() != TokenType::EOF_TYPE)
    {
        parseQuery();
        parseQueryList();
    }

}

vector<parameter> parser::idList()
{
    vector<parameter> myList;

    if(token->getType() != TokenType::RIGHT_PAREN)
    {
        parameter param;
        match(TokenType::COMMA);
        param.setData(token->getDescription());
        myList.push_back(param);
        match(TokenType::ID);
        vector<parameter> temp = idList();
        myList.insert(myList.end(), temp.begin(), temp.end());
    }

    return myList;

}

vector<parameter> parser::stringList()
{
    vector<parameter> myList;

    if(token->getType() != TokenType::RIGHT_PAREN)
    {
        parameter param;
        match(TokenType::COMMA);
        param.setData(token->getDescription());
        myList.push_back(param);
        match(TokenType::STRING);
        vector<parameter> temp = stringList();
        myList.insert(myList.end(), temp.begin(), temp.end());
    }

    return myList;
}
