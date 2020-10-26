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
    int balancedStringSplit(const std::string& s)
    {
        int result  = 0;
        int count_R = 0;
        int count_L = 0;
        for (auto &&i : s)
        {
            if (i == 'R')
                count_R++;

            if (i == 'L')
                count_L++;
            
            if (count_R == count_L &&
                count_R != 0 &&
                count_L != 0)
            {
                result++;
                count_R = 0;
                count_L = 0;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.balancedStringSplit("RLRRRLLRLL");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
