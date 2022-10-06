#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOF_TYPE
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType myType;
    std::string myDescription;
    int myLine;

public:
    Token(TokenType type, std::string description, int line);

    // TODO: add other needed methods
    std::string tokenToString(TokenType type);
    std::string toString();

    TokenType getType();

    std::string getDescription();
};

#endif // TOKEN_H

