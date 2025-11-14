#include "Parser.h"
#include <stdexcept>

std::queue<Token> Parser::tokens;
Token Parser::currentToken;

//Run the parsing to AST
std::shared_ptr<AST> Parser::Parse(std::vector<Token>& tokensIn)
{
    for(Token item : tokensIn)
    {
        tokens.push(item);
    }
    currentToken = tokens.front();
    return Expression();
}

//Removes the current token from the list
void Parser::ConsumeToken(){
    if(!tokens.empty())
        tokens.pop();
        if(!tokens.empty())
            currentToken = tokens.front();
    else std::cout << "Parser was empty, couldn't pop token";
}

//Base priority
//Handles assignment & statements
std::shared_ptr<AST> Parser::Statement(){

}

//Low priority
//Handles addition, substraction
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

//Medium priority
//Handles multiplication and division
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

//Highest priority
//Handles grouping like '()' and variables like '17 or count'
std::shared_ptr<AST> Parser::Factor()
{
    try {
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
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}