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
    std::vector<int> shuffle(const std::vector<int>& nums, int n)
    {
        std::vector<int> result(nums.size(), 0);
        for (size_t i = 0; i < n; i++)
        {
            result.at(i) = nums.at(i);
            result.at(i + 1) =  nums.at(i + n);
        }
        return result; 
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.shuffle({2,5,1,3,4,7}, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
