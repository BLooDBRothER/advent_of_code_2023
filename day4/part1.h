#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

namespace part1 {

    void create_winning_number_map(string input, int64_t start_idx, int64_t stop_idx, unordered_map<int64_t, bool>& number_map) {
        string number;
        while(start_idx < stop_idx) {
            if(isdigit(input.at(start_idx))) 
                number += input.at(start_idx);
            else {
                if(number != "")
                    number_map[stoi(number)] = true;
                number = "";
            }
            start_idx++;
        }
    }

    int64_t card_point(string input, int64_t start_idx, int64_t stop_idx, unordered_map<int64_t, bool> number_map) {
        string number;
        int64_t point_count = 0;

        while(start_idx < stop_idx) {
            if(isdigit(input.at(start_idx))) 
                number += input.at(start_idx);
            else {
                if(number != "" && number_map[stoi(number)])
                    point_count++;
                number = "";
            }
            start_idx++;
        }

        if(number != "" && number_map[stoi(number)])
            point_count++;

        return pow(2, --point_count);
    }

    int64_t sum_total_points(vector<string> inputs) {
        int64_t sum = 0;

        for (string input: inputs) {
            unordered_map<int64_t, bool> winning_number_map;
            int64_t winning_number_start_idx = input.find(':') + 1;
            int64_t winning_number_stop_idx = input.find('|');
            
            create_winning_number_map(input, winning_number_start_idx, winning_number_stop_idx, winning_number_map);
            sum += card_point(input, winning_number_stop_idx + 1, input.size(), winning_number_map);
        }

        return sum;
    }
}
