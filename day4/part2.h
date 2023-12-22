#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

namespace part2 {

    void create_winning_number_map(string input, int64_t start_idx, int64_t stop_idx, unordered_map<int64_t, bool>& number_map) {
        string number;
        while(start_idx < stop_idx) {
            if(isdigit(input.at(start_idx))) 
                number += input.at(start_idx);
            else {
                if(number != "")
                    number_map[stoi(number)] = true;
                number = "";
            }
            start_idx++;
        }
    }

    void create_card_copy(string input, int64_t start_idx, int64_t stop_idx, int64_t game_id, unordered_map<int64_t, bool> number_map, unordered_map<int64_t, int64_t>& card_count) {
        string number;
        int64_t card_match_count = 0;

        while(start_idx < stop_idx) {
            if(isdigit(input.at(start_idx))) 
                number += input.at(start_idx);
            else {
                if(number != "" && number_map[stoi(number)])
                    card_count[(++card_match_count) + game_id] += 1 + card_count[game_id];
                number = "";
            }
            start_idx++;
        }

        if(number != "" && number_map[stoi(number)])
            card_count[(++card_match_count) + game_id] += 1 + card_count[game_id];

    }

    int64_t sum_total_cards(vector<string> inputs) {
        int64_t sum = 0;
        unordered_map<int64_t, int64_t> card_count;

        int64_t game_id = 1;
        for (string input: inputs) {
            unordered_map<int64_t, bool> winning_number_map;
            int64_t winning_number_start_idx = input.find(':') + 1;
            int64_t winning_number_stop_idx = input.find('|');
            
            create_winning_number_map(input, winning_number_start_idx, winning_number_stop_idx, winning_number_map);
            create_card_copy(input, winning_number_stop_idx + 1, input.size(), game_id, winning_number_map, card_count);

            sum += card_count[game_id] + 1;
            game_id++;
        }

        return sum;
    }
}
