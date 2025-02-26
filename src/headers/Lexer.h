#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "TokenType.h"
#include "Token.h"

class Lexer
{
private:
    static std::ifstream file;
    static int startPos;
    static int currentPos;
    static int line;
    static char token;
public:
    static std::vector<Token> tokens;
    static int ProcessFile(std::string file);
    static char Peek(int offset = 1);
    static int SetFile(std::string fileIn);
    static void ScanToken(char& token);
    static void AddToken(TokenType type);
    static bool Match(char charIn);
    static bool IsAlphabetic(char& charIn);
    static bool IsDigit(char& charIn);
};

