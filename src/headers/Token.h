#pragma once

#include <string>
#include <iostream>
#include <ostream>

#include "TokenType.h"


class Token
{
private:
    TokenType type;
    std::string lexeme;
    int line;
public:
    Token(TokenType type, std::string lexeme, int line)
    : type(type), lexeme(lexeme), line(line) {

    }
    ~Token(){

    }

    friend std::ostream& operator<<(std::ostream& os, const Token& token){
        os << "Token type: " << static_cast<int>(token.type)
       << "; Text: " << token.lexeme
       << "; Line: " << token.line << "\n";
        return os;
    }
};
