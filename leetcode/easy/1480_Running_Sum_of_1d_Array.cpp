#include <iostream>
#include <vector>
#include <set>
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
    std::vector<int> runningSum(const std::vector<int>& nums) {
        std::vector<int> result;
        int sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
            result.push_back(sum);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.runningSum({1,1,1,1,1});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
