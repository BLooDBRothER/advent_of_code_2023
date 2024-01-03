#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

namespace part2 {
    int64_t gcd(int64_t a, int64_t b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    int64_t findlcm(vector<int64_t> arr, int64_t n)
    {
        int64_t ans = arr[0];
    
        for (int64_t i = 1; i < n; i++)
            ans = (((arr[i] * ans)) /
                    (gcd(arr[i], ans)));
    
        return ans;
    }

    int64_t total_steps(string command, unordered_map<string, pair<string, string>> networks) {
        vector<string> curr_networks;
        vector<int64_t> network_steps;

        for (auto network: networks) {
            if(network.first[2] == 'A'){
                curr_networks.push_back(network.first);
            }
        }



        for(int64_t idx = 0; idx < curr_networks.size(); idx++) {
            string curr_network = curr_networks.at(idx);
            int64_t command_idx = 0;
            int64_t steps = 0;
            int64_t cmd_idx = 0;

            cout << curr_network << endl;

            while (curr_network[2] != 'Z') {
                pair<string, string> nodes = networks[curr_network];

                curr_network = command[cmd_idx] == 'R' ? nodes.second : nodes.first;

                cmd_idx = (cmd_idx + 1) % command.size();
                steps++;
            }
            cout << curr_network << " " << steps << endl;
            network_steps.push_back(steps);
        }

        int64_t lcm = findlcm(network_steps, network_steps.size());

        return lcm;
    }
}

