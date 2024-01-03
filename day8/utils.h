#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;



void parse_input(vector<string> inputs, string& command, unordered_map<string, pair<string, string>>& networks) {
    command = inputs.at(0);

    for(int idx = 2; idx < inputs.size(); idx++) {
        string input = inputs.at(idx);
        string network = input.substr(0, 3);
        string left_node = input.substr(7, 3);
        string right_node = input.substr(12, 3);
        
        networks[network] = make_pair(left_node, right_node);
    }
}
