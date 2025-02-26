#include "Token.h"

Token::Token(TokenType typeIn, std::string lexemeIn, int lineIn) 
    : type(typeIn), lexeme(lexemeIn), line(lineIn) 
{
}

Token::~Token() 
{
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    os << "Token type: " << token.type << "; Text: " << token.lexeme << "; Line: " << token.line << "\n";
    return os;
}