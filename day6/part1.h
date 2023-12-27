#include <iostream>

using namespace std;

namespace part1 {

    int64_t total_record(pair<int64_t, int64_t> time_distance) {
        int64_t count = 0;
        for(int hold_time = 1; hold_time < time_distance.first; hold_time++) {
            int64_t distance_covered = hold_time * (time_distance.first - hold_time);

            if(distance_covered > time_distance.second)
                count++;
        }

        return count == 0 ? 1 : count;
    }

    int64_t ways_to_beat_record(vector<pair<int64_t, int64_t>> time_distance_pairs) {
        int64_t total_ways = 1;

        for(auto time_distance: time_distance_pairs) {
            total_ways *= total_record(time_distance);
        }

        return total_ways;
    }
}
