#include <iostream>

using namespace std;

namespace part2 {
    vector<vector<int64_t>> map_each_input(vector<vector<int64_t>> inputs, vector<vector<int64_t>> input_maps_numbers) {

        auto is_between_range = [](int64_t input, int64_t start, int64_t end) -> bool { return input >= start && input <= end; };
        vector<vector<int64_t>> result;

        for(int idx = 0; idx < inputs.size(); idx++) {
            vector<int64_t> input = inputs.at(idx);
            bool flag = true;

            for(auto input_map_numbers: input_maps_numbers) {
                int64_t map_range = input_map_numbers.at(2);

                int64_t src_map_start = input_map_numbers.at(1);
                int64_t src_map_end = src_map_start + map_range - 1;

                int64_t dest_map_start = input_map_numbers.at(0);

                int64_t src_range = input.at(1);
                int64_t src_start = input.at(0);
                int64_t src_end = src_start + src_range - 1;

                if(is_between_range(src_start, src_map_start, src_map_end) && is_between_range(src_end, src_map_start, src_map_end)) {
                    flag = false;

                    int64_t dest_start = src_start + (dest_map_start - src_map_start);
                    result.push_back({dest_start, src_range});
                }
                else if(is_between_range(src_start, src_map_start, src_map_end) && !is_between_range(src_end, src_map_start, src_map_end)) {
                    flag = false;

                    int64_t dest_start = src_start + (dest_map_start - src_map_start);
                    int64_t dest_range = (src_map_end - src_start) + 1;
                    result.push_back({dest_start, dest_range});

                    inputs.push_back({src_start + dest_range, src_range - dest_range});
                }
                else if(!is_between_range(src_start, src_map_start, src_map_end) && is_between_range(src_end, src_map_start, src_map_end)) {
                    flag = false;

                    inputs.push_back({src_start, src_map_start - src_start});

                    int64_t dest_start = dest_map_start;
                    int64_t dest_range = src_range - (src_map_start - src_start);
                    result.push_back({dest_start, dest_range});
                }
            }

            if(flag)
                result.push_back(input);
        }
        return result;
    }

    int64_t find_small_location(vector<int64_t> seed_ranges, unordered_map<string, vector<vector<int64_t>>> input_map, vector<string> order) {
        vector<vector<int64_t>> seeds;
        unordered_map<string, vector<vector<int64_t>>> inputs;
        int64_t small_location = INT64_MAX;
        
        for (int64_t idx = 0; idx < seed_ranges.size() - 1; idx += 2) {
            seeds.push_back({seed_ranges.at(idx), seed_ranges.at(idx + 1)});
            inputs["seeds"].push_back({seed_ranges.at(idx), seed_ranges.at(idx + 1)});
        }

        order.insert(order.begin(), "seeds");

        for(int i=0; i<order.size() - 1; i++) {
            inputs[order[i + 1]] = map_each_input(inputs[order[i]], input_map[order[i + 1]]);
        }

        for (auto result: inputs[order.at(order.size() - 1)]) {
            if(result.at(0) < small_location)
                small_location = result.at(0);
        }

        return small_location;
    }
}
