#include "Token.h"
#include <memory>

class AST{
public:
    virtual ~AST() = default;
};

class IntNode : public AST {
public:
    int value;

    IntNode(int valueIn, TokenType typeIn) 
        : value(valueIn) {}   
};

class BinaryOPNode : public AST {
public:
    std::shared_ptr<AST> left, right;
    TokenType op;

    BinaryOPNode(std::shared_ptr<AST> leftIn, std::shared_ptr<AST> rightIn, TokenType opIn) 
        : left(leftIn), right(rightIn), op(opIn) {}   
};

class GroupNode : public AST {
    std::shared_ptr<AST> expression;

    GroupNode(std::shared_ptr<AST> expr) 
        : expression(expr) {}
};