#include "Comment.h"

void Comment::S0(const std::string& input) {
    if (input[0] == '#') {
        if (input[1] == '|') {
            inputRead += 2;
            index += 2;
            for(unsigned int i = 2; i < input.length(); i++){
                inputRead++;
                index++;
                if(i < input.length()-2 && input.at(i) == '|' && input.at(i+1) == '#'){
                    inputRead++;
                    index++;
                    break;
                }
                if(i == input.length() - 1){
                    this->type = TokenType::UNDEFINED;
                }
            }
        } else {
            inputRead++;
            index++;
            for(unsigned int i = 1; i < input.size(); i++) {
                if (input[i] == '\n') {
                    break;
                } else {
                    inputRead++;
                }
            }
        }
    }
    else {
        Serr();
    }
}