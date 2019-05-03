#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        std::vector<int> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int index = i;
            int greater = -1;
            do
            {
                if (index == nums.size() - 1)
                    index = 0;
                else
                    index ++;

                if (nums.at(i) < nums.at(index))
                {
                    greater = nums.at(index);
                    break;
                }
            }
            while (index != i);
            result.push_back(greater);
        }

        return result;
    }

    vector<int> nextGreaterElements2(vector<int> &nums)
    {
        // @ TODO: using stack
    }
};

int main(int argc, char const *argv[])
{

    // vector<int> nums = {1, 2, 1 };
    vector<int> nums = {1, 2, 3, 4, 3 };

    Solution s;
    auto result = s.nextGreaterElements(nums);

    for (const auto &e : result)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}