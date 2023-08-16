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
    vector<int> findDuplicates(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            int index = std::abs(nums.at(i)) - 1;
            if ( nums.at(index) < 0)
                result.push_back(std::abs(nums.at(i)));
            else
                nums.at(index) = -nums.at(index);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> v = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};
    Solution s;
    auto res = s.findDuplicates(v);
    for(const auto& e: res)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
