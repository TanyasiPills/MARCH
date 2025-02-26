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
    static std::string wholeToken;
public:
    static std::vector<Token> tokens;
    static int ProcessFile(std::string file);
    static char Peek(int offset = 1);
    static int SetFile(std::string fileIn);
    static void ScanToken(char& token);
    static void PushToken(TokenType type, bool push);
    static bool Match(char charIn);
    static bool IsAlphabetic(char& tokenIn);
    static bool IsDigit(char& tokenIn);
    static bool IsAlphaNumeric(char tokenIn);
    static void ScanLong();
    static char TakeNext();
    static void NumberToken();
    static void IdentifierToken();
};

