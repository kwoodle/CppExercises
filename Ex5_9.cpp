//
// Created by kwoodle on 1/31/19.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
//
// X.5 [9] (∗1) Open a file for writing (as an ofstream ) and write a few hundred integers to it.
//    [10] (∗1) Open the file of integers from §X.5[9] for reading (as an ifstream ) and read it.
//

int main() {

    ofstream ofile{"test.txt", ios_base::trunc};
    for (int i = 1; i < 250; ++i) {
        ofile << i << " ";
        if (i % 20 == 19)
            ofile << "\n";
    }
    ofile.close();
    ifstream ifile{"test.txt"};
    if (!ifile.is_open())
        return 1;
    string line;
    vector<int> Ints;
    while (std::getline(ifile, line)) {
        istringstream ss(line);
        int I;
        while (ss >> I) {
            Ints.push_back(I);
        }
    }
    cout << "\nContents of file\n";
    int ii = 0;
    for (auto e:Ints) {
        cout << e << ", ";
        ++ii;
        if (ii % 20 == 19)
            cout << "\n";
    }
    return 0;
}