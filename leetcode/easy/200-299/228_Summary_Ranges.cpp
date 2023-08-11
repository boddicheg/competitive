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
    std::vector<std::string> summaryRanges(const std::vector<int>& nums)
    {
        if (nums.empty())
            return {};

        if (nums.size() == 1)
            return { std::to_string(nums.at(0)) };

        std::vector<std::string> r;
        // Due to some corner tests
        int64_t start = nums.at(0);
        for (size_t i = 1; i < nums.size(); i++)
        {
            int64_t current = nums.at(i);
            int64_t prev = nums.at(i - 1);
            if (current - prev > 1)
            {
                std::string s = std::to_string(start);
                if (prev != start)
                    s += "->" + std::to_string(prev);
                r.push_back(s);
                start = current;
            }

            if (i == nums.size() - 1)
            {
                if (start == current)
                    r.push_back(std::to_string(start));
                else
                    r.push_back(std::to_string(start) + "->" + std::to_string(current));
            }
        }
        return r;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.summaryRanges({ 0,2,3,4,6,8,9 });
    std::cout << "Result: " << result << std::endl;
    auto result1 = s.summaryRanges({ 0,1,2,4,5,7 });
    std::cout << "Result: " << result1 << std::endl;
    auto result2 = s.summaryRanges({ -1 });
    std::cout << "Result: " << result2 << std::endl;
    auto result3 = s.summaryRanges({ -2147483648,-2147483647,2147483647 });
    std::cout << "Result: " << result3 << std::endl;
    return 0;
}
