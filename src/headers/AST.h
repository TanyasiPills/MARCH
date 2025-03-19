#include "Token.h"
#include <memory>

class AST{
public:
    virtual ~AST() = default;
};

class IntNode : public AST {
public:
    int value;
    TokenType type;

    IntNode(int valueIn, TokenType typeIn) 
        : value(valueIn), type(typeIn) {}   
};

class BinaryOPNode : public AST {
public:
    enum class Op {ADD, SUB, MUL, DIV};
    std::shared_ptr<AST> left, right;
    Op op;

    BinaryOPNode(std::shared_ptr<AST> leftIn, std::shared_ptr<AST> rightIn, Op opIn) 
        : left(leftIn), right(rightIn), op(opIn) {}   
};

class GroupNode : public AST {
    std::shared_ptr<AST> expression;

    GroupNode(std::shared_ptr<AST> expr) 
        : expression(expr) {}
};