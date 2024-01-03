#include <string>
#include <vector>
#include <strconv.h>

using namespace std;

void parse_input(vector<string> inputs, vector<vector<int64_t>>& report_values) {
    for(auto input: inputs) {
        int64_t idx = 0;
        vector<int64_t> report_value;
        while(idx < input.size()) {
            int64_t value = convert_string_to_number(input, idx);
            idx++;

            report_value.push_back(value);
        }
        report_values.push_back(report_value);
    }
}
