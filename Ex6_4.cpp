//
// Created by kwoodle on 1/22/19.
//


#include <vector>
#include <functional>
#include <random>
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;

int main() {
    // X.6 [4]
    // (∗2) Repeat the histogram drawing example from §5.6.3 for a normal_distribution and 30
    // rows.
    //
    auto gen = std::bind(normal_distribution<double>{15, 4.0}, default_random_engine{});
    vector<int> hist(30);
    for (int i = 0; i < 2000; ++i) {
        ++hist[gen()];
    }
    for (int i = 0; i != hist.size(); ++i) {
        cout << i << "\t";
        for (int j = 0; j != hist[i]; ++j) cout << "*";
        cout << "\n";
    }
    return 0;
}
