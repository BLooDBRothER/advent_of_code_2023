#include <iostream>

using namespace std;

namespace part1 {
    void map_each_input(vector<int64_t>& inputs, vector<vector<int64_t>> input_maps_numbers) {
        auto is_between_range = [](int64_t input, int64_t start, int64_t end) -> bool { return input >= start && input <= end; };

        for (auto& input: inputs) {
            for(auto input_map_numbers: input_maps_numbers) {
                int64_t range = input_map_numbers.at(2);
                int64_t src_start = input_map_numbers.at(1);
                int64_t src_end = src_start + range;
                
                if(is_between_range(input, src_start, src_end)) {
                    input = (input - src_start) +  input_map_numbers.at(0);
                    break;
                }
            }
        }
    }

    int64_t find_small_location(vector<int64_t> seeds, unordered_map<string, vector<vector<int64_t>>> input_map, vector<string> order) {
        int64_t small_location = INT64_MAX;
        vector<int64_t> test = seeds;
        for (auto map_order: order) {
            map_each_input(seeds, input_map[map_order]);
        }

        for (auto result: seeds) {
            if(result < small_location)
                small_location = result;
        }

        return small_location;
    }
}
