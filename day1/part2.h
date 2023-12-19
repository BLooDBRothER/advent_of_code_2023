#include <iostream>
#include <cctype>
#include <algorithm>
#include <ranges>
#include <string_view>
#include <unordered_map>


using namespace std;

int64_t extract_first_and_last_digit(string_view line, unordered_map<string, int> char_digit_to_digit) {
	int64_t min = INT64_MAX, max = INT64_MIN, first, last;

	for (auto char_to_digit_map : char_digit_to_digit) {
		vector<int64_t> indexes;
		int64_t initialIndex = line.find(char_to_digit_map.first);
		
		while(initialIndex != string::npos) {
			indexes.push_back(initialIndex);
			initialIndex = line.find(char_to_digit_map.first, initialIndex + 1);
		}

		for (auto index: indexes) {
			if(index < min) {
				first = char_to_digit_map.second;
				min = index;
			}

			if(index > max) {
				last = char_to_digit_map.second;
				max = index;
			}
		}

	}
	return (first * 10) + last;
}

int64_t sumOfCalibrationValuePartTwo(vector<string> inputs) {
	unordered_map<string, int> char_digit_to_digit {
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"1", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
		{"0", 0},
	};
	
	int64_t sum = 0;
	for (string input: inputs) {
		sum += extract_first_and_last_digit(input, char_digit_to_digit);
		// cout << "sum " << sum << endl;
	}

	return sum;
}
