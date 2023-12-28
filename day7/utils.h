#include <string>
#include <unordered_map>
#include <strconv.h>

using namespace std;

vector<string> CARD_TYPE_ORDER {
	"high_card",
	"one_pair",
	"two_pair",
	"three_kind",
	"full_house",
	"four_kind",
	"five_kind",
};

void parse_input(vector<string> inputs, unordered_map<string, int64_t>& cards_bid_map) {

    for (auto input: inputs) {
        int64_t card_split_pos = input.find(" ");
        int64_t bid_split_pos = card_split_pos + 1;
        cards_bid_map[input.substr(0, card_split_pos)] = convert_string_to_number(input, bid_split_pos);
    }

}
