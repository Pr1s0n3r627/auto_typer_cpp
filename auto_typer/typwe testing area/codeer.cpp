/*

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> breaker(const std::string& code) {
    std::vector<std::string> keystrokes;
    std::stringstream ss(code);
    std::string token;

    while (ss >> token) {
        for (char ch : token) {
            std::string str(1, ch);
            if (ch == ' ') {
                keystrokes.push_back("SPACE");
            } else {
                keystrokes.push_back(str);
            }
        }
        keystrokes.push_back("ENTER");
    }

    return keystrokes;
}

int main() {
    std::string code = R"(#include<iostream>
int Hello(){
std::cout<<"HeLLo";
return 0;
})";

    std::vector<std::string> result = breaker(code);

    for (const auto& ks : result) {
        std::cout << ks << " ";
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

bool isSpecial(char ch) {
    return ispunct(ch) && !ispunct(tolower(ch));
}

std::vector<std::string> breaker(const std::string& code) {
    std::vector<std::string> keystrokes;
    std::string current;

    auto flush = [&keystrokes, &current]() {
        if (!current.empty()) {
            keystrokes.push_back(current);
            current.clear();
        }
    };

    for (size_t i = 0; i < code.size(); ++i) {
        char ch = code[i];

        if (isspace(ch)) {
            flush();
            if (ch == ' ') {
                keystrokes.push_back("SPACE");
            } else if (ch == '\n') {
                keystrokes.push_back("ENTER");
            }
        } else if (isalpha(ch)) {
            if (!current.empty() && !isalpha(current.back())) {
                flush();
            }
            if (!current.empty() && ((islower(current.back()) && isupper(ch)) || (isupper(current.back()) && islower(ch)))) {
                flush();
            }
            current += ch;
        } else if (isSpecial(ch)) {
            flush();
            std::string str(1, ch);
            keystrokes.push_back(str);
        } else {
            if (!current.empty() && isalpha(current.back())) {
                flush();
            }
            current += ch;
        }
    }
    flush();
    return keystrokes;
}

int main() {
    std::string code = R"(#include<iostream>
int HeLLo(){
std::cout<<"HeLLo";
return 0;
})";

    std::vector<std::string> result = breaker(code);
    
    for (const auto& ks : result) {
        std::cout << ks << " ";
    }

    return 0;
}
