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
    int smallestRangeI(const std::vector<int>& A, int K)
    {
        int min = A.at(0);
        int max = A.at(0);
        for (auto &&i : A)
        {
            min = std::min(min, i);
            max = std::max(max, i);
        }
        return std::max(0, max - K - min - K);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.smallestRangeI({1, 3, 6}, 3);
    auto result = s.smallestRangeI({0, 10}, 2);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
