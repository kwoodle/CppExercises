//
// Created by kwoodle on 1/22/19.
//

#include <vector>
#include <functional>
#include <random>
#include <chrono>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace std::chrono;
namespace boofs = boost::filesystem;        // to get name of executable


// X.6 [3]
// (∗2) Time a loop. Write out the time in milliseconds. Do this for the default setting of your
// compiler and for a setting using an optimizer (e.g., −O2 or "release"). Be careful not to have
// the optimizer eliminate your whole loop as dead code because you did not use a result.
// Release vs Debug g++ 20000 vs 200000 ns
//
int main(int argc, char *argv[]) {
    boofs::path app_path{argv[0]};
    const string& rundir = app_path.string();
    string app_name = app_path.filename().string();
    string found;
    size_t pos = rundir.find("debug");
    if (pos != string::npos) {
        found = "debug";
        cout << "found = debug\n";
    } else {
        pos = rundir.find("release");
        if (pos != string::npos) {
            found = "release";
            cout << "found = release\n";
        } else {
            cout << "Could not find rundir!\n";
            exit(1);
        }
    }
    string ofile{"../"};
    ofile += app_name;
    ofile += "_outfile";
    ofstream ofs(ofile, ios::app);
    string outstring{"Output for "};
    outstring += app_name;
    int out;
    int imax{100000};
    cout << "Starting Loop for imax = " << imax << "\t mode = " << found << "\n";
    ofs << "Starting Loop for imax = " << imax << "\t mode = " << found << "\n";
    auto t0 = high_resolution_clock::now();
    for (int i = 0; i < imax; ++i) {
        out += i;
    }
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(t1 - t0).count() << " nanoseconds passed.\n";
    cout << "out = " << out << "\n";
    ofs << duration_cast<nanoseconds>(t1 - t0).count() << " nanoseconds passed.\n";
    ofs << "out = " << out << "\n";
    return 0;
}

