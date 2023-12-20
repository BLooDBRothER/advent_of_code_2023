#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <string_view>
#include <ranges>
#include <numeric>

using namespace std;

void update_max_balls(unordered_map<string_view, int64_t>& ball_count, unordered_map<string_view, int64_t> ball_count_temp) {
    if(ball_count["red"] < ball_count_temp["red"])
        ball_count["red"] = ball_count_temp["red"];

    if(ball_count["green"] < ball_count_temp["green"])
        ball_count["green"] = ball_count_temp["green"];
        
    if(ball_count["blue"] < ball_count_temp["blue"])
        ball_count["blue"] = ball_count_temp["blue"];
}

int power_cube_play(string input) {
    string number;

    int64_t pos = 5;
    int64_t game_id = convert_string_to_number(input, pos);

    unordered_map<string_view, int64_t> ball_count, ball_count_temp;

    ball_count = ball_count_temp = {
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
        ball_count_temp[ball_color] += count;

        pos += ball_color.size();

        if(pos >= input.size() || input.at(pos) == ';') {
            update_max_balls(ball_count, ball_count_temp);

            ball_count_temp = {
                    {"red", 0},
                    {"green", 0},
                    {"blue", 0}
                };
        }
    }

    return ball_count["red"] * ball_count["green"] * ball_count["blue"];

}

int64_t sum_power_cubes(vector<string> inputs) {
    int64_t sum = 0;
    for (auto input: inputs) {
        sum += power_cube_play(input);
    }
    return sum;
}
