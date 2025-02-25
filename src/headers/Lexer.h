#pragma once

#include <string>
#include <fstream>

class Lexer
{
private:
    static std::vector<Token> tokens;
    static std::ifstream file;
    static int startPos;
    static int currentPos;
    static int line;
    static char token;
public:
    static int ProcessFile(std::string file);
    static char Peek(int offset = 1);
    static int SetFile(std::string fileIn);
    static void ScanToken(char& token);
    static void AddToken(TokenType type);
    static bool Match(char charIn);
    static bool IsAlphabetic(char& charIn);
    static bool IsDigit(char& charIn);
};

