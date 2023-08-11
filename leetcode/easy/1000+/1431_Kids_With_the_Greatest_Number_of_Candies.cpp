#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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
    std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies)
    {
        std::vector<bool> result(candies.size(), false);
        int max = *std::max_element(candies.begin(), candies.end());
        for (size_t i = 0; i < candies.size(); i++)
            result.at(i) = candies.at(i) + extraCandies >= max;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.kidsWithCandies({4,2,1,1,2}, 1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
