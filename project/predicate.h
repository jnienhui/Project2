//
// Created by jnien on 10/4/2022.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H

#include <string>
#include <vector>
#include "parameter.h"

using namespace std;

class predicate
{
public:
    predicate(string n)
    {
        name = n;
    }
    predicate(){}
    ~predicate(){}
    string name;
    vector<parameter> parameterList;
    void addParameter(parameter param)
    {
        parameterList.push_back(param);
    }
    void addParameter(vector<parameter> params)
    {
        parameterList.insert(parameterList.end(),params.begin(), params.end());
    }

    string toString()
    {
        string output;
        output = name + "(";
        for(int i = 0; i < parameterList.size()-1; i++)
        {
            output = output + parameterList[i].getData() + ",";
        }
        output += parameterList[parameterList.size()-1].getData() + ")";

        return output;
    }
};




#endif //PROJECT1_STARTER_CODE_PREDICATE_H
