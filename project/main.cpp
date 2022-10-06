#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Token.h"
#include "Lexer.h"
#include "parser.h"

int main(int argc, char** argv) {

    // TODO
    Lexer* lexer = new Lexer();

    std::string inputStr = "";
    std::string toAdd = "";

    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    // open file
    std::string fileName = argv[1];
    std::ifstream input(fileName);
    if (!input.is_open()) {
        std::cout << "File " << fileName << " could not be found or opened." << std::endl;
        return 1;
    }
    else{
        while(std::getline(input,toAdd)){
            inputStr += toAdd;
            inputStr += "\n";
        }
    }

    input.close();

    parser* parse = new parser(inputStr);
    parse->parse();

    delete lexer;
    delete parse;

    return 0;
}