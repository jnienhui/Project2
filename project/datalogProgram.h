//
// Created by jnien on 10/4/2022.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H


#include <vector>
#include <string>
#include "rule.h"

using namespace std;

class datalogProgram
{
public:
    datalogProgram(){}
    ~datalogProgram(){}
    void addScheme(predicate newScheme);
    void addFact(predicate newFact);
    void addRule(rule newRule);
    void addQuery(predicate p);
    void makeDomain();
    string toString();


private:
    vector<predicate> schemesList;
    vector<predicate> factsList;
    vector<string> domain;
    vector<rule> rulesList;
    vector<predicate> queryList;
    string intToString(int);
};



#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
