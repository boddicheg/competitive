#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
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

// Brute force - 5% runtime
class Solution0 {
public:
    std::vector<int> smallerNumbersThanCurrent(const std::vector<int>& nums)
    {
        std::vector<int> result(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                if (nums.at(i) > nums.at(j))
                    result.at(i) ++;
            }
            
        }
        return result;
    }
};

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(const std::vector<int>& nums)
    {
        std::vector<int> result(nums.size(), 0);
        std::map<int, int> m;
        std::unordered_map<int, int> proc;
        for (size_t i = 0; i < nums.size(); i++)
            m[nums.at(i)] ++;
        
        int idx = 0;
        for (auto &&i : m)
        {
            proc[i.first] = idx;
            idx += i.second;
        }

        for (size_t i = 0; i < nums.size(); i++)
            result.at(i) = proc.at(nums.at(i));
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.smallerNumbersThanCurrent({7,7,7,7});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
