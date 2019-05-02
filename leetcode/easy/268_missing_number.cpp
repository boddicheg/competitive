#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int sum = (1 + nums.size()) / 2.0 * nums.size();
        sum -= std::accumulate(nums.begin(), nums.end(), 0);
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<int> v = { 9,6,4,2,3,5,7,0,1 };
    // std::vector<int> v = { 3, 0, 1 };
    std::vector<int> v = { 0, 1 };
    Solution s;
    int result = s.missingNumber(v);
    watch(result);
    return 0;
}
