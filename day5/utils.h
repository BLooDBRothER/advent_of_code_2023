#include <string>
#include <unordered_map>
#include <strconv.h>

using namespace std;

void extract_seed(string input, vector<int64_t>& seeds) {
    int64_t idx = 7;
    while(idx < input.size()) {
        seeds.push_back(convert_string_to_number(input, idx));
        idx++;
    }
}

void parse_input(vector<string> inputs, vector<int64_t>& seeds, unordered_map<string, vector<vector<int64_t>>>& input_map) {
    extract_seed(inputs.at(0), seeds);

    bool is_header = true;
    string header = "";
    for (int64_t row = 2; row < inputs.size(); row++) {
        string input = inputs.at(row);

        if(input == ""){
            is_header = true;
            header = "";
            continue;
        }

        if(is_header) {
            header = input.substr(0, input.find(" "));
            is_header = false;
        }
        else {
            int64_t char_idx = 0;
            vector<int64_t> input_number;
            while (char_idx < input.size()) {
                input_number.push_back(convert_string_to_number(input, char_idx));
                char_idx++;
            }

            input_map[header].push_back(input_number);
        }
    }
}
