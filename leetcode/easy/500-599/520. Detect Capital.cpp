static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;

        bool all_cap = isupper(word.at(0)) && isupper(word.at(1));
        bool first_cap = isupper(word.at(0)) && islower(word.at(1));
        bool all_low = islower(word.at(0)) && islower(word.at(1));

        for (size_t i = 2; i < word.size(); i++)
        {
            if (all_cap && islower(word.at(i)))
                return false;

            if (first_cap && isupper(word.at(i)))
                return false;

            if (all_low && isupper(word.at(i)))
                return false;
        }

        return all_cap || first_cap || all_low;
    }
};