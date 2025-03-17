#include <vector>
#include <unordered_map>
#include <fstream>

#include "Lexer.h"
#include "Logger.h"

std::unordered_map<std::string, TokenType> identityKeyMap = {
    {"int", intType},
    {"string", stringType}
};

std::vector<Token> Lexer::tokens;
int Lexer::currentPos = 0;
int Lexer::startPos = 0;
int Lexer::line = 1;
char Lexer::token = '\0';
std::string Lexer::wholeToken = "";
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

void WriteTokensToFile(const std::vector<Token>& tokens, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Cannot open file for writing!\n";
        return;
    }

    for (const auto& token : tokens) {
        outFile << token << "\n";
    }

    outFile.close();
}

char Lexer::Peek(int offset)
{
    if(!file) return EOF;

    std::streampos currentPos = file.tellg();
    file.seekg(offset, std::ios::cur);

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

bool Lexer::IsAlphabetic(char tokenIn)
{
    return  (tokenIn >= 'a' && tokenIn <= 'z') ||
            (tokenIn >= 'A' && tokenIn <= 'Z') ||
            tokenIn == '_';
}

bool Lexer::IsDigit(char tokenIn)
{
    return (tokenIn >= '0' && tokenIn <= '9');// || tokenIn == '.';
}

void Lexer::PushToken(TokenType type)
{
    wholeToken += token;
    tokens.emplace_back(type, wholeToken, line);
}

char Lexer::TakeNext()
{
    if (!file) return '\0';
    token = file.get();
    return (file.eof()) ? '\0' : token;
}

void Lexer::ScanLong()
{
    if(IsDigit(token))
    {
        NumberToken();
    }
    else if(IsAlphabetic(token))
    {
        std::cout << "Alphabetic: " << token << std::endl;
        IdentifierToken();
    }
    else{
        std::string errorStuff = "Can't identify token: ";
        errorStuff += token;
        LogError("lexer", std::to_string(line), errorStuff);
    }
}

bool Lexer::IsAlphaNumeric(char tokenIn)
{
    return IsDigit(tokenIn) || IsAlphabetic(tokenIn);
}

void Lexer::IdentifierToken()
{
    bool run = true;
    wholeToken += token;

    while(run){
        if(IsAlphaNumeric(Peek())) {
            TakeNext();
            wholeToken += token;
        }
        else run = false;
    }

    if (identityKeyMap.find(wholeToken) != identityKeyMap.end()) {
        tokens.emplace_back(identityKeyMap[wholeToken], wholeToken, line);
        return;
    }

    tokens.emplace_back(nameType, wholeToken, line);  
}

void Lexer::NumberToken()
{
    bool run = true;
    wholeToken += token;

    while(run){
        if(IsDigit(Peek())) {
            TakeNext();
            wholeToken += token;
        }
        else run = false;
    }

    tokens.emplace_back(numberType, wholeToken, line);
}

void Lexer::ScanToken(char& tokenIn)
{
    wholeToken = "";
    token = tokenIn;
    switch (token)
    {
    case ' ':
        break;
    case '=':
        PushToken(assingType);
        break;
    case '\n':
        line++;
        break;
    case '+':
        PushToken(additionType);
        break;
    case '-':
        PushToken(subtractioType);
        break;
    case '*':
        PushToken(subtractioType);
        break;
    case '/':
        PushToken(subtractioType);
        break;
    case ':':
        PushToken(functionType);
        break;
    case ';':
        PushToken(lineType);
        break;
    default:
        ScanLong();
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
    tokens.emplace_back(EOFType, "", line);

    WriteTokensToFile(tokens, "output.out");

    return 0;
}
