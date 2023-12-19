#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int64_t sumOfCalibrationValue(vector<string> inputs) {
    int64_t sum = 0;
    for (string input: inputs) {
        int64_t first = -1, last = -1;
        for (char eachChar: input) {
            if(isdigit(eachChar)) {
                if(first == -1)
                    first = eachChar - 48;
                last = eachChar - 48;
            }

        }
        sum += (first * 10 + last);
    }

    return sum;
}
