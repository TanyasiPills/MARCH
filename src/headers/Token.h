#pragma once

#include <string>

#include "TokenType.h"

class Token
{
private:
    TokenType type;
    std::string lexeme; // aka the text/name
    int line;
public:
    Token(TokenType type, std::string lexeme, int line);
    ~Token();

    friend std::ostream& operator<<(std::ostream& os, const Token& token)
    {
        os << "Token type: " << token.type << "; Text: " << token.lexeme << "; Line: " << token.line << "\n";
        return os;
    }
};

Token::Token()
{
}

Token::~Token()
{
}
