#include "datalogProgram.h"
#include <sstream>
#include <algorithm>

void datalogProgram::addScheme(predicate newScheme)
{
    schemesList.push_back(newScheme);
}

void datalogProgram::addFact(predicate newFact)
{
    factsList.push_back(newFact);
    for(unsigned int i = 0; i < newFact.parameterList.size(); i++)
    {
        domain.insert(domain.end(),newFact.parameterList.at(i).getData());
    }
}

void datalogProgram::addRule(rule newRule)
{
    rulesList.push_back(newRule);
}

void datalogProgram::addQuery(predicate p)
{
    queryList.push_back(p);
}

void datalogProgram::makeDomain()
{

    sort(domain.begin(), domain.end());
    domain.erase(unique(domain.begin(), domain.end()), domain.end());
}

string datalogProgram::toString()
{
    string output;
    output = "Schemes(" + intToString(schemesList.size()) + "):\n";
    for(unsigned int i = 0; i < schemesList.size(); i++)
    {
        output += "  " + schemesList[i].toString() + "\n";
    }
    output += "Facts(" + intToString(factsList.size()) +  "):\n";
    for(unsigned int i = 0; i < factsList.size(); i++)
    {
        output += "  " + factsList[i].toString() + ".\n";
    }
    output += "Rules(" + intToString(rulesList.size()) + "):\n";
    for(unsigned int i = 0; i < rulesList.size(); i++)
    {
        output += "  " + rulesList[i].toString() + ".\n";
    }

    output += "Queries(" + intToString(queryList.size()) + "):\n";
    for(unsigned int i = 0; i < queryList.size(); i++)
    {
        output += "  " + queryList[i].toString() + "?\n";
    }

    output += "Domain(" + intToString(domain.size()) + "):\n";
    for(unsigned int i = 0; i < domain.size(); i++)
    {
        output += "  " + domain[i]+ "\n";
    }
    return output;

}

string datalogProgram::intToString(int x)
{
    stringstream convert;
    convert << x;
    string output = convert.str();
    return output;
}
