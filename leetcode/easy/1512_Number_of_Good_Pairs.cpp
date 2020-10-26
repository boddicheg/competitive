#include <iostream>
#include <vector>
#include <unordered_map>
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
    int numIdenticalPairs(const std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (auto &&i : nums)
            m[i] ++;

        int result = 0;

        for (auto &&i : m)
            result += (i.second * (i.second - 1)) / 2;

        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.numIdenticalPairs({1,1,1,1});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
