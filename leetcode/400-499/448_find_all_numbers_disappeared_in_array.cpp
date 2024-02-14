#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            int index = std::abs(nums.at(i)) - 1;
            nums.at(index) = nums.at(index) > 0 ? -nums.at(index) : nums.at(index);
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums.at(i) > 0)
                result.push_back(i + 1);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    s.findDisappearedNumbers(v);
    return 0;
}
