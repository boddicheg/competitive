#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

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

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {};
    auto result = s.template(..);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
