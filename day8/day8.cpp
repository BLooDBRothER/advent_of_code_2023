#include <iostream>
#include <readInput.h>
#include <chrono>

#include "utils.h"
#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> inputs = readInput("8");
    // vector<string> inputs = readInput("8", "sample2");

	string command;
	unordered_map<string, pair<string, string>> networks;

    parse_input(inputs, command, networks);

    auto start = high_resolution_clock::now();

    cout << "--- Part 1 --- \n" << part1::total_steps(command, networks) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" << part2::total_steps(command, networks) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;
}
