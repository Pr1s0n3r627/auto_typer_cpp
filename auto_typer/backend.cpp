#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream inputFile("text.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    // Step 1: Read all text into the variable 'code'
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string code = buffer.str();

    // Step 2: Print 'code'
    std::cout << "Original code:\n" << code << std::endl;

    // Step 3: Remove leading spaces from each line and store in 'no_indent_code'
    std::istringstream codeStream(code);
    std::string no_indent_code;
    std::string line;

    while (getline(codeStream, line)) {
        line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        no_indent_code += line + "\n";
    }

    // Step 4: Print 'no_indent_code'
    std::cout << "Code without indents:\n" << no_indent_code << std::endl;

    inputFile.close();
    return 0;
}
