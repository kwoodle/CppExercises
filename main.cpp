//
// Created by kwoodle on 11/30?/17.
// Exercises for Bjarne Stroustrup: The C++ Programming Language (4th Edition). Addison-Wesley
//
#include <iostream>
#include <regex>
#include <string>
#include <fstream>

//using namespace std::chrono;
using std::string;
using std::ifstream;

int main() {
    // X.6 [5]
    // Use a reg ex to find all decimal numbers in a file.

    std::cout << "Enter filename. [e.g. floats.txt]\n";
    string fnam;
    std::cin >> fnam;
    ifstream is{fnam};
    string line;
    if (!is) {
        std::cerr << "Failed to open " << fnam << ".\n";
        return 1;
    }
    // from http://regexlib.com/DisplayPatterns.aspx?categoryId=3&AspxAutoDetectCookieSupport=1
    string pat_str{R"([-+]?\d+(\.\d+)?)"};
    std::regex pat{pat_str};
    int cnt{0};
    while (getline(is, line)) {
        std::smatch m;
        while (regex_search(line, m, pat)) {
            std::cout << m[0] << ", ";
            std::cout.flush();
            line = m.suffix().str();
            if (cnt % 20 == 19) std::cout << "\n";
            ++cnt;
        }
    }
    return 0;
}