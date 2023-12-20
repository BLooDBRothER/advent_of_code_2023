#include <iostream>
#include <vector>

using namespace std;

namespace part2 {

    struct PairHash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &v) const
        {
            return std::hash<T1>()(v.first) ^ hash<T2>()(v.second) << 1;    
        }
    };

    optional<pair<int64_t, int64_t>> is_adjacent_symbol(vector<string> inputs, int64_t row, int64_t col) {
        vector<pair<int8_t, int8_t>> adjacent_coordinate {
            {-1, -1}, {0, -1}, {1, -1},
            {-1, 0}, {1, 0},
            {-1, 1}, {0, 1}, {1, 1}
        };

        auto is_valid_row = [&](int64_t row) -> bool { return row >= 0 && row < inputs.size(); };
        auto is_valid_col = [&](int64_t row, int64_t col) -> bool { return col >= 0 && col < inputs.at(row).size(); };
        auto is_symbol = [](char character) { return !isdigit(character) && character != '.' && character == '*'; };

        for (auto coordinates: adjacent_coordinate) {
            int64_t curr_row = row + coordinates.first, curr_col = col + coordinates.second;
            
            if(is_valid_row(curr_row) && is_valid_col(curr_row, curr_col) && is_symbol(inputs.at(curr_row).at(curr_col))){
                return make_pair(curr_row, curr_col);
            }
        }

        return nullopt;
    }

    int64_t sum_gear_ration(vector<string> inputs) {
        unordered_map<pair<int, int>, vector<int>, PairHash> gear_numbers;
        int64_t sum = 0;

        for(int64_t row = 0; row < inputs.size(); row++) {
            string row_input = inputs.at(row);
            pair<int, int> gear_ratio_coordinate;
            string number = "";
            bool is_adjacent_char_symbol = false;

            for(int64_t col = 0; col < row_input.size(); col++) {

                if(isdigit(row_input.at(col))) {
                    number += row_input.at(col);
                    
                    if(!is_adjacent_char_symbol){
                        optional<pair<int, int>> gear_ratio_coordinate_temp = is_adjacent_symbol(inputs, row, col);
                        if(gear_ratio_coordinate_temp.has_value()) {
                            is_adjacent_char_symbol = true;
                            gear_ratio_coordinate = gear_ratio_coordinate_temp.value();
                        }
                    }

                }
                else {
                    if(is_adjacent_char_symbol){
                        gear_numbers[gear_ratio_coordinate].push_back(stoi(number));
                    }
                    is_adjacent_char_symbol = false;
                    number = "";
                }
            }

            if(is_adjacent_char_symbol){
                gear_numbers[gear_ratio_coordinate].push_back(stoi(number));
            }
        }

        for (auto gear_number: gear_numbers) {

            if(gear_number.second.size() == 2)
                sum += gear_number.second.at(0) * gear_number.second.at(1);
        }

        return sum;
    }
}
