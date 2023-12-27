#include <iostream>
#include <readInput.h>
#include <chrono>

#include "utils.h"
#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> inputs = readInput("6");
    // vector<string> inputs = readInput("6", "sample");

    vector<pair<int64_t, int64_t>> time_distance_pairs;

    parse_input_part1(inputs, time_distance_pairs);
    
    auto start = high_resolution_clock::now();

    cout << "--- Part 1 --- \n" << part1::ways_to_beat_record(time_distance_pairs) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;

    pair<int64_t, int64_t> time_distance;
	parse_input_part2(time_distance_pairs, time_distance);

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" << part2::total_record(time_distance) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;
}
