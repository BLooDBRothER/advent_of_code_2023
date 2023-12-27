#include <string>
#include <unordered_map>
#include<ranges>
#include <strconv.h>

using namespace std;

void parse_input_part1(vector<string> inputs, vector<pair<int64_t, int64_t>>& time_distance) {
    string time = inputs.at(0), distance = inputs.at(1);
    
    int64_t time_idx = time.find(':') + 1;
    int64_t distance_idx = distance.find(':') + 1;

    while(time_idx < inputs.at(0).size() && distance_idx < inputs.at(1).size()) {
        while(!isdigit(time.at(time_idx)))
            time_idx++;
        while(!isdigit(distance.at(distance_idx)))
            distance_idx++;

        time_distance.push_back(make_pair(convert_string_to_number(time, time_idx), convert_string_to_number(distance, distance_idx)));
    }
}

void parse_input_part2(vector<pair<int64_t, int64_t>>& time_distance_pairs, pair<int64_t, int64_t>& time_distance) {
    string time = "", distance = "";
    for(auto time_distance_pair: time_distance_pairs) {
        time += to_string(time_distance_pair.first);
        distance += to_string(time_distance_pair.second);
    }

    time_distance = { stoll(time), stoll(distance) };
}
