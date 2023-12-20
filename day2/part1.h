#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <string_view>
#include <ranges>
#include <numeric>

using namespace std;

bool is_valid_game(unordered_map<string_view, int64_t> ball_count) {
    return ball_count["red"] <= 12 && ball_count["green"] <= 13 && ball_count["blue"] <= 14;
}

int validate_game_play(string input) {
    string number;

    int64_t pos = 5;
    int64_t game_id = convert_string_to_number(input, pos);

    unordered_map<string_view, int64_t> ball_count;

    ball_count = {
        {"red", 0},
        {"green", 0},
        {"blue", 0}
    };

    while(pos < input.size()) {
        while(pos < input.size() && !isdigit(input.at(pos))){
            pos++;
            continue;
        }

        int64_t count = convert_string_to_number(input, pos);
        pos++;
        string ball_color = input.at(pos) == 'r' ? "red" : input.at(pos) == 'g' ? "green" : "blue";
        ball_count[ball_color] += count;

        pos += ball_color.size();

        if(pos >= input.size() || input.at(pos) == ';') {
            if(!is_valid_game(ball_count))
                return 0;
             
            ball_count = {
                    {"red", 0},
                    {"green", 0},
                    {"blue", 0}
                };
        }

    }

    return game_id;
}

int64_t sum_game_ids(vector<string> inputs) {
    int64_t sum = 0;
    for (auto input: inputs) {
        sum += validate_game_play(input);
    }
    return sum;
}
