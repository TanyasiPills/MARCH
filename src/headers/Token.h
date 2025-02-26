#pragma once

#include <string>
#include <iostream>

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

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};
