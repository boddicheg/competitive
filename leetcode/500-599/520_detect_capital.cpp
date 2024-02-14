#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // Check first letter
        char first = word.at(0);
        bool first_capital = false;
        int lower_or_upper = -1;

        for (size_t i = 0; i < word.size(); i++)
        {
            char letter = word.at(i);
            bool is_upper = isupper(letter);

            if (i == 0)
            {
                first_capital = is_upper;
                continue;
            }

            if (!first_capital)
            {
                if (is_upper) return false;
            }
            else
            {
                int l_or_up = is_upper ? 1 : 0;
                if (lower_or_upper == -1)
                    lower_or_upper = l_or_up;
                else if (lower_or_upper != l_or_up)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.detectCapitalUse("Qqweqwe") << std::endl;
    return 0;
}
