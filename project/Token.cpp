#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    myType = type;
    myDescription = description;
    myLine = line;
}

std::string Token::tokenToString(TokenType type) {

    std::string returnType = "";

    switch(type){
        case TokenType::COMMA:
            returnType = "COMMA";
            break;

        case TokenType::PERIOD:
            returnType = "PERIOD";
            break;

        case TokenType::Q_MARK:
            returnType = "Q_MARK";
            break;

        case TokenType::LEFT_PAREN:
            returnType = "LEFT_PAREN";
            break;

        case TokenType::RIGHT_PAREN:
            returnType = "RIGHT_PAREN";
            break;

        case TokenType::COLON:
            returnType = "COLON";
            break;

        case TokenType::COLON_DASH:
            returnType = "COLON_DASH";
            break;

        case TokenType::MULTIPLY:
            returnType = "MULTIPLY";
            break;

        case TokenType::ADD:
            returnType = "ADD";
            break;

        case TokenType::SCHEMES:
            returnType = "SCHEMES";
            break;

        case TokenType::FACTS:
            returnType = "FACTS";
            break;

        case TokenType::RULES:
            returnType = "RULES";
            break;

        case TokenType::QUERIES:
            returnType = "QUERIES";
            break;

        case TokenType::ID:
            returnType = "ID";
            break;

        case TokenType::STRING:
            returnType = "STRING";
            break;

        case TokenType::COMMENT:
            returnType = "COMMENT";
            break;

        case TokenType::UNDEFINED:
            returnType = "UNDEFINED";
            break;

        case TokenType::EOF_TYPE:
            returnType = "EOF";
            break;
    }
    return returnType;
}

TokenType Token::getType(){
    return myType;
}

std::string Token::getDescription(){
    return myDescription;
}

std::string Token::toString() {
    return "(" + tokenToString(myType) + ",\"" + myDescription + "\"," + std::to_string(myLine) + ")";
}
