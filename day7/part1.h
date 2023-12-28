#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

namespace part1 {

    unordered_map<char, int64_t> CARD_RANK_MAP = {
        {'A', 13},
        {'K', 12},
        {'Q', 11},
        {'J', 10},
        {'T', 9},
        {'9', 8},
        {'8', 7},
        {'7', 6},
        {'6', 5},
        {'5', 4},
        {'4', 3},
        {'3', 2},
        {'2', 1},
    };

    template <class T> bool card_rank_comparator(T s1, T s2)
    {
        int64_t s1_idx = 0, s2_idx = 0;

        while(s1_idx < s1.size() && s2_idx < s2.size()) {
            if(CARD_RANK_MAP[s1[s1_idx]] != CARD_RANK_MAP[s2[s2_idx]])
                break;
            s1_idx++;
            s2_idx++;
        }

        return CARD_RANK_MAP[s1[s1_idx]] < CARD_RANK_MAP[s2[s2_idx]];
    }

    unordered_map<char, int64_t> extract_card_label(string cards) {
        unordered_map<char, int64_t> card_label_map;

        for (auto card: cards) {
            card_label_map[card]++;
        }

        return card_label_map;
    }

    void split_card_by_type(vector<string> cards, unordered_map<string, vector<string>>& card_type_map) {

        for(auto card: cards) {
            unordered_map<char, int64_t> card_label_map = extract_card_label(card);
            string card_type = "high_card";
            bool is_three_kind = false;

            switch(card_label_map.size()) {
                case 1:
                    card_type = "five_kind";
                    break;
                case 2:
                    card_type = (card_label_map.at(card[0]) == 4 || card_label_map.at(card[0]) == 1) ? "four_kind" : "full_house";
                    break;
                case 3:
                    is_three_kind = false;
                    for(auto card_label: card_label_map) {
                        if(card_label.second == 3)
                            is_three_kind = true;
                    }
                    card_type = is_three_kind ? "three_kind" : "two_pair";
                    break;
                case 4:
                    card_type = "one_pair";
                    break;
                case 5:
                    card_type = "high_card";
                
            }
            card_type_map[card_type].push_back(card);
        }

    }

    int64_t total_winnings(unordered_map<string, int64_t> cards_bid_map) {
        int64_t sum = 0;
        
        vector<string> cards;
        unordered_map<string, vector<string>> card_type_map;

        for(auto cards_bid: cards_bid_map) {
            cards.push_back(cards_bid.first);
        }

        split_card_by_type(cards, card_type_map);

        int64_t rank = 1;
        for(auto type: CARD_TYPE_ORDER) {
            vector<string> cards = card_type_map[type];
            sort(cards.begin(), cards.end(), card_rank_comparator<string>);

            for (auto card: cards) {
                sum += rank * cards_bid_map[card];
                rank++;
            }
        } 
             
        return sum;
    }
}
