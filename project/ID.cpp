#include "ID.h"

void ID::S0(const std::string& input) {
    if (isalpha(input.at(0))) {
        for(unsigned int i = 0; i < input.length(); i++){
            if(isalnum(input.at(i))){
                inputRead++;
                index++;
            }
            else{
                break;
            }
        }
    }
    else {
        Serr();
    }
}