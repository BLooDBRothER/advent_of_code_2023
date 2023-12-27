#include <iostream>

using namespace std;

namespace part2 {

    int64_t total_record(pair<int64_t, int64_t> time_distance) {
        int64_t count = 0;
        for(int hold_time = 1; hold_time < time_distance.first; hold_time++) {
            int64_t distance_covered = hold_time * (time_distance.first - hold_time);

            if(distance_covered > time_distance.second)
                count++;
        }

        return count;
    }
}
