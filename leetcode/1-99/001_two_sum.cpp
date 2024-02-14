/**
    https://leetcode.com/problems/two-sum/description/

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].


    Results:
    Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
    Memory Usage: 10.2 MB, less than 53.27% of C++ online submissions for Two Sum.
 */

#include <iostream>
#include <vector>
#include <map>

template <typename T>
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

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target)
    {
        std::map<int, int> pairs;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int first = nums.at(i);
            auto it = pairs.find(target - first);
            if (it != pairs.end() && it->second != i)
                return {(int)i, it->second};
            else
                pairs[first] = i;
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.twoSum({2, 7, 11, 15}, 9);
    print(result);
    return 0;
}
