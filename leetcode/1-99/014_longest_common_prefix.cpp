/**
    https://leetcode.com/problems/longest-common-prefix/
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:

    Input: ["flower","flow","flight"]
    Output: "fl"

    Example 2:

    Input: ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

    Note:
    All given inputs are in lowercase letters a-z.

    Results:
    Runtime: 8 ms, faster than 98.56% of C++ online submissions for Longest Common Prefix.
    Memory Usage: 8.8 MB, less than 99.63% of C++ online submissions for Longest Common Prefix.
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0) return {};
        int min_size = std::numeric_limits<int>::max();
        for (const auto &e : strs)
            min_size = std::min(min_size, (int)e.size());
        std::string prefix;

        for (int i = 0; i < min_size; i++)
        {
            char c = 0;
            for (const auto &e : strs)
            {
                if (c == 0)
                    c = e.at(i);
                else
                {
                    if (c != e.at(i))
                        return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::string> v = {"flower", "flow", "flight"};
    std::vector<std::string> v1 = {"cdog", "caracecar", "car"};
    std::vector<std::string> v2 = {};

    std::cout << s.longestCommonPrefix(v) << std::endl;
    std::cout << s.longestCommonPrefix(v1) << std::endl;
    std::cout << s.longestCommonPrefix(v2) << std::endl;

    return 0;
}
