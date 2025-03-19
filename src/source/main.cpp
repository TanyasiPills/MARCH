#include <string>

#include "Logger.h"
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
    if(argc < 2){
        Log("No input file");
        return 1;
    }

    std::string input_filename = argv[1];
    std::string output_filename = "main.exe";

    for (int i = 2; i < argc; ++i) {
        if (std::string(argv[i]) == "-o" && i + 1 < argc) {
            output_filename = argv[i + 1];
            i++;
        }
    }

    if(Lexer::ProcessFile(input_filename)) return 1;
    auto resultOfParse = Parser::Parse(Lexer::tokens);
    resultOfParse->print();
    return 0;
};