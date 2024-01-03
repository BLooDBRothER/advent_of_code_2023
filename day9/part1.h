#include <vector>
#include <string>

using namespace std;

namespace part1 {
    int64_t find_next_in_series(vector<int64_t> series) {
        vector<int64_t> next_series;

        bool is_all_same = true;

        for(int idx = 1; idx < series.size(); idx++) {
            int64_t diff = series[idx] - series[idx - 1];

            if(is_all_same && idx != 1 && diff != next_series[idx - 2]) {
                is_all_same = false;
            }

            next_series.push_back(diff);
        }

        int64_t next_series_last_value = next_series.at(next_series.size() - 1);
        int64_t curr_series_last_value = series.at(series.size() - 1);

        return is_all_same ? curr_series_last_value + next_series_last_value : (curr_series_last_value + find_next_in_series(next_series));
    }

    int64_t sum_next_value(vector<vector<int64_t>> report_values) {
        int64_t sum = 0;

        for(auto report_value: report_values) {
            sum += find_next_in_series(report_value);
        }

        return sum;
    }
}
