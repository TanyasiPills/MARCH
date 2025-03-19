#pragma once

#include <string>
#include <iostream>
#include <ostream>

#include "TokenType.h"


class Token
{
private:
public:
    TokenType type;
    std::string lexeme;
    int line;

    Token(TokenType type, std::string lexeme, int line)
    : type(type), lexeme(lexeme), line(line) {

    }

    Token() = default;

    ~Token(){

    }


    friend std::ostream& operator<<(std::ostream& os, const Token& token){
        os << "Token type: " << static_cast<int>(token.type)
       << "; Text: " << token.lexeme
       << "; Line: " << token.line << "\n";
        return os;
    }
};
