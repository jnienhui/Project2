//
// Created by jnien on 10/4/2022.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H


class parameter
{
public:
    parameter(){}
    ~parameter(){}

    void setData(std::string data){
        value = data;
    }
    std::string getData(){
        return value;
    }

private:
    std::string value;


};
#endif //PROJECT1_STARTER_CODE_PARAMETER_H
