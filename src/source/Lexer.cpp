#include <vector>

#include "Lexer.h"
#include "Logger.h"

std::vector<Token> Lexer::tokens;
int Lexer::currentPos = 0;
int Lexer::startPos = 0;
int Lexer::line = 1;
char Lexer::token = '\0';
std::ifstream Lexer::file;


int Lexer::SetFile(std::string fileIn)
{
    file.open(fileIn);

    if (!file) {
        LogError("File","-1","Cant read provided file");
        return 1;
    }

    return 0;
}

char Lexer::Peek(int offset)
{
    if(!file) return EOF;

    std::streampos currentPos = file.tellg();
    file.seekg(currentPos + std::streamoff(offset));

    char nextChar = file.get();

    file.seekg(currentPos);

    return nextChar;
}

bool Lexer::Match(char charIn)
{
    char temp = Peek();
    if(temp == EOF) return false;
    if(temp == charIn) return true;
    else return false;
}

bool Lexer::IsAlphabetic(char& charIn)
{
    return  (charIn >= 'a' && charIn <= 'z') ||
            (charIn >= 'A' && charIn <= 'Z') ||
            charIn == '_';
}

bool Lexer::IsDigit(char& charIn)
{
    return charIn >= '0' && charIn <= '9';
}

void Lexer::AddToken(TokenType type)
{
    tokens.emplace_back(type, std::string(&token), line);
}

void Lexer::ScanToken(char& tokenIn)
{
    token = tokenIn;
    switch (token)
    {
    case '=':
        AddToken(assingType);
        break;
    case '\n':
        AddToken(lineType);
    case '+':
        AddToken(additionType);
        break;
    default:
        break;
    }
}

int Lexer::ProcessFile(std::string fileIn)
{
    if(SetFile(fileIn)) return 1;


    char ch;
    while (file.get(ch)) {  
        startPos = currentPos;
        ScanToken(ch);
    }
    tokens.emplace_back(Token(EOFType, "", line));


    return 0;
}
