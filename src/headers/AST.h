#include "Token.h"
#include <memory>

class AST{
public:
    virtual ~AST() = default;
    virtual void print() const = 0;
};

class IntNode : public AST {
private:
    int value;
public:
    IntNode(int valueIn) 
        : value(valueIn) {}   

    void print() const override {
        std::cout << value;
    }
};

class BinaryOpNode : public AST {
private:
    std::shared_ptr<AST> left, right;
    TokenType op;
public:
    BinaryOpNode(std::shared_ptr<AST> leftIn, std::shared_ptr<AST> rightIn, TokenType opIn) 
        : left(leftIn), right(rightIn), op(opIn) {}   

    void print() const override {
        left->print();
        if(op == TokenType::additionType) 
            std::cout << " + ";
        if(op == TokenType::subtractioType) 
            std::cout << " - ";
        if(op == TokenType::multiplicationType) 
            std::cout << " * ";
        if(op == TokenType::divisionType) 
            std::cout << " / ";
        right->print();
    }
};

class GroupNode : public AST {
private:
    std::shared_ptr<AST> expression;
public:
    GroupNode(std::shared_ptr<AST> expr) 
        : expression(expr) {}

    void print() const override {
        std::cout << "(";
        expression->print();
        std::cout << ")";
    }
};

class AssignmentNode : public AST {
private:
    std::string variableName;
    std::shared_ptr<AST> expression;
public:
    AssignmentNode(const std::string& var, std::shared_ptr<AST> expr)
        : variableName(var), expression(expr) {}

    void print() const override {
        std::cout << variableName << " = ";
        expression->print();
    }
};