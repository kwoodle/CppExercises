//
// Created by kwoodle on 12/1/17.
//

#ifndef CPPEXERCISES_PEEPS_H
#define CPPEXERCISES_PEEPS_H

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Peeps {
public:
    map<string, int> peeps;
};

ostream &operator<<(ostream &os, const Peeps &Peeps) {
    for (auto& p : Peeps.peeps) {
        os << "name: " << p.first << "   age: " << p.second << "\n";
    }
    return os;
}

istream &operator>>(istream &is, Peeps &P) {
    string line;
    string nm;
    int ag;
    while (std::getline(is, line).good()) {
        istringstream ss(line);
        if (ss.str().length() == 0)
            break;
        ss >> nm >> ag;
        P.peeps[nm] = ag;
    }
    return is;
}

#endif //CPPEXERCISES_PEEPS_H
