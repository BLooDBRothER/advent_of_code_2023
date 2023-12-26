#include <iostream>
#include <readInput.h>
#include <chrono>

#include "utils.h"
#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> inputs = readInput("5");

    vector<int64_t> seeds;
    unordered_map<string, vector<vector<int64_t>>> input_map;
    vector<string> order {
     "seed-to-soil",
     "soil-to-fertilizer",
     "fertilizer-to-water",
     "water-to-light",
     "light-to-temperature",
     "temperature-to-humidity",
     "humidity-to-location"
    };

    parse_input(inputs, seeds, input_map);

    auto start = high_resolution_clock::now();

    cout << "--- Part 1 --- \n" << part1::find_small_location(seeds, input_map, order) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" << part2::find_small_location(seeds, input_map, order) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;
}
