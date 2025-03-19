#include "AST.h"
#include <vector>
#include <queue>

class Parser{
private:
    static std::queue<Token> tokens;
    static std::shared_ptr<AST> Expression();
    static std::shared_ptr<AST> Term();
    static std::shared_ptr<AST> Factor();

    static void ConsumeToken();

};