#include <iostream>
#include <readInput.h>
#include <chrono>

#include "utils.h"
#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> inputs = readInput("9");
    
    auto start = high_resolution_clock::now();

    vector<vector<int64_t>> report_values;

    parse_input(inputs, report_values);

    cout << "--- Part 1 --- \n" << part1::sum_next_value(report_values) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" << part2::sum_next_value(report_values) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;
}
