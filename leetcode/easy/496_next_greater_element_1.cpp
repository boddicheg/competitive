#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        std::vector<int> result;
        for (const auto &e : findNums)
        {
            size_t index = std::find(nums.begin(), nums.end(), e) - nums.begin();
            int greater = -1;
            for (size_t i = index; i < nums.size(); i++)
            {
                if (nums.at(i) > e)
                {
                    greater = nums.at(i);
                    index = i + 1;
                    break;
                }
            }
            result.push_back(greater);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> findNums = {2, 4};
    // vector<int> nums = {1,2,3,4};
    // vector<int> findNums = {4, 1, 2};
    // vector<int> nums = {1,3,4,2};
    vector<int> findNums = {4, 1, 2};
    vector<int> nums = {1,2,3,4};
    Solution s;
    auto result = s.nextGreaterElement(findNums, nums);

    for (const auto &e : result)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}