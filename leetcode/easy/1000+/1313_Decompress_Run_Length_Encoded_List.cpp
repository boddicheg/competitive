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

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

class Solution {
public:
    std::vector<int> decompressRLElist(const std::vector<int>& nums)
    {
        std::vector<int> decompressed;
        for(int i = 0; i < nums.size(); i += 2)
            decompressed.insert(decompressed.end(), nums.at(i), nums.at(i + 1));
        return decompressed;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.decompressRLElist({1, 2, 3, 4});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
