#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace part1 {

    bool is_adjacent_symbol(vector<string> inputs, int64_t row, int64_t col) {
        vector<pair<int8_t, int8_t>> adjacent_coordinate {
            {-1, -1}, {0, -1}, {1, -1},
            {-1, 0}, {1, 0},
            {-1, 1}, {0, 1}, {1, 1}
        };

        auto is_valid_row = [&](int64_t row) -> bool { return row >= 0 && row < inputs.size(); };
        auto is_valid_col = [&](int64_t row, int64_t col) -> bool { return col >= 0 && col < inputs.at(row).size(); };
        auto is_symbol = [](char character) { return !isdigit(character) && character != '.'; };

        for (auto coordinates: adjacent_coordinate) {
            int64_t curr_row = row + coordinates.first, curr_col = col + coordinates.second;
            
            if(is_valid_row(curr_row) && is_valid_col(curr_row, curr_col) && is_symbol(inputs.at(curr_row).at(curr_col))){
                return true;
            }
        }
        return false;
    }

    int64_t sum_engine_schematic(vector<string> inputs) {
        int64_t sum = 0;

        for(int64_t row = 0; row < inputs.size(); row++) {
            string row_input = inputs.at(row);
            string number = "";
            bool is_adjacent_char_symbol = false;

            for(int64_t col = 0; col < row_input.size(); col++) {

                if(isdigit(row_input.at(col))) {
                    number += row_input.at(col);
                    
                    if(!is_adjacent_char_symbol){
                        is_adjacent_char_symbol = is_adjacent_symbol(inputs, row, col);
                    }

                }
                else {
                    if(is_adjacent_char_symbol){
                        sum += stoi(number);
                    }
                    is_adjacent_char_symbol = false;
                    number = "";
                }
            }

            if(is_adjacent_char_symbol){
                sum += stoi(number);
            }
        }

        return sum;
    }
}
