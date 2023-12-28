#include <iostream>
#include <readInput.h>
#include <chrono>

#include "utils.h"
#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    // vector<string> inputs = readInput("7", "sample");
    vector<string> inputs = readInput("7");
    
    unordered_map<string, int64_t> cards_bid_map;
	
    parse_input(inputs, cards_bid_map);

    auto start = high_resolution_clock::now();

    cout << "--- Part 1 --- \n" << part1::total_winnings(cards_bid_map) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" << part2::total_winnings(cards_bid_map) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " sec" << endl;
}
