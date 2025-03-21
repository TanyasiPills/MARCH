#include "Parser.h"
#include <stdexcept>

std::queue<Token> Parser::tokens;
Token Parser::currentToken;

std::shared_ptr<AST> Parser::Parse(std::vector<Token>& tokensIn)
{
    for(Token item : tokensIn)
    {
        tokens.push(item);
    }
    currentToken = tokens.front();
    return Expression();
}

void Parser::ConsumeToken(){
    if(!tokens.empty())
        tokens.pop();
        if(!tokens.empty())
            currentToken = tokens.front();
    else std::cout << "Parser was empty, couldn't pop token";
}
std::shared_ptr<AST> Parser::Expression()
{
    auto left = Term();

    while(currentToken.type == TokenType::additionType || currentToken.type == TokenType::subtractioType)
    {
        TokenType op = currentToken.type;
        ConsumeToken();

        auto right = Term();

        left = std::make_shared<BinaryOpNode>(left, right, op);
    }

    return left;
}

std::shared_ptr<AST> Parser::Term()
{
    auto left = Factor();

    while(currentToken.type == TokenType::multiplicationType || currentToken.type == TokenType::divisionType)
    {
        TokenType op = currentToken.type;
        ConsumeToken();

        auto right = Factor();

        left = std::make_shared<BinaryOpNode>(left, right, op); 
    }
    
    return left;
}

std::shared_ptr<AST> Parser::Factor()
{
    if(currentToken.type == TokenType::numberType)
    {
        int value = std::stoi(currentToken.lexeme);
        ConsumeToken();

        return std::make_shared<IntNode>(value);
    }
    else if(currentToken.type == TokenType::LBraceType)
    {
        ConsumeToken();
        auto expr = Expression();
        if(currentToken.type != TokenType::RBraceType){
            throw std::runtime_error("Expected ')'");
        }
        ConsumeToken();
        return std::make_shared<GroupNode>(expr);
    }

    throw std::runtime_error("Unexpected token at line: "+std::to_string(currentToken.line)+"; Token: "+currentToken.lexeme);
}