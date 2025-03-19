#include "AST.h"
#include <vector>
#include <queue>

class Parser{
private:
    static std::queue<Token> tokens;
    static Token currentToken;
    static std::shared_ptr<AST> Expression();
    static std::shared_ptr<AST> Term();
    static std::shared_ptr<AST> Factor();

    static void ConsumeToken();
public:
    static std::shared_ptr<AST> Parse(std::vector<Token>& tokensIn);
};