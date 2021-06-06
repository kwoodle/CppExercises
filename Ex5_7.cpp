//
// Created by kwoodle on 1/31/19.
//

#include "Peeps.h"
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//
// X.5 [7]
// (∗2) Initialize a vector<int> with the elements 5 , 9 , −1 , 200 , and 0 . Print it. Sort is, and print it
// again.
//
int main() {
    vector<int> v{5, 9, -1, 200, 0};
    for (auto &e: v) {
        cout << e << ", ";
    }
    cout << "\n";
    sort(v.begin(), v.end());
    for (auto &e: v) {
        cout << e << ", ";
    }
    cout << "\n";

// X.5 [8]
// ∗1) Repeat §X.5[7] with a vector<string> initialized with "Kant" , "Plato" , "Aristotle" ,
// "Kierkegard" , and "Hume" .
//
    vector<string> vs{"Kant", "Plato", "Aristotle", "Kierkigard", "Hume"};
    for (auto &e: vs) {
        cout << e << ", ";
    }
    cout << "\n";
    sort(vs.begin(), vs.end());
    for (auto &e: vs) {
        cout << e << ", ";
    }
    cout << "\n";

//
// X.5 [6]
// (∗1.5) Redo §X.5[5], storing several (name,age) pairs in a class. Doing the reading and writ-
// ing using your own >> and << operators.
//
    Peeps p;
    cout << "Enter pairs\n";
    cin >> p;
    cout << p;

//
// X.5 [5]
// (∗1.5) Write a program that reads a name (a string ) and an age (an int ) from the standard
// input stream cin. Then output a message including the name and age to the standard output
// stream cout.
//
    string s;
    int i;
    cout << "Enter a Name\n";
    cin >> s;
    cout << "Enter an Age\n";
    cin >> i;
    cout << "Name " << s << "   Age " << i << "\n";

    return 0;

}
