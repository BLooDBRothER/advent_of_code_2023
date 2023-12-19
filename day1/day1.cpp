#include <iostream>
#include <readInput.h>
#include <chrono>

#include "part1.h"
#include "part2.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> inputs = readInput("1");

    auto start = high_resolution_clock::now();

    cout << "--- Part 1 --- \n" << sumOfCalibrationValue(inputs) << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " ms" << endl;

    start = high_resolution_clock::now();

    cout << "--- Part 2 --- \n" <<sumOfCalibrationValuePartTwo(inputs) << endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken - "
         << (duration.count() / 1000000.0) << " ms" << endl;
}
