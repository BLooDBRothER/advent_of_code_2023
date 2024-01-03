#include<string>
#include<unordered_map>

using namespace std;

namespace part1 {
    int64_t total_steps(string command, unordered_map<string, pair<string, string>> networks) {
        int64_t steps = 0;
        string curr_network = "AAA";
        int64_t idx = 0;

        while (curr_network != "ZZZ") {
            pair<string, string> nodes = networks[curr_network];

            curr_network = command[idx] == 'R' ? nodes.second : nodes.first;

            idx = (idx + 1) % command.size();
            steps++;
        }

        return steps;
    }
}

