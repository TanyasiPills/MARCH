#include <iostream>
#include <fstream>
#include <string>

void log_error(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
}
void log_info(const std::string& message) {
    std::cout << message << "\n";
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "No input file" << std::endl;
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

    std::ifstream input_file(input_filename);
    if (!input_file) {
        log_error("Could not open input file: " + input_filename);
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        log_info("Processing: " + line);
    }

    std::ofstream output_file(output_filename);
    if (output_file) {
        output_file << "Compiler output for: " << input_filename;
        log_info("Output written to: " + output_filename);
    } else {
        log_error("Failed to write to output file: " + output_filename);
    }

    return 0;
}